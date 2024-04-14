#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <unistd.h>

template<typename T>
class BinarySearchTree;

template<typename T>
std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& tree);

template<typename T>
concept Printable = requires(T t) {
    std::cout << t;
};

/* BINARY SEARCH TREE */

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };
    std::shared_ptr<Node> root;
public:
    class Iterator;
    class ImagePrinter;

    BinarySearchTree() = default;
    BinarySearchTree(const BinarySearchTree<T>& tree);
    BinarySearchTree(BinarySearchTree<T>&& tree) = default;
    BinarySearchTree(std::initializer_list<T> lst);
    ~BinarySearchTree() = default;

    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& tree);
    BinarySearchTree<T>& operator=(BinarySearchTree<T>&& tree) = default;

    Iterator begin() const;
    Iterator end() const;

    friend std::ostream& operator<< <T>(std::ostream& os, const BinarySearchTree<T>& tree);

    int length() const;

    bool exist(const T& elem) const;

    void add(const T& elem);
    void remove(const T& elem);

    T min() const;
    T max() const;

    std::list<T> to_list() const;
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
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree)
{
    for (const auto& elem : tree)
        add(elem);
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> lst)
{
    for (const auto& elem : lst)
        add(elem);
}

template<typename T>
BinarySearchTree<T>&
BinarySearchTree<T>::operator=(const BinarySearchTree<T>& tree) {
    for (const auto &elem: tree)
        add(elem);
}

template<typename T>
typename BinarySearchTree<T>::Iterator
BinarySearchTree<T>::begin() const
{
    return Iterator{ *this };
}

template<typename T>
typename BinarySearchTree<T>::Iterator
BinarySearchTree<T>::end() const
{
    return Iterator{ nullptr };
}

template<typename T>
int BinarySearchTree<T>::length() const
{
    int count = 0;

    for (const auto& elem : *this)
        count++;

    return count;
}

template<typename T>
bool BinarySearchTree<T>::exist(const T& elem) const
{
    return getElem(elem, root) != nullptr;
}

template<typename T>
void BinarySearchTree<T>::add(const T& elem)
{
    insert(elem, root);
}

template<typename T>
void BinarySearchTree<T>::remove(const T& elem)
{
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

template<typename T>
T BinarySearchTree<T>::min() const
{
    return Iterator::downLeft(root)->value;
}

template<typename T>
T BinarySearchTree<T>::max() const
{
    return Iterator::downRight(root)->value;
}

template<typename T>
std::list<T> BinarySearchTree<T>::to_list() const
{
    std::list<T> lst;

    for (const auto& elem : *this)
        lst.push_back(elem);

    return lst;
}


/* BST ITERATOR (inorder traversal) */


template<typename T>
class BinarySearchTree<T>::Iterator :
        public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    std::shared_ptr<Node> current;
public:
    friend class BinarySearchTree;

    explicit Iterator(const BinarySearchTree<T>& tree);

    Iterator(const Iterator& rhs) = default;
    Iterator(Iterator&& rhs) = default;

    // inorder successor
    Iterator next() const;
    // inorder predecessor
    Iterator prev() const;

    T value() const;

    bool is_end() const;

    Iterator& operator=(const Iterator& rhs) = default;
    Iterator& operator=(Iterator&& rhs) = default;

    Iterator& operator++();
    Iterator& operator--();

    const T& operator*() const;

    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;
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
BinarySearchTree<T>::Iterator::Iterator(const BinarySearchTree<T>& tree)
{
    current = downLeft(tree.root);
}

template<typename T>
typename BinarySearchTree<T>::Iterator
BinarySearchTree<T>::Iterator::next() const
{
    if (!current) return *this;

    std::shared_ptr<Node> cur = current;

    cur = cur->right ? downLeft(cur->right) : upRight(cur);

    return Iterator{ cur };
}

template<typename T>
typename BinarySearchTree<T>::Iterator
BinarySearchTree<T>::Iterator::prev() const
{
    if (!current) return *this;

    std::shared_ptr<Node> cur = current;

    cur = cur->left ? downRight(cur->left) : upLeft(cur);

    return Iterator{ cur };
}

template<typename T>
T BinarySearchTree<T>::Iterator::value() const
{
    return current->value;
}

template<typename T>
bool BinarySearchTree<T>::Iterator::is_end() const
{
    return current == nullptr;
}

template<typename T>
typename BinarySearchTree<T>::Iterator&
BinarySearchTree<T>::Iterator::operator++()
{
    *this = next();
    return *this;
}

template<typename T>
typename BinarySearchTree<T>::Iterator&
BinarySearchTree<T>::Iterator::operator--()
{
    *this = prev();
    return *this;
}

template<typename T>
const T& BinarySearchTree<T>::Iterator::operator*() const
{
    return current->value;
}

template<typename T>
bool BinarySearchTree<T>::Iterator::operator==(const Iterator& rhs) const
{
    return current == rhs.current;
}

template<typename T>
bool BinarySearchTree<T>::Iterator::operator!=(const Iterator& rhs) const
{
    return !(*this == rhs);
}


/* BST IMAGE PRINTER (using dot utility from Graphviz) */


template<typename T>
class BinarySearchTree<T>::ImagePrinter {
private:
    const BinarySearchTree<T>& tree;
    std::string fname;
    std::ofstream os;
public:
    ImagePrinter(const BinarySearchTree<T>& tree, const std::string& fname);

    void printImage();
private:
    void numberNodes(const std::shared_ptr<Node>& node, int n) {
        if (!node) return;

        os << n << " [shape=\"circle\"label=\"" << node->value << "\"];\n";

        numberNodes(node->left, 2*n + 1);
        numberNodes(node->right, 2*n + 2);

        if (node->left)
            os << n << "->" << 2*n + 1 << ";\n";

        if (node->right)
            os << n << "->" << 2*n + 2 << ";\n";
    }
};

template<typename T>
BinarySearchTree<T>::ImagePrinter::ImagePrinter(
        const BinarySearchTree<T>& tree,
        const std::string& fname)
    : tree(tree), fname(fname)
{
    os.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    os.open(fname);
}

template<typename T>
void BinarySearchTree<T>::ImagePrinter::printImage()
{
    os << "digraph G {\n";
    numberNodes(tree.root, 0);
    os << "}\n";

    if (fork() == 0) {
        size_t dotPos = fname.find('.');
        std::string oname = dotPos != std::string::npos ?
            fname.substr(0, dotPos) + ".png" : fname;

        execlp("dot", "dot", "-Tpng", ("-o" + oname).c_str(), fname.c_str(), NULL);
        perror("Error in execlp. Run dot manually: ");
    }
}

template<Printable T>
std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& tree)
{
    for (const auto& elem : tree)
        std::cout << elem << "\n";

    return os;
}

#endif // BINARYSEARCHTREE_H

