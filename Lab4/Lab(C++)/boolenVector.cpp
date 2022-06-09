#include <utility>

#include "header.h"

// Конструктори класу
booleanVector::booleanVector(int newSize, string newValue) : size(newSize), value(move(newValue)) {
    formatAttributes();
}

booleanVector::booleanVector(string newValue) : size(newValue.size()), value(move(newValue)) {}

booleanVector::booleanVector() = default;

// Форматування введення атрибутів для класу
void booleanVector::formatAttributes() {
    if (size < value.size())
        value = value.substr(0, size);
    else if (size > value.size()) {
        int count = size - value.size();
        for (int i = 0; i < count; ++i)
            value += "0";
    }
}

// Гетер для значення булевого вектору
string booleanVector::getValue() {
    return value;
}

// Геттер для визначення розміру вектору
int booleanVector::getSize() const {
    return size;
}

// Cеттер для значення булевого вектору
void booleanVector::setValue(string newValue) {
    value = move(newValue);
    formatAttributes();
}

// Сеттер для визначення розміру вектору
void booleanVector::setSize(int newSize) {
    size = newSize;
    formatAttributes();
}

// Визначення ваги вектора
int booleanVector::vectorWeight() {
    string temp_value;
    int weight = 0;
    for (int i = 0; i < size; ++i) {
        temp_value = value[i];
        weight += stoi(temp_value);
    }

    return weight;
}

// Перевантаження оператора заперечення ~
booleanVector *booleanVector::operator~() {
    string newValue;
    for (int i = 0; i < size; ++i) {
        if (value[i] == '1')
            newValue += '0';
        else
            newValue += '1';
    }

    value = newValue;
    return this;
}

// Перевантаження оператора кон'юнкції
booleanVector booleanVector::operator&(const booleanVector &Obj) {
    string newValue;
    string objValue = Obj.value;
    if (size != Obj.size) {
        exit(1);
    } else {
        for (int i = 0; i < size; ++i) {
            if (value[i] == objValue[i] and value[i] == '1') {
                newValue += '1';
            } else
                newValue += '0';
        }
    }

    booleanVector temp(newValue);
    return temp;
}