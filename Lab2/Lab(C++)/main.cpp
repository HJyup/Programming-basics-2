#include "functions.hpp"

int main(){
    // Назва файлів
    string input = "input.bin";
    string output = "output.bin";

    // Ініціалізування змінних
    vector<Person> persons_base;
    vector<Person> modified_persons_base;

    // Створення інформації про абітурієнтів
    persons_base = Create_Person_Base();

    // Запис контенту та зчитування вхідного бінарного файлу
    Write_File(input, persons_base);
    Read_File(input);

    // Зміна інформації з абітурієнтами
    modified_persons_base = Modify_Data(persons_base);

    // Запис контенту та зчитування вихідного бінарного файлу
    Write_File(output, modified_persons_base);
    Read_File(output);
}