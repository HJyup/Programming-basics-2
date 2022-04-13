#include "functions.hpp"

// Створення дати про абітурієнтів
vector<Person> Create_Person_Base(){
    int count;
    vector<Person> data;
    string name;

    cout << "How many persons do u wanna add? "; cin >> count;
    cin.ignore();

    for (int i = 0; i < count; ++i) {
        struct Person personality;

        cout << "Enter full name of person: "; getline(cin, personality.full_name);
        cout << "Enter Date of Birth of person: "; getline(cin, personality.date_of_birth);
        cout << "Enter Sex of ur person: "; getline(cin, personality.sex);

        data.push_back(personality);
    }

    return data;
}

// Створення бінарного файлу та запис дати
void Write_File(const string& name_of_file, vector<Person> content){
    string data_information;
    ofstream out(name_of_file, ios::binary);

    for (int i = 0; i < content.size(); ++i) {
        data_information = content[i].full_name + "," + content[i].date_of_birth + "," + content[i].sex;
        out << data_information;
        if (i != content.size()-1)
            out << '\n';
    }

    out.close();
}

// Зчитування бінарного файлу
void Read_File(const string& name_of_file){
    string line;
    cout << '\n' << name_of_file << " file:" << endl;

    ifstream in(name_of_file, ios::binary);
    while(getline(in, line))
        cout << line << endl;
}

// Зміна бази даних з абітурієнтами
vector<Person> Modify_Data(vector<Person> content){
    vector<Person> modify_content;
    vector<int> current_time = {12, 04, 2022};
    vector<int> date_of_birth;

    int year;
    cout << "\nPersons that older than 35 yd: " << endl;
    for (int i = 0; i < content.size(); ++i) {
        date_of_birth = Birth_Transform(content[i].date_of_birth);
        year = current_time[2] - date_of_birth[2];

        if (current_time[1] < date_of_birth[1] or
        (current_time[1] == date_of_birth[1] and current_time[0] < date_of_birth[0]))
            year -= 1;

        if (year >= 18 and year <= 27 and content[i].sex == "чоловік")
            modify_content.push_back(content[i]);
        else if (year > 35)
            cout << content[i].full_name << " " << content[i].date_of_birth << " " << content[i].sex << endl;
    }

    return modify_content;
}

// Переведення строки з датою народження в вектор з цілими числами
vector<int> Birth_Transform(string date_of_birth){
    vector<int> birth_int_person;
    int dot_position;

    for (int j = 0; j < 2; ++j) {
        dot_position = date_of_birth.find('.');
        birth_int_person.push_back(atoi(date_of_birth.substr(0, dot_position).c_str()));
        date_of_birth = date_of_birth.substr(dot_position+1);
    }

    birth_int_person.push_back(atoi(date_of_birth.c_str()));

    return birth_int_person;
}