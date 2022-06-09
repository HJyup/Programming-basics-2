#include "header.h"

int main() {
    vector<TTriad *> Objects;
    vector<TTriad *> CorrectObjects;

    // Create a vector with dates and times
    Objects = createVectorWithObjects();

    // Output objects
    cout << "\nObjects that represent times and dates: " << endl;
    outputObjects(Objects);

    // Create a vector with dates that can be represented like a time
    CorrectObjects = findCorrectDatesAndTime(Objects);

    // Output objects
    cout << "\nDates that can be represented like time:  " << endl;
    outputObjects(CorrectObjects);

    // Change Objects
    Objects = createNewVector(Objects, CorrectObjects);

    // Output objects
    cout << "\nChanged dates and times: " << endl;
    outputObjects(Objects);
}
