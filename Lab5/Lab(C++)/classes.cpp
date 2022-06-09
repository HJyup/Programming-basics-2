#include "header.h"

// Methods that represent TTriad
TTriad::TTriad(int num1, int num2, int num3) {
    numbers.push_back(num1);
    numbers.push_back(num2);
    numbers.push_back(num3);
}

// Getters
vector<int> TTriad::get_values() {
    return numbers;
}

// Setters
void TTriad::set_values(int newNum1, int newNum2, int newNum3) {
    numbers[0] = newNum1;
    numbers[1] = newNum2;
    numbers[2] = newNum3;
    format_numbers();
}

// Return string representation
string TTriad::string_numbers() {
    return to_string(numbers[0]) + " " + to_string(numbers[1]) + " " + to_string(numbers[2]);
}

// Check index of element
void TTriad::checkIndex(int &index) {
    if (index < 1 or index > 3)
        index = 3;
}

// Add number to value
void TTriad::addValue(int value, int index) {
    checkIndex(index);
    numbers[index - 1] += value;
    format_numbers();
}

// Min number to value
void TTriad::minValue(int value, int index) {
    checkIndex(index);
    numbers[index - 1] -= value;
    format_numbers();
}

// Methods that represent TTime
TTime::TTime(int seconds, int minutes, int hours) : TTriad(seconds, minutes, hours) {
    format_numbers();
}

void TTime::format_numbers() {
    for (int i = 0; i < 2; ++i) {
        if (numbers[i] >= 60) {
            numbers[i + 1] += 1;
            numbers[i] -= 60;
        } else if (numbers[i] < 0) {
            numbers[i + 1] -= 1;
            numbers[i] += 60;
        }
    }
    if (0 > numbers[2] or numbers[2] > 24)
        numbers[2] = 0;
}

string TTime::string_numbers() {
    vector<string> numbersString;
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] < 10)
            numbersString.push_back('0' + to_string(numbers[i]));
        else
            numbersString.push_back(to_string(numbers[i]));
    }
    return numbersString[0] + ":" + numbersString[1] + ":" + numbersString[2];
}

// Methods that represent TDate
TDate::TDate(int days, int months, int years) : TTriad(days, months, years) {
    format_numbers();
}

// Format another numbers
void TDate::format_numbers() {
    checkDays();

    if (numbers[1] > 12) {
        numbers[2] += 1;
        numbers[1] -= 12;
    } else if (numbers[1] < 0) {
        numbers[2] -= 1;
        numbers[1] += 12;
    }
}

string TDate::string_numbers() {
    vector<string> numbersString;
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] < 10)
            numbersString.push_back('0' + to_string(numbers[i]));
        else
            numbersString.push_back(to_string(numbers[i]));
    }
    return numbersString[0] + "." + numbersString[1] + "." + numbersString[2];
}

// Check year and days representation
void TDate::checkDays() {
    int monthMaxValue;
    if (isLeapYear(numbers[2]))
        monthMaxValue = 29;
    else
        monthMaxValue = 28 + (numbers[1] + numbers[1] / 8) % 2 + 2 %
                                                                 numbers[1] + 1 / numbers[1] * 2;
    if (numbers[0] > monthMaxValue) {
        numbers[1] += 1;
        numbers[0] -= monthMaxValue;
    } else if (numbers[0] < 0) {
        numbers[1] -= 1;
        numbers[0] += monthMaxValue;
    }

}

// Check is year is leap
bool TDate::isLeapYear(int yrs) {
    int year = yrs + 1;
    return ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0);
}