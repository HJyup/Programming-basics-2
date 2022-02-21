#include "functions.h"

int main(){
    // Название файлов
    string NameOfInput= "input.txt";
    string NameOfOutput = "output.txt";

    // Создание переменных
    vector<string> newText;
    vector <string> text;

    // Обработка input.txt
    text = generateContent();
    writeFile(NameOfInput, text);
    readFile(NameOfInput);

    // Создание нового контента
    newText = createNewContent(text);

    // Обработка output.txt
    writeFile(NameOfOutput, newText);
    readFile(NameOfOutput);
}