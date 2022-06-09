#include "header.h"

void InsertValue(Node *root, Tree tree) {
    int count, value;
    while (true) {
        cout << "How many numbers do u wanna add? -> ";
        cin >> count;
        cin.ignore();
        if (count > 0) {
            for (int i = 0; i < count; ++i) {
                cout << "Enter ur value -> ";
                cin >> value;
                if (root->getNumber() == 0)
                    root->setNumber(value);
                else
                    tree.insertValue(root, value);
            }
            break;
        }
        else{
            cout << "Try again..." << endl;
        }
    }
}