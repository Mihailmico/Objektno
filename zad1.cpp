#include <iostream>
using namespace std;


struct date {
    int year;
    int month;
    int day;
};

int sporedi(date &d1,date &d2) {
    if (d1.year>d2.year) {return 1;}
    else if (d1.year<d2.year) {return -1;}
    else {
        if (d1.month>d2.month) {return 1;}
        else if (d1.month<d2.month){return -1;}
        else {
            if (d1.day>d2.day){return 1;}
            else if (d1.day<d2.day){return -1;}
            else {return 0;}
        }
    }
}

int razlikaDenovi(date &d1,date &d2) {
    if (sporedi(d1,d2)==-1) {
        date tmp = d1;
        d1=d2;
        d2=tmp;
    }
    int denovi=0;
    denovi+=d1.day-d2.day;
    denovi+=(d1.month-d2.month)*30;
    denovi+=(d1.year-d2.year)*365;
    return denovi;


}

int main() {
    date d1,d2;
    cin>>d1.year>>d1.month>>d1.day;
    cin>>d2.year>>d2.month>>d2.day;

    int sporedba=sporedi(d1,d2);

    if (sporedba==0) {
        cout<<"Isti Datumi";
        return 0;
    }else if (sporedba==1) {
        cout<<"Prviot datum e pomal od vtoriot"<<endl;
        cout<<"Razlikata vo denovi e ";
        int razlika=razlikaDenovi(d1,d2);
        cout<<razlika<<endl;
    }else {
        cout<<"Vtoriot datum e pomal od prviot"<<endl;
        cout<<"Razlikata vo denovi e ";
        int razlika=razlikaDenovi(d1,d2);
        cout<<razlika<<endl;
    }
    return 0;
}