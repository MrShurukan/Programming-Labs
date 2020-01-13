#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

enum Class {
    Upper,
    Middle,
    Lower
};

enum Sex {
    Male,
    Female
};

enum Embarkation {
    Cherbourg,
    Queenstown,
    Southampton
};

struct Passenger {
    bool hasSurvived;
    Class pClass;
    std::string name;
    Sex sex;
    float age;
    int sibsp;
    int parch;
    std::string ticketN;
    double fare;
    std::string cabin;
    Embarkation embarkation;
};

std::vector<Passenger> passengers;

int main() {
    std::ifstream fin("CSV/train.csv");
    std::string buffer;

    return 0;
}