#include <iostream>
#include <cstring>
using namespace std;

bool valid(char proba[]) {
    int brojac=0;
    for(int i=0;i<strlen(proba);i++) {
        if (proba[i]=='@') {
            brojac++;
        }
    }
    return brojac==1;
}

class Email {
private:
    char from [20];
    char to[20];
    char subject[100];
    char message[100];
public:
    Email(){};
    Email(char fromm[],char too[],char subjectt[],char messagee[]) {
        strcpy(from,fromm);
        strcpy(to,too);
        strcpy(subject,subjectt);
        strcpy(message,messagee);
    }

    void showMessage() {
        cout<<"From: "<<from<<endl;
        cout<<"To: "<<to<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Message: "<<message<<endl;
    }
};

int main() {
    char fromm[20],too[20],subjectt[100],messagee[100];
    cin.getline(fromm,20);
    cin.getline(too,20);
    cin.getline(subjectt,100);
    cin.getline(messagee,100);
    if (valid(fromm) && valid(too)) {
        Email email(fromm,too,subjectt,messagee);
        email.showMessage();
    }else{
        cout<<"email adress not valid,sorry bro";
        return 0;
    }
    return 0;
}


