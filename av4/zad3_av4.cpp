#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char name[30];
    char id[10];
    float average;
    static int num_students;
    static float GPA;
public:
    Student(){}
    Student(char *name,float average,char *id) {
        strcpy(this->name,name);
        strcpy(this->id,id);
        this->average=average;
        num_students++;
        GPA+=average;
    }
    Student(const Student &s){
        strcpy(this->name,s.name);
        strcpy(this->id,s.id);
        this->average=s.average;
    }

    static int getTotalStudents() {
        return num_students;
    }

    static float getGPA() {
        return GPA;
    }

    static float getAverageGPA() {
        return GPA/num_students;
    }

    void print() {
        cout<<name<<" "<<id<<" "<<average<<endl;
    }
};

int Student::num_students=0;
float Student::GPA=0.0;

int main() {
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    char name[30], id[10];
    float gpa;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> gpa;
        students[i] = Student(name, gpa, id);
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }

    cout << "Total students: " << Student::getTotalStudents() << endl;
    cout << "Total average: " << Student::getAverageGPA() << endl;
    return 0;
}