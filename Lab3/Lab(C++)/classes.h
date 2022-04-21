#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Ініціалізація класса тривимірного вектора

class ThreeDimensionalVector {
    int x, y, z;

    void set_length();

    double length{};
public:
    ThreeDimensionalVector(int, int, int);

    void get_values() const;


    double get_length() const;
};

// Прототипи функцій для створення, обробки массиву об'єктів

vector<ThreeDimensionalVector> create_base_with_vectors();

void output_vector_base(const vector<ThreeDimensionalVector> &content_with_vectors);

void output_vector_length(const vector<double> &content_with_length);

vector<double> set_vector_length(const vector<ThreeDimensionalVector>& content_with_vectors);

void find_the_biggest_length(vector<double> content_with_length);