#include <iostream>
#include <cstring>
using namespace std;

class TableTennisPlayer {
private:
    char name[50];
    char country[50];

public:
    TableTennisPlayer(){}
    TableTennisPlayer(char *name,char *country) {
        strcpy(this->name,name);
        strcpy(this->country,country);
    }

    void print() {
        cout<<name<<" ("<<country<<")";
    }

    const char *getName() {
        return name;
    }

    const char *getCountry() {
        return country;
    }
};



class TableTennisMatch {
private:
    char date[11];
    TableTennisPlayer p1;
    TableTennisPlayer p2;
    int pts1;
    int pts2;
public:
    TableTennisMatch(char *date,TableTennisPlayer p1,TableTennisPlayer p2,int pts1,int pts2) {
        strcpy(this->date,date);
        this->p1=p1;
        this->p2=p2;
        this->pts1=pts1;
        this->pts2=pts2;
    }

    void print() {
        cout<<"Date: "<<date<<endl;
        cout<<"Match Details:"<<endl;
        p1.print();
        cout<<" - Points: "<<pts1<<endl;
        p2.print();
        cout<<" - Points: "<<pts2<<endl;

    }
};


int main() {
    int n;
    cin>>n;
    cin.ignore();
    while (n) {
        char date[11];
        int pts1;
        int pts2;
        char name1[50];
        char country1[50];
        char name2[50];
        char country2[50];

        cin.getline(date,11);

        cin.getline(name1,50);
        cin.getline(country1,50);
        cin>>pts1;
        cin.ignore();

        cin.getline(name2,50);
        cin.getline(country2,50);
        cin>>pts2;
        cin.ignore();

        TableTennisPlayer p1(name1,country1);
        TableTennisPlayer p2(name2,country2);

        TableTennisMatch match(date,p1,p2,pts1,pts2);

        match.print();

        n--;
    }
    return 0;
}