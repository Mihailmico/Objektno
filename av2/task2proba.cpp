#include <iostream>
#include <cstring>
using namespace std;

enum pozicija{vraboten,direktor,shef};

class Vraboten {
private:
    char ime[20];
    int plata;
    pozicija poz;
public:
    Vraboten() {}

    Vraboten(char imee[],int plataa,pozicija pozz) {
        strcpy(ime,imee);
        plata=plataa;
        poz=pozz;
    }

    void pecati() {
        cout<<ime<<" "<<plata;
        if (poz==0) {
            cout<<" Vraboten"<<endl;
        }else if (poz==1) {
            cout<<" Direktor"<<endl;
        }else {
            cout<<" Shef"<<endl;
        }
    }

    int get_plata() {
        return plata;
    }
};


void sortVraboteni(Vraboten vraboteni[],int &n ) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if(vraboteni[j].plata<vraboteni[j+1].get_plata()) {
                Vraboten tmp=vraboteni[j];
                vraboteni[j]=vraboteni[j+1];
                vraboteni[j+1]=tmp;
            }
        }
    }
}

int main() {
    Vraboten vraboteni[10];
    int n,pozicijaint,plata;
    char ime[20];
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++) {
        cin.getline(ime,20);
        cin>>pozicijaint;
        cin>>plata;
        cin.ignore();
        vraboteni[i]=Vraboten(ime,plata,(pozicija)pozicijaint);
    }

    sortVraboteni(vraboteni,n);

    for (int i=0;i<n;i++) {
        vraboteni[i].pecati();
    }

    return 0;

}