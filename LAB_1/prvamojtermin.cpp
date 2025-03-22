#include <iostream>
#include <iomanip>
using namespace std;

struct Tocka {
    int x;
    int y;
};

struct Krug {
    Tocka tocki;
    int radius;
};


void sortkrugovi(Krug a[],int n) {
    for(int i=0;i<n;i++) {
        for (int j=0;j<n-1-i;j++) {
            if (a[j].radius>a[j+1].radius) {
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    cin.ignore();

    Krug krugovi[10];

    for (int i=0;i<n;i++) {
        cin>>krugovi[i].tocki.x;
        cin>>krugovi[i].tocki.y;
        cin>>krugovi[i].radius;
    }

    sortkrugovi(krugovi,n);

    float plostina=krugovi[n-1].radius*krugovi[n-1].radius*3.14;

    cout<<"Krug so najgolema plostina e "<<setprecision(2)<<fixed<<plostina<<" so tocki ("<<krugovi[n-1].tocki.x<<","<<krugovi[n-1].tocki.y<<")";

    return 0;
}