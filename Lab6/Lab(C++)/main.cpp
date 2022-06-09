#include "header.h"

int main() {
    // Variables
    Node *root = new Node;
    Tree myTree;

    // Enter numbers to tree
    InsertValue(root, myTree);

    // Print tree and positive, negative count values
    myTree.print("", root, false);
    myTree.printPosAndNegValues(root);

    // Delete Root pointer
    delete root;
}