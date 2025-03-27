#include <iostream>
#include <cstring>
using namespace std;


class Student {
private:
    char name[30];
    float gpa;
    static int totalStudents;
    static int nextindex;
    static float totalGPA;
public:
    Student(){}
    Student(char *name,float gpa) {
        strcpy(this->name,name);
        this->gpa=gpa;
        totalStudents++;
        totalGPA+=gpa;
    }

    void print() {
        cout<<"Student name: "<<name<<endl;
        cout<<"Student gpa: "<<gpa<<endl;
        cout<<"Student index:"<<nextindex++<<endl;
    }

    static int getNumStudents() {
        return totalStudents;
    }

    static float averageGpa() {
        return totalGPA/totalStudents;
    }
};


int Student::nextindex=240001;
int Student::totalStudents=0;
float Student::totalGPA=0.0;

int main() {
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    int id;
    char name[30];
    float gpa;
    for (int i = 0; i < n; i++) {
        cin >> name >> gpa;
        students[i] = Student(name, gpa);
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }
    cout << "Total students: " << Student::getNumStudents() << endl;
    cout << "Total average: " << Student::averageGpa() << endl;
    return 0;
}