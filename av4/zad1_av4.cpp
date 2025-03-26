#include <iostream>
#include <cstring>
using namespace std;

class Ekipa {
private:
    int founded;
    char name[30];
    char city[30];
public:
    Ekipa(int founded=0,char *name="",char *city="") {
        this->founded=founded;
        strcpy(this->name,name);
        strcpy(this->city,city);
    }
    Ekipa(const Ekipa &e) {
        this->founded=e.founded;
        strcpy(this->name,e.name);
        strcpy(this->city,e.city);
    }
    ~Ekipa(){}

    void print() {
        cout<<founded<<" "<<name<<" "<<city;
    }

    const char *getName()const {
        return name;
    }
};

class Natprevar {
private:
    Ekipa domakin;
    Ekipa gostin;
    int d_golovi;
    int g_golovi;
public:
    Natprevar(Ekipa domakin=Ekipa(),Ekipa gostin=Ekipa(),int d_golovi=0,int g_golovi=0) {
        this->domakin=domakin;
        this->gostin=gostin;
        this->d_golovi=d_golovi;
        this->g_golovi=g_golovi;
    }
    Natprevar(const Natprevar &n) {
        this->domakin=n.domakin;
        this->gostin=n.gostin;
        this->d_golovi=n.d_golovi;
        this->g_golovi=n.g_golovi;
    }

    void print() {
        cout<<"Natprevar pomegu: "<<endl;
        cout<<"--------------"<<endl;
        domakin.print();
        cout<<" vs ";
        gostin.print();
    }

    Ekipa &getDomakin()  {
        return domakin;
    }

    Ekipa &getGostin()  {
        return gostin;
    }

    int getD_golovi()const {
        return d_golovi;
    }

    int getG_golovi()const {
        return g_golovi;
    }
};

bool revans(Natprevar &n1,Natprevar &n2) {
    return strcmp(n1.getDomakin().getName(),n2.getGostin().getName())==0 && strcmp(n1.getGostin().getName(),n2.getDomakin().getName())==0;
}

Ekipa duel(Natprevar &n1,Natprevar &n2) {
    if (revans (n1,n2)) {
        int e1=n1.getD_golovi()+n2.getG_golovi();
        int e2=n1.getG_golovi()+n2.getD_golovi();
        if (e1>e2){return n1.getDomakin();}
        else if (e2>e1){return n1.getGostin();}
    }
}


int main() {
    Ekipa e1(1880, "Real Madrid", "Madrid");
    Ekipa e2(1880, "FC Barcelona", "Barcelona");
    Natprevar n1(e1, e2, 1, 2);
    Natprevar n2(e2, e1, 1, 0);
    Ekipa winner=duel(n1,n2);
    winner.print();
    return 0;
}









