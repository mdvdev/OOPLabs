#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> tree = { 7, 3, 21, 30, 24 };

    std::cout << tree << "\n";

    if (tree.exist(1))
        std::cout << "exist\n\n";
    else
        std::cout << "not exist\n\n";

    tree.add(1);

    std::cout << tree << "\n";

    std::cout << "length == " << tree.length() << "\n\n";

    tree.remove(1);
    tree.remove(100);
    tree.remove(24);

    std::cout << tree << "\n";

    std::cout << "min == " << tree.min() <<"\nmax == " << tree.max() << "\n\n";

    std::list<int> lst = tree.to_list();

    std::cout << "List first elem == " <<  *lst.begin() << "\n\n";

    BinarySearchTree<int> tree1 = { 30, 2, -9, 0, 53, 100, 50 };

    std::string fname = "image.dot";

    try {
        BinarySearchTree<int>::ImagePrinter printer(tree1, fname);
        printer.printImage();
    } catch (const std::ios_base::failure& fail) {
        std::cerr << fail.what() << "\n";
    }
}
