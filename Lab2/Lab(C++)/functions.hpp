#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Структура для збереження конкретної інформації про абітурієнтів
struct Person{
    string full_name;
    string date_of_birth;
    string sex;
};

// Створення дати про абітурієнтів
vector<Person> Create_Person_Base();

// Створення бінарного файлу та запис дати, зчитування
void Write_File(const string& name_of_file, vector<Person> content);
void Read_File(const string& name_of_file);

// Зміна контенту
vector<int> Birth_Transform(string date_of_birth);
vector<Person> Modify_Data(vector<Person> content);