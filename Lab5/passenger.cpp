enum Class {
    Upper,
    Middle,
    Lower,
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

void printEmbarkation(std::ofstream* fout, Embarkation em) {
    std::string s;
    switch (em) {
        case Cherbourg:
            s = "Cherbourg";
            break;
        case Queenstown:
            s = "Queenstown";
            break;
        case Southampton:
            s = "Southampton";
            break;
    }

    (*fout) << s;
}

struct Passenger {
    short id;
    bool hasSurvived;
    Class pClass;
    std::string name;
    Sex sex;
    float age;
    int sibsp;
    int parch;
    std::string ticket;
    float fare;
    std::string cabin;
    Embarkation embarkation;
};

void initPassenger(Passenger* psg, char* string) {
    // PassengerId, Survived, Pclass, Name, Sex, Age, SibSp, Parch, Ticket, Fare, Cabin, Embarked

    // Читаем все поля подряд
    psg->id = readNextInt(string, ',');
    psg->hasSurvived = readNextBool(nullptr, ',');
    psg->pClass = static_cast<Class>(readNextInt(nullptr, ',') - 1);
    psg->name = readNextName(nullptr);    // Читаем имя по отдельным правилам
    psg->sex = readNextStr(nullptr, ',') == "male" ? Male : Female;
    psg->age = readNextFloat(nullptr, ',');    //-1.0 если пропущено
    psg->sibsp = readNextInt(nullptr, ',');
    psg->parch = readNextInt(nullptr, ',');
    psg->ticket = readNextStr(nullptr, ',');
    psg->fare = readNextFloat(nullptr, ',');
    psg->cabin = readNextStr(nullptr, ',');   // Пустая строка, если пропущено

    std::string embarked = readNextStr(nullptr, '\0');
    if (embarked == "S") psg->embarkation = Southampton;
    else if (embarked == "Q") psg->embarkation = Queenstown;
    else psg->embarkation = Cherbourg;
}

// Debug
void printPassenger(Passenger psg) {
    std::cout << '"' << psg.id << " " << psg.hasSurvived << " " << psg.pClass << " " << psg.name << " "
        << psg.sex << " " << psg.sibsp << " " << psg.parch << " " << psg.ticket << " " << psg.fare << " "
        << psg.cabin << " " << psg.embarkation << '"' << '\n';
}