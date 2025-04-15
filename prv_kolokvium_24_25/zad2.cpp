#include <iostream>
#include <cstring>
using namespace std;

enum Category {security,kitchen,entertainment};

class Device {
private:
    char name[50];
    int energy;
    double price;
    Category c;
    bool status;
public:
    Device(){}
    Device(char *name,int energy,double price,Category c,bool status) {
        strcpy(this->name,name);
        this->energy=energy;
        this->price=price;
        this->c=c;
        this->status=status;
    }

    void togglePower() {
        if (status) {
            status=false;
        }else {
            status=true;
        }
    }

    void increaseEnergy(int watts) {
        this->energy+=watts;
    }


    void print() {
        cout<<name<<" ";
        if (c==0) {
            cout<<"(security) - Price: ";
        }else if (c==1) {
            cout<<"(kitchen) - Price: ";
        }else {
            cout<<"(entertainment) - Price: ";
        }

        cout<<price<<" Status: ";

        if (status) {
            cout<<"ON"<<endl;
        }else {
            cout<<"OFF"<<endl;
        }
    }

    const char *getName() {
        return name;
    }

    int getCategory() {
        return c;
    }

    bool getStatus() {
        return status;
    }

    void setStatus(bool stat) {
        status=stat;
    }

};

class SmartHome {
private:
    char name[50];
    Device d[100];
    static int id;
    static int list;
    int num_devices;
    friend SmartHome mostAutomatedSmartHome(SmartHome s[],int n);
public:
    SmartHome(char *name) {
        num_devices=0;
        strcpy(this->name,name);
        id++;
    }
    SmartHome(const SmartHome& other) {
        strcpy(this->name,other.name);
    }
    ~SmartHome(){}

    void addDevice(Device other) {
        bool exists=false;
        for (int i=0;i<num_devices;i++) {
            if (strcmp(d[i].getName(),other.getName())==0 && d[i].getCategory() == other.getCategory()) {
                exists=true;
                break;
            }
        }
        if (exists) {
            cout<<"Device already exists!"<<endl;
        }else {
            d[num_devices++]=other;
        }
    }

    void incrementPowerByCategory(Category c, int watts) {
        for (int i=0;i<num_devices;i++) {
            if (d[i].getCategory()==c) {
                d[i].increaseEnergy(watts);
            }
        }
    }

    void togglePowerByCategory(bool stat) {
        for (int i=0;i<num_devices;i++) {
            if (d[i].getStatus()==stat) {
                d[i].setStatus(stat);
            }
        }
    }

    int getNumDevices() {
        return num_devices;
    }
};

SmartHome mostAutomatedSmartHome(SmartHome s[],int n) {
    int maxindex;
    int maxDevices=0;
    for (int i=0;i<n;i++) {
        if (s[i].getNumDevices()>maxDevices) {
            maxindex=i;
            maxDevices=s[i].getNumDevices();
        }
    }
    return s[maxindex];
}

int SmartHome::id=0;
int SmartHome::list=100;

int main() {
    /*tuka si bese maino ubavo napisan da da*/
    return 0;
}