//
// Created by Nikita Antonenkov on 10.04.2024.
//

#ifndef LAB2_OUTPUTBINARYSEARCHTREE_H
#define LAB2_OUTPUTBINARYSEARCHTREE_H

#include <iostream>

template<typename T>
concept Printable = requires(T t) {
    std::cout << t;
};

template<typename T>
class BinarySearchTree;

template<Printable T>
std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& tree)
{
    for (const auto& elem : tree)
        std::cout << elem << "\n";

    return os;
}


#endif //LAB2_OUTPUTBINARYSEARCHTREE_H
