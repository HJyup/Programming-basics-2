#include "classes.h"

int main() {

    // Створення змінних
    vector<ThreeDimensionalVector> content;
    vector<double> vector_length;

    // Створення массиву з об'єктами классу
    content = create_base_with_vectors();
    output_vector_base(content);

    // Визначення довжини
    vector_length = set_vector_length(content);
    output_vector_length(vector_length);

    //Отримання найбільшої довжини
    find_the_biggest_length(vector_length);

}
