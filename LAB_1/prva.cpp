#include <iostream>
using namespace std;

struct Engine {
    int horsepower;
    int torque;
};

struct Car {
    char ime[30];
    int god_prozivodstvo;
    Engine engine;
};

void input(Car cars[],int n) {
    for (int i=0;i<n;i++) {
        cin.getline(cars[i].ime, 30);
        cin>>cars[i].god_prozivodstvo;
        cin>>cars[i].engine.horsepower;
        cin>>cars[i].engine.torque;
        cin.ignore();
    }
}

void sort(Car cars[],int &n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(cars[j].engine.horsepower>cars[j+1].engine.horsepower) {
                Car tmp = cars[j];
                cars[j]=cars[j+1];
                cars[j+1]=tmp;
            }
        }
    }
}

void printCars(Car &a, Car &b) {
    if (a.engine.torque>=b.engine.torque) {
        cout<<a.ime<<" ";
        cout<<a.god_prozivodstvo<<" ";
        cout<<a.engine.horsepower<<" ";
        cout<<a.engine.torque<<" ";
    }else {
        cout<<b.ime<<" ";
        cout<<b.god_prozivodstvo<<" ";
        cout<<b.engine.horsepower<<" ";
        cout<<b.engine.torque<<" ";
    }
}

int main() {
    int n;
    Car cars[100];
    cin >> n;
    cin.ignore();

    input(cars, n);
    sort(cars, n);
    printCars(cars[0], cars[1]);

    return 0;

}
