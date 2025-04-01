#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Boy {
private:
    char ime[20];
    int age;
public:
    Boy(char *_ime="nema",int age=0) {
        strcpy(ime,_ime);
        this->age=age;
    }
    void print();

    int getAge() const {
        return age;
    }

    const char* getName() const {
        return ime;
    }
};



void Boy::print() {
    cout<<"Boy:"<<ime<<" "<<age<<endl;
}


class Girl {
private:
    char ime[20];
    int age;
public:
    Girl(char *_ime="nema",int age=0) {
        strcpy(ime,_ime);
        this->age=age;
    }
    void print();
    ~Girl() {}

    int getAge() const {
        return age;
    }

    const char *getName()const {
        return ime;
    }
};

void Girl::print() {
    cout<<"Girl:"<<ime<<" "<<age<<endl;
}


class Date {
private:
    Boy boy;
    Girl girl;
public:
    Date(Boy _boy=Boy(),Girl _girl=Girl()) {
        boy=_boy;
        girl=_girl;
    }
    void print();
};

void Date::print() {
    cout<<"Date: ";
    boy.print();
    girl.print();
}

bool Match(Boy &boy, Girl &girl) {
    int razlika=abs(boy.getAge()-girl.getAge());
    return razlika<=5;
}

int main() {
    Boy boy1("Mico",19);
    Girl girl1("Anastasija",19);
    Date d1(boy1,girl1);
    d1.print();
    Match(boy1,girl1)?cout<<"It's a match":cout<<"Not a match";
}#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Boy {
private:
    char ime[20];
    int age;
public:
    Boy(char *_ime="nema",int age=0) {
        strcpy(ime,_ime);
        this->age=age;
    }
    void print();

    int getAge() const {
        return age;
    }

    const char* getName() const {
        return ime;
    }
};



void Boy::print() {
    cout<<"Boy:"<<ime<<" "<<age<<endl;
}


class Girl {
private:
    char ime[20];
    int age;
public:
    Girl(char *_ime="nema",int age=0) {
        strcpy(ime,_ime);
        this->age=age;
    }
    void print();
    ~Girl() {}

    int getAge() const {
        return age;
    }

    const char *getName()const {
        return ime;
    }
};

void Girl::print() {
    cout<<"Girl:"<<ime<<" "<<age<<endl;
}


class Date {
private:
    Boy boy;
    Girl girl;
public:
    Date(Boy _boy=Boy(),Girl _girl=Girl()) {
        boy=_boy;
        girl=_girl;
    }
    void print();
};

void Date::print() {
    cout<<"Date: ";
    boy.print();
    girl.print();
}

bool Match(Boy &boy, Girl &girl) {
    int razlika=abs(boy.getAge()-girl.getAge());
    return razlika<=5;
}

int main() {
    Boy boy1("Mico",19);
    Girl girl1("Anastasija",19);
    Date d1(boy1,girl1);
    d1.print();
    Match(boy1,girl1)?cout<<"It's a match":cout<<"Not a match";
}