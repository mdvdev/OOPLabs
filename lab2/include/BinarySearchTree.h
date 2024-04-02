#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iterator>
#include <cstddef>

template<typename T>
class BinarySearchTree {
    struct Node {
        T value;
        Node* left;
        Node* right;
    };
    Node* root;
public:
    struct Iterator {
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type 		= T;
        using difference_type 	= std::ptrdiff_t;
        using pointer 			= T*;
        using reference 		= T&;
        using const_reference 	= const T&;

        explicit Iterator(const BinarySearchTree<T>& tree);

        Iterator next();
        value_type value() const;
        bool is_end() const;

        Iterator& operator++();
        const_reference operator*() const;
        bool operator==(const Iterator& b) const;
        bool operator!=(const Iterator& b) const;
    private:
        Node* current;
    };

    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T>& tree);
    BinarySearchTree(BinarySearchTree<T>&& tree);
    explicit BinarySearchTree(std::initializer_list<T> lst);

    ~BinarySearchTree();

    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& tree);
    BinarySearchTree<T>& operator=(BinarySearchTree<T>&& tree);

    Iterator begin() const;
    Iterator end() const;

    friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& tree);

    int length() const;

    bool exist(const T& elem) const;

    void add(const T& elem);
    void remove(const T& elem);

    T min() const;
    T max() const;
private:

};

#endif // BINARYSEARCHTREE_H

