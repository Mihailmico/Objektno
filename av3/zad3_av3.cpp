#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day=0,int month=0,int year=0) {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void print() {
        cout<<day<<"."<<month<<"."<<year;
    }

    int get_day() const {
        return day;
    }

    int get_month() const {
        return month;
    }

    int get_year() const {
        return year;
    }
};

class Vraboten {
private:
    string ime;
    int plata;
    Date dob;
public:
    Vraboten(string ime="nema",int plata=0,Date dob=Date()) {
        this->ime=ime;
        this->plata=plata;
        this->dob=dob;
    }

    void print() {
        cout<<ime<<" "<<plata<<" ";
        dob.print();
    }

    string getime() const {
        return ime;
    }

    int getplata() const {
        return plata;
    }

    Date get_dob() const {
        return dob;
    }
};


Vraboten najvisokaplata(Vraboten *vraboteni,int n) {
    int maxvraboten=0;
    int max=vraboteni[0].getplata();
    for (int i=0;i<n;i++) {
        if (vraboteni[i].getplata()>max) {
            max=vraboteni[i].getplata();
            maxvraboten=i;
        }
    }
    return vraboteni[maxvraboten];
}

int sporedba(Date d1, Date d2) {
    // 0 ==, 1 d1>d2, -1 d2>d1

    if (d1.get_year()>d2.get_year()) {
        return 1;
    }else if (d1.get_year()<d2.get_year()) {
        return -1;
    }else if (d1.get_month()>d2.get_month()) {
        return 1;
    }else if (d1.get_month()<d2.get_month()) {
        return -1;
    }else if (d1.get_day()>d2.get_day()) {
        return 1;
    }else if (d1.get_day()<d2.get_day()) {
        return -1;
    }else {
        return 0;
    }
}

Vraboten najmlad(Vraboten *vraboteni,int n) {
    int najmlad=0;
    for (int i=0;i<n;i++) {
        if (sporedba(vraboteni[i].get_dob(),vraboteni[najmlad].get_dob())==1) {
            najmlad=i;
        }
    }

    return vraboteni[najmlad];
}

int main() {
    Date d1(1, 1, 1980);
    Date d2(1, 2, 1983);
    Date d3(11, 12, 1984);

    Vraboten v[3];
    Vraboten v1("Marjan", 40000, d1);
    Vraboten v2("Stefan", 30000, d2);
    Vraboten v3("Marko", 20000, d3);
    v[0] = v1;   v[1] = v2;   v[2] = v3;

    cout << "Najmlad vraboten: " << endl;
    najmlad(v, 3).print();
    cout<<endl;
    cout << "Vraboten so najgolema plata: " << endl;
    najvisokaplata(v, 3).print();

    return 0;
}