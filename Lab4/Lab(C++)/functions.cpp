#include "header.h"

// Виведення значень векторів
void outputVectors(booleanVector Vector1, booleanVector Vector2) {
    cout << "\nValues of boolean vector" << endl;
    cout << "Vector: " << Vector1.getValue() << " " << Vector1.getSize() << endl;
    cout << "Vector: " << Vector2.getValue() << " " << Vector2.getSize() << endl;
}

void outputVectors(booleanVector Vector1) {
    cout << "Vector: " << Vector1.getValue() << " " << Vector1.getSize() << endl;
}

// Виведення ваги кожного вектора
void outputWeights(booleanVector Vector1, booleanVector Vector2) {
    cout << "\nWeight of each boolean vector" << endl;
    cout << "Vector: " << Vector1.vectorWeight() << endl;
    cout << "Vector: " << Vector2.vectorWeight() << endl;
}

void outputWeights(booleanVector Vector1){
    cout << "Vector: " << Vector1.vectorWeight() << endl;

}
