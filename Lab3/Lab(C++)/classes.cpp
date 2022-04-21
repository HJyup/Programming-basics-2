//
// Created by Danya Butov on 17.04.2022.
//

#include "classes.h"

// Методи класса тривимірного вектора

// Конструктор класса
ThreeDimensionalVector::ThreeDimensionalVector(int x_value, int y_value, int z_value) {
    x = x_value;
    y = y_value;
    z = z_value;
    set_length();
}

// Отримати координатори вектора
void ThreeDimensionalVector::get_values() const {
    cout << "x= " << x << "; y= " << y << "; z= " << z << ";" << endl;
}

// Встановити значення довжини вектора
void ThreeDimensionalVector::set_length() {
    length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

// Отримати значення довжини
double ThreeDimensionalVector::get_length() const {
    return length;
}