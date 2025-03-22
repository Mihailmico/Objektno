#include <iostream>
#include <cstring>
using namespace std;

class Ekipa {
private:
    char ime[20];
    int formiranje;
    char poteklo[20];
public:
    Ekipa(char *_ime="nema",int _formiranje=0, char *_poteklo="nema") {
        strcpy(ime,_ime);
        formiranje=_formiranje;
        strcpy(poteklo,_poteklo);
    }
    void print() {
        cout<<ime<<" "<<formiranje<<" "<<poteklo;
    }

    const char* getname() {
        return ime;
    }
    /*bool isEqual(const Ekipa druga) {
        return strcmp(ime,druga.ime)==0;
    }*/

};

class Match {
private:
    Ekipa home;
    Ekipa away;
    int homeGoals;
    int awayGoals;
public:
    Match(Ekipa _home=Ekipa(),Ekipa _away=Ekipa(),int _homegoals=0, int _awaygoals=0) {
        home=_home;
        away=_away;
        homeGoals=_homegoals;
        awayGoals=_awaygoals;
    }

    void print() {
        cout<<"Match pomegu: ";
        home.print();
        cout<<" vs ";
        away.print();
    }

     Ekipa gethome() const {
        return home;
    }
     Ekipa getaway() const {
        return away;
    }

     int get_home_goals() const {
        return homeGoals;
    }

     int get_away_goals() const {
        return awayGoals;
    }

};

bool isRematch(const Match &m1,const Match &m2) {
    /*return m1.gethome().isEqual(m2.getaway()) && m2.gethome().isEqual(m1.getaway());*/
    return strcmp(m1.gethome().getname(),m2.getaway().getname())==0 &&
            strcmp(m1.getaway().getname(),m2.gethome().getname())==0;
}

int main() {
    Ekipa t1("Real Madrid",1902,"Madrid");
    Ekipa t2("Chelsea",1905,"London");
    Ekipa t3("Barcelona",1899,"Barcelona");
    //t1.print();
    //cout<<" ";
    //t2.print();
    Match m1(t1,t2);
    m1.print();
    cout<<endl;
    Match m2(t2,t1);
    cout<<endl;
    m2.print();
    cout<<endl;
    cout<<isRematch(m1,m2);

}