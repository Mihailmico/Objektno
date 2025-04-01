#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string prezime;
    int indeks;
    int poeni;
    void pecati();
    void vnesi();
};

void Student::vnesi() {
    cin>>ime>>prezime;
    cin>>indeks;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    poeni=a+b+c+d;
}

void Student::pecati() {
    cout<<ime<<" "<<prezime<<" "<<indeks<<" "<<poeni<<endl;
}

void sort(Student student[],int n) {
    for (int i=0;i<n-1;i++) {
        if (student[i].poeni>student[i+1].poeni) {
            Student tmp=student[i];
            student[i]=student[i+1];
            student[i+1]=tmp;
        }
    }
}

int main() {
    int n;
    cin>>n;
    Student studenti [n];

    for (int i = 0; i < n; i++) {
        studenti[i].vnesi();
    }

    sort(studenti,n);

    cout<<"Vo rastecki redosled"<<endl;

    for (int i = 0; i < n; i++) {
        studenti[i].pecati();
    }

    return 0;
}