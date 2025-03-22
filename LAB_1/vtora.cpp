#include <iostream>
#include <cstring>
using namespace std;

class BasketballPlayer {
private:
    char ime[20];
    char prezime[20];
    int brojDres;
    float avg;
public:
    BasketballPlayer(char imee[],char prezimee[],int dress,float avgg) {
        strcpy(ime,imee);
        strcpy(prezime,prezimee);
        brojDres=dress;
        avg=avgg;
    }

    void pecati() {
        cout<<"Player: "<<ime<<" "<<prezime<<" with number "<<brojDres<<" has "<<avg<<" points on average"<<endl;
    }
};

int main() {
    char ime[20];
    char prezime[20];
    int brojDres,poeni1,poeni2,poeni3;
    float avg;
    cin.getline(ime,20);
    cin.getline(prezime,20);
    cin>>brojDres;
    cin>>poeni1;
    cin>>poeni2;
    cin>>poeni3;
    avg=(poeni1+poeni2+poeni3)/3;
    BasketballPlayer mico(ime,prezime,brojDres,avg);
    mico.pecati();
    return 0;



}