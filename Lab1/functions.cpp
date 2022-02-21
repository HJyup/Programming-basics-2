//
// Created by Danya Butov on 14.02.2022.
//

#include "functions.h"

// Генерация контента
vector<string> generateContent(){
    vector<string> content;
    string stringLine;
    int endCode = 126;

    cout << "Enter content of ur file (use ~ and Enter):\n";
    while(int(stringLine[0]) != endCode){
        getline(cin, stringLine);
        content.push_back(stringLine);
    }
    content.pop_back();

    return content;
}

// Перенос контента в файл
void writeFile(const string& NameOfFile, vector<string> content){
    ofstream out;

    out.open(NameOfFile);
    for (int i = 0; i < content.size(); ++i) {
        out << content[i];
        if (i != content.size()-1)
            out << '\n';
    }
    out.close();
}

// Вывод файла
void readFile(const string& NameOfFile){
    ifstream in;
    string line;

    cout << "Your " + NameOfFile + " file has content:" << endl;
    in.open(NameOfFile);
    while(getline(in, line))
        cout << line << endl;
    in.close();

    cout << endl;
}

// Создание нового контента
vector<string> createNewContent(vector<string> content){
    vector <string> NewContent;
    string newString;

    string comma_count = "\nComma was deleted -> ";
    int comma = 0;
    string space_count = "Space was deleted -> ";
    int space = 0;
    string point_count = "Point was deleted -> ";
    int point = 0;
    string end_count = " times\n";
    string words_count = "Words were deleted -> ";
    int word = 0;

    for (int i = 0; i < content.size(); ++i) {
        newString = deleteWords(content[i], word);
        newString = newContent(newString, comma, space, point);
        NewContent.push_back(newString);
    }
    NewContent.push_back( "\n" + comma_count + to_string(comma) + end_count
            + space_count + to_string(space) + end_count +
            point_count + to_string(point) + end_count +
            words_count + to_string(word) + end_count);

    return NewContent;
}

// Удаление символов и подсчёт каждого
string newContent(string content, int& comma, int& space, int& point){
    string new_line = "";

    for (int i = 0; i <= content.size(); ++i) {
        if (content[i] == content[i+1]){
            if (content[i] == ',')
                comma++;
            else if (content[i] == '.')
                point++;
            else if (content[i] == ' ')
                space++;
            else
                new_line += content[i];
            }
        else
            new_line += content[i];
        }
    new_line = new_line.substr(0, new_line.size()-1);

    return new_line;
}

// Удаление односимвольного слова
string deleteWords(const string content, int& wordsCount){
    string FixedContent = "";
    for (int i = 0; i < content.size(); ++i) {
        if (content[i-1] == ' ' and content[i+1] == ' ' and content[i] != ' ')
            wordsCount++;
        else if (i == 0 and content[i+1] == ' ' and content[i] != ' ')
            wordsCount++;
        else if (i == content.size() and content[i-1] == ' ' and content[i] != ' ')
            wordsCount++;
        else
            FixedContent += content[i];
    }
    return FixedContent;
}