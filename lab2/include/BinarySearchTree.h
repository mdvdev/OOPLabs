#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <iterator>
#include <list>
#include <memory>

template<typename T>
class BinarySearchTree;

template<typename T>
std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& tree);

template<typename T>
class BinarySearchTree {
    struct Node {
        T value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };
    std::shared_ptr<Node> root;
public:
    class Iterator;

    BinarySearchTree() = default;

    BinarySearchTree(const BinarySearchTree<T>& tree) {
        for (const auto& elem : tree)
            add(elem);
    }

    BinarySearchTree(BinarySearchTree<T>&& tree) = default;

    BinarySearchTree(std::initializer_list<T> lst) {
        for (const auto& elem : lst)
            add(elem);
    }

    ~BinarySearchTree() = default;

    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& tree) {
        for (const auto& elem : tree)
            add(elem);
    }

    BinarySearchTree<T>& operator=(BinarySearchTree<T>&& tree) = default;

    Iterator begin() const {
        return Iterator{ *this };
    }

    Iterator end() const {
        return Iterator{ nullptr };
    }

    friend std::ostream& operator<< <T>(std::ostream& os, const BinarySearchTree<T>& tree);

    int length() const {
        int count = 0;

        for (const auto& elem : *this)
            count++;

        return count;
    }

    bool exist(const T& elem) const {
        return getElem(elem, root) != nullptr;
    }

    void add(const T& elem) {
        insert(elem, root);
    }

    void remove(const T& elem) {
        std::shared_ptr<Node> deleted = getElem(elem, root);
        if (!deleted) return;

        if (!deleted->left && !deleted->right) {
            if (deleted == root)
                root = nullptr;
            else if (deleted == deleted->parent.lock()->left)
                deleted->parent.lock()->left = nullptr;
            else
                deleted->parent.lock()->right = nullptr;
        } else if (deleted->left && deleted->right) {
            Iterator iter(deleted); ++iter;
            std::shared_ptr<Node> successor = std::move(iter.current);

            T valueCopy = successor->value;

            remove(successor->value);

            deleted->value = std::move(valueCopy);
        } else {
            std::shared_ptr<Node> child = deleted->left ? deleted->left : deleted->right;

            if (deleted == root)
                root = child;
            else if (deleted == deleted->parent.lock()->left)
                deleted->parent.lock()->left = child;
            else
                deleted->parent.lock()->right = child;
        }
    }

    T min() const {
        return Iterator::downLeft(root)->value;
    }

    T max() const {
        return Iterator::downRight(root)->value;
    }

    std::list<T> to_list() const {
        std::list<T> lst;

        for (const auto& elem : *this)
            lst.push_back(elem);

        return lst;
    }
private:
    static void insert(const T& elem, std::shared_ptr<Node>& cur) {
        if (!cur)
            cur = std::make_shared<Node>(Node{
                .value = elem, .parent = std::weak_ptr<Node>(),
                .left = nullptr, .right = nullptr
            });

        if (elem == cur->value) return;

        if (elem > cur->value)
            if (!cur->right) {
                cur->right = std::make_shared<Node>(Node{
                        .value = elem, .parent = cur,
                        .left = nullptr, .right = nullptr
                });
                return;
            } else {
                insert(elem, cur->right);
            }
        else
            if (!cur->left) {
                cur->left = std::make_shared<Node>(Node{
                        .value = elem, .parent = cur,
                        .left = nullptr, .right = nullptr
                });
                return;
            } else {
                insert(elem, cur->left);
            }
    }

    static std::shared_ptr<Node> getElem(const T& elem, const std::shared_ptr<Node>& cur) {
        if (!cur)
            return nullptr;
        if (elem == cur->value)
            return cur;
        else if (elem < cur->value)
            return getElem(elem, cur->left);
        else
            return getElem(elem, cur->right);
    }
};

template<typename T>
class BinarySearchTree<T>::Iterator :
        public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    std::shared_ptr<Node> current;
public:
    friend class BinarySearchTree;

    explicit Iterator(const BinarySearchTree<T>& tree)  {
        current = downLeft(tree.root);
    }

    Iterator(const Iterator& rhs) = default;
    Iterator(Iterator&& rhs) = default;

    // inorder successor
    Iterator next() const {
        if (!current) return *this;

        std::shared_ptr<Node> cur = current;

        cur = cur->right ? downLeft(cur->right) : upRight(cur);

        return Iterator{ cur };
    }

    // inorder predecessor
    Iterator prev() const {
        if (!current) return *this;

        std::shared_ptr<Node> cur = current;

        cur = cur->left ? downRight(cur->left) : upLeft(cur);

        return Iterator{ cur };
    }

    T value() const {
        return current->value;
    }

    bool is_end() const {
        return current == nullptr;
    }

    Iterator& operator=(const Iterator& rhs) = default;
    Iterator& operator=(Iterator&& rhs) = default;

    Iterator& operator++() {
        *this = next();
        return *this;
    }

    Iterator& operator--() {
        *this = prev();
        return *this;
    }

    const T& operator*() const {
        return current->value;
    }

    bool operator==(const Iterator& rhs) const {
        return current == rhs.current;
    }

    bool operator!=(const Iterator& rhs) const {
        return !(*this == rhs);
    }
private:
    explicit Iterator(const std::shared_ptr<Node>& cur) : current(cur) {}

    static std::shared_ptr<Node> downLeft(std::shared_ptr<Node> cur) {
        if (!cur) return nullptr;

        while (cur->left)
            cur = cur->left;

        return cur;
    }

    static std::shared_ptr<Node> downRight(std::shared_ptr<Node> cur) {
        if (!cur) return nullptr;

        while (cur->right)
            cur = cur->right;

        return cur;
    }

    static std::shared_ptr<Node> upRight(std::shared_ptr<Node> cur) {
        if (!cur) return nullptr;

        while (cur->parent.lock() && cur == cur->parent.lock()->right)
            cur = cur->parent.lock();

        return cur->parent.lock();
    }

    static std::shared_ptr<Node> upLeft(std::shared_ptr<Node> cur) {
        if (!cur) return nullptr;

        while (cur->parent.lock() && cur == cur->parent.lock()->left)
            cur = cur->parent.lock();

        return cur->parent.lock();
    }
};

template<typename T>
concept Printable = requires(T t) {
    std::cout << t;
};

template<Printable T>
std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& tree)
{
    for (const auto& elem : tree)
        std::cout << elem << "\n";

    return os;
}

#endif // BINARYSEARCHTREE_H

