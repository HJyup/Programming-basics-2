#include "header.h"

int main() {
    // Ініціалізація векторів A та B через різні конструктори
    booleanVector A(6, "100101");
    booleanVector B("010110");

    // Виведення значень векторів
    outputVectors(A, B);

    // Виведення ваги кожного вектора
    outputWeights(A, B);

    // Доповнення вектора A до універсальної множини
    cout << "\nChange A boolean vector" << endl;
    ~A;
    outputVectors(A);

    // Створення вектора C за кон'юнкцією векторів A та В
    cout << "\nCreating a new boolean vector C" << endl;
    booleanVector C;
    C = A & B;
    outputVectors(C);
    outputWeights(C);
}