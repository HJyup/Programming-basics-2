#include <iostream>
#include <string>
#include <vector>
#include "classes.h"

using namespace std;

// Create a container with objects
vector<TTriad *> createVectorWithObjects();

// Output objects
void outputObjects(vector<TTriad *> objects);

// Find dates that can be represented like a time
vector<TTriad *> findCorrectDatesAndTime(vector<TTriad *> objects);

// Change vector
vector<TTriad *> createNewVector(vector<TTriad *> objects, vector<TTriad *> correctObjects);