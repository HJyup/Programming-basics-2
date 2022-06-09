#include "header.h"
#include <ctime>

// Check if object is related to class
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

// Create vector with objects
vector<TTriad *> createVectorWithObjects() {
    vector<TTriad *> vectorWithObjects;
    srand(time(nullptr));

    int timeCount, dateCount;
    int value1, value2, value3;
    cout << "How many time objects do u wanna create? ";
    cin >> timeCount;
    cout << "How many date objects do u wanna create? ";
    cin >> dateCount;
    for (int i = 0; i < timeCount; ++i) {
        value1 = rand() % 60 + 1;
        value2 = rand() % 60 + 1;
        value3 = rand() % 24 + 1;

        TTime *object = new TTime(value1, value2, value3);
        vectorWithObjects.push_back(object);
    }
    for (int i = 0; i < dateCount; ++i) {
        value1 = rand() % 31 + 1;
        value2 = rand() % 12 + 1;
        value3 = rand() % 2022 + 1;

        TDate *object = new TDate(value1, value2, value3);
        vectorWithObjects.push_back(object);
    }
    return vectorWithObjects;
}

// Output vector
void outputObjects(vector<TTriad *> objects) {
    for (int i = 0; i < objects.size(); ++i) {
        cout << objects[i]->string_numbers() << endl;
    }
}

// Find dates objects that can be represented like a time
vector<TTriad *> findCorrectDatesAndTime(vector<TTriad *> objects) {
    vector<int> values;
    vector<TTriad *> correctObjects;
    for (int i = 0; i < objects.size(); ++i) {
        if (instanceof<TDate>(objects[i])) {
            values = objects[i]->get_values();
            if (values[0] < 60 and values[1] < 60 and values[2] < 24)
                correctObjects.push_back(objects[i]);
        }
    }

    return correctObjects;
}

// Find is value consists in vector
bool findContains(TTriad *value, vector<TTriad *> objects) {
    bool flag = true;
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i] == value)
            flag = false;
    }

    return flag;
}

// Edit and create a new vector
vector<TTriad *> createNewVector(vector<TTriad *> objects, vector<TTriad *> correctObjects) {
    vector<TTriad *> newObjects;

    for (int i = 0; i < objects.size(); ++i) {
        if (findContains(objects[i], correctObjects)) {
            if (instanceof<TTime>(objects[i]))
                objects[i]->addValue(15, 2);
            else
                objects[i]->minValue(5, 1);
        }
        newObjects.push_back(objects[i]);
    }

    return newObjects;
}