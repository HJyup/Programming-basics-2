#include "header.h"


// Methods that represent a class "Note"
//Constructor
Node::Node(int number) : number(number), right(nullptr), left(nullptr) {}

Node::Node() : number(0), right(nullptr), left(nullptr) {}

// Getters and Setters
int Node::getNumber() {
    return number;
}

void Node::setNumber(int newNumber) {
    number = newNumber;
}

void Node::setLeft(Node *newLeft) {
    left = newLeft;
}

void Node::setRight(Node *newRight) {
    right = newRight;
}

Node *Node::getLeft() {
    return left;
}

Node *Node::getRight() {
    return right;
}

// Destructor
Node::~Node() {
    delete left;
    delete right;
}

// Methods that represent a class "Tree"
// Insert value
Node *Tree::insertValue(Node *root, int number) {
    if (root == nullptr) {
        Node *pointer = new Node(number);
        return pointer;
    }
    if (number > root->getNumber()) {
        root->setRight(insertValue(root->getRight(), number));
    } else {
        root->setLeft(insertValue(root->getLeft(), number));
    }

    return root;
}

// Print tree
void Tree::print(const std::string &prefix, Node *root, bool isLeft) {
    if (root != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << '(' << root->getNumber() << ')' << std::endl;

        // enter the next tree level - left and right branch
        print(prefix + (isLeft ? "│   " : "    "), root->getLeft(), true);
        print(prefix + (isLeft ? "│   " : "    "), root->getRight(), false);
    }
}

// Print positive and negative values
void Tree::printPosAndNegValues(Node *node) {
    cout << "\nTree Positive and Negative values counts: " << endl;
    countPosAndNegValues(node);
    cout << "Positive values -> " << positiveCount << endl;
    cout << "Negative values -> " << negativeCount << endl;
}

// Count positive and negative values
void Tree::countPosAndNegValues(Node *root) {
    if (root == nullptr)
        return;

    countPosAndNegValues(root->getLeft());

    if (root->getNumber() >= 0)
        positiveCount++;
    else
        negativeCount++;

    countPosAndNegValues(root->getRight());
}