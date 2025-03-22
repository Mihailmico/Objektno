#include <iostream>
#include <string.h>
using namespace std;

class Country {
private:
    char name[100];
    char capital[100];
    float area;
    float population;
public:
    Country(char *imee=" ",char gl_grad[]="",float povrsina=0,float populacija=0) {
        strcpy(name,imee);
        strcpy(capital,gl_grad);
        area=povrsina;
        population=populacija;
    }

    void display() {
        cout<<"Country: "<<name<<endl;
        cout<<"Capital: "<<capital<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Population: "<<population<<endl;
    }

     float area1() const {
        return area;
    }

    void set_area(float area) {
        this->area = area;
    }

     float population1() const {
        return population;
    }

    void set_population(float population) {
        this->population = population;
    }
};


int main() {
    int n;
    cin>>n;
    cin.ignore();
    Country drzavi[100];
    for (int i=0;i<n;i++) {
        char imee[100];
        char gl_grad[100];
        float povrsina;
        float populacija;
        cin.getline(imee,100);
        cin.getline(gl_grad,100);
        cin>>povrsina;
        cin>>populacija;
        cin.ignore();
        drzavi[i]=Country(imee,gl_grad,povrsina,populacija);
    }


    for (int i=0;i<n;i++) {
        drzavi[i].display();
    }
    return 0;
}