#include <iostream>
#include <cstring>
using namespace std;



class MountainTrail {
private:
    char name[50];
    int length;
    double slope;
public:
    MountainTrail(){}
    MountainTrail(char *name,int length,double slope) {
        strcpy(this->name,name);
        this->length=length;
        this->slope=slope;
    }
    MountainTrail(const MountainTrail &other) {
        strcpy(this->name,other.name);
        this->length=other.length;
        this->slope=other.slope;
    }

    double difficulty() {
        return (length*slope)/100;
    }

    void display() {
        cout<<name<<" "<<length<<" "<<slope<<endl;
    }

};

class Mountain {
private:
    char name[50];
    MountainTrail trails[5];
    int peak_elevation;
    static int num_mountains;

public:
    Mountain() {
        ++num_mountains;
    }
    Mountain(char *name,MountainTrail *trails,int peak_elevation) {
        strcpy(this->name,name);
        for (int i=0;i<5;i++) {
            this->trails[i]=trails[i];
        }
        this->peak_elevation=peak_elevation;
        ++num_mountains;
    }

    Mountain(const Mountain &other) {
        strcpy(this->name,other.name);
        for (int i=0;i<5;i++) {
            this->trails[i]=other.trails[i];
        }
        this->peak_elevation=other.peak_elevation;
        ++num_mountains;
    }
    ~Mountain() {
        --num_mountains;
    }

    void display() {
        cout<<name<<": "<<peak_elevation<<"m"<<endl;
    }
    static int getNumMountains() {
        return num_mountains;
    }
    friend void sortMountainsByPeakElevation(Mountain mountains[], int n);
};

void sortMountainsByPeakElevation(Mountain mountains[], int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-1-i;j++) {
            if (mountains[j].peak_elevation<mountains[j+1].peak_elevation) {
                swap(mountains[j],mountains[j+1]);
            }
        }
    }
    for (int i=0;i<n;i++) {
        mountains[i].display();
    }
}

int Mountain::num_mountains=0;

int main() {

    int test_case_n;

    char trail_name[100];
    int trail_length;
    double trail_slope;

    char mountain_name[100];
    int mountain_peak_elevation;

    cin>>test_case_n;
    if (test_case_n == 0) {
        cout << "Testing MountainTrail c-tors, display function:"<<endl;
        cin >> trail_name >> trail_length >> trail_slope;
        MountainTrail mt = MountainTrail(trail_name, trail_length, trail_slope);
        MountainTrail mt2 = MountainTrail(mt);
        mt.display();
        mt2.display();
    } else if (test_case_n == 1) {
        cout << "Testing MountainTrail difficulty function:"<<endl;
        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            MountainTrail mt = MountainTrail(trail_name, trail_length, trail_slope);
            cout<<mt.difficulty()<<endl;
        }
    } else if (test_case_n == 2) {
        cout << "Testing Mountain c-tor, display function:"<<endl;
        MountainTrail trails[5];

        cin>>mountain_name>>mountain_peak_elevation;

        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            trails[i] = MountainTrail(trail_name, trail_length, trail_slope);
        }
        Mountain mountain = Mountain(mountain_name, trails, mountain_peak_elevation);
        mountain.display();
    } else if (test_case_n == 3) {
        cout << "Testing static field in Mountain:" <<endl;
        MountainTrail trails[5];

        cin>>mountain_name>>mountain_peak_elevation;

        for (int i = 0; i < 5; ++i) {
            cin >> trail_name >> trail_length >> trail_slope;
            trails[i] = MountainTrail(trail_name, trail_length, trail_slope);
        }

        for (int i = 0; i < 10; ++i) {
            Mountain mountain = Mountain(mountain_name, trails, mountain_peak_elevation);
        }

        Mountain m1 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m2 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m3 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m4 = Mountain(mountain_name, trails, mountain_peak_elevation);
        Mountain m5 = Mountain(mountain_name, trails, mountain_peak_elevation);

        if(Mountain::getNumMountains() == 5) {
            cout<<"OK";
        } else {
            cout<<"Missing mountain count increment/decrement";
        }
    } else if (test_case_n == 4) {
        int M;
        cin>>M;
        cout<<"Testing order function:"<<endl;

        Mountain mountains[M];
        for (int i = 0; i < M; ++i) {
            cin>>mountain_name>>mountain_peak_elevation;
            MountainTrail trails[5];

            for (int j = 0; j < 5; ++j) {
                cin >> trail_name >> trail_length >> trail_slope;
                trails[j] = MountainTrail(trail_name, trail_length, trail_slope);
            }

            mountains[i] = Mountain(mountain_name, trails, mountain_peak_elevation);
        }

        sortMountainsByPeakElevation(mountains, M);
    }
}