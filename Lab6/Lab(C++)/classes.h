using namespace std;

// Create a class that represent value of tree
class Node {
    int number;

    Node *left;
    Node *right;
public:
    // Constructor
    explicit Node(int number);

    Node();

    // Getters and setter to values
    int getNumber();

    void setNumber(int newNumber);

    void setLeft(Node *newLeft);

    void setRight(Node *newRight);

    Node *getLeft();

    Node *getRight();

    //Destructor
    ~Node();

};

class Tree {
    int positiveCount = 0, negativeCount = 0;

    // Counts positive and negative numbers
    void countPosAndNegValues(Node *node);

public:
    // Print positive and negative numbers in tree
    void printPosAndNegValues(Node *root);

    //  Insert Value to Tree
    static Node *insertValue(Node *root, int number);

    // Print tree
    static void print(const std::string &prefix, Node *root, bool isLeft);
};