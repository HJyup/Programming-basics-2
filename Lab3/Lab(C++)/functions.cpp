#include "classes.h"

// Функцій для створення, обробки массиву об'єктів

// Створення вектора з об'єктами класса тривимірного вектора
vector<ThreeDimensionalVector> create_base_with_vectors() {
    vector<ThreeDimensionalVector> content_with_vectors;
    int count, x_values, y_values, z_values;

    cout << "How many vectors do u wanna create? ";
    cin >> count;
    for (int i = 0; i < count; ++i) {
        cout << to_string(i + 1) + "th Vector: " << endl;

        cout << "Enter x -> ";
        cin >> x_values;
        cout << "Enter y -> ";
        cin >> y_values;
        cout << "Enter z -> ";
        cin >> z_values;

        ThreeDimensionalVector Vector(x_values, y_values, z_values);
        content_with_vectors.push_back(Vector);
    }
    cout << endl;

    return content_with_vectors;
}

// Виведення вектора зі значеннями об'єктів классу
void output_vector_base(const vector<ThreeDimensionalVector> &content_with_vectors) {

    for (int i = 0; i < content_with_vectors.size(); ++i) {
        cout << to_string(i + 1) + "th Vector: ";
        content_with_vectors[i].get_values();
    }

}

// Створення вектора з довжиною кожного об'єкта класса тривимірного вектора
vector<double> set_vector_length(const vector<ThreeDimensionalVector> &content_with_vectors) {
    vector<double> length_vector;

    length_vector.reserve(content_with_vectors.size());
    for (auto &content_with_vector: content_with_vectors) {
        length_vector.push_back(content_with_vector.get_length());
    }

    return length_vector;
}

// Визначення найбільшого значення довжини
void find_the_biggest_length(vector<double> content_with_length) {
    double max = content_with_length[0];
    int index;

    for (int i = 0; i < content_with_length.size(); ++i) {
        if (content_with_length[i] > max) {
            index = i;
            max = content_with_length[i];
        }
    }

    cout << "\nThe biggest length has " << to_string(index+1) << "th Vector with value: " << max << endl;

}

// Виведення значень довжини
void output_vector_length(const vector<double> &content_with_length) {

    cout << "\nVectors length: " << endl;
    for (int i = 0; i < content_with_length.size(); ++i) {
        cout << to_string(i + 1) + "th Vector: ";
        cout << content_with_length[i] << endl;
    }

}