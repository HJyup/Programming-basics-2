//
// Created by Danya Butov on 14.02.2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Генерация Контента для изначального файла
vector<string> generateContent();

// Перенос контента в файл
void writeFile(const string& NameOfFile, vector<string> content);

// Обработка файла (ввод-вывод)
void readFile(const string& NameOfFile);

// Создание Нового выходного контента
vector<string> createNewContent(vector<string> content);
string newContent(string content, int& comma, int& space, int& point);
string deleteWords(string content, int& wordsCount);
