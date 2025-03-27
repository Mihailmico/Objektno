#include <iostream>
#include <cstring>
using namespace std;

class LibraryMember;
class Library;

class Book {
private:
    char name[20];
    char author[20];
    bool available;
    friend class Library;
    friend void checkOutBook(LibraryMember &l,Library &lib,int index);
public:
    Book(){}
    explicit Book(char *name,char *author,bool available) {
        strcpy(this->name,name);
        strcpy(this->author,author);
        this->available=available;
    }
    Book(const Book &b) {
        strcpy(this->name,b.name);
        strcpy(this->author,b.author);
        this->available=b.available;
    }
    ~Book(){};


    void print() {
        cout<<name<<" "<<author<<endl;
    }
};


class Library {
private:
    char name[30];
    Book books[30];
    int numBooks;
    friend void checkOutBook(LibraryMember &l,Library &lib,int index);

public:
    Library() {
        strcpy(name,"Braka Miladinovci");
        numBooks=0;
    }
    explicit Library(char *name,Book *books,int numBooks) {
        strcpy(this->name,name);
        for (int i=0;i<numBooks;i++) {
            this->books[i]=books[i];
        }
        this->numBooks=numBooks;
    }
    void addBook(Book &b) {
        if (numBooks<30) {
            books[numBooks++]=b;
        }else {
            cout<<"FULL SORRY GET OUT BRO";
        }
    }

    void print() {
        cout<<name<<" "<<endl;
        for (int i=0;i<numBooks;i++) {
            books[i].print();
        }

    }
};


class LibraryMember {
private:
    char name[20];
    int id;
public:
    LibraryMember(){}
    LibraryMember(char *name,int id) {
        strcpy(this->name,name);
        this->id=id;
    }
    friend void checkOutBook(LibraryMember &l,Library &lib,int index);

    void print() {
        cout << "Library Member: " << name << " (ID: " << id << ")" << endl;
    }
};

void checkOutBook(LibraryMember &m, Library &l, int id) {
    if (l.books[id].available) {
        cout<<m.name<<" "<<"ja zima "<<l.books[id].name<<endl;
    }else {
        cout<<"Sorry bro it ain't here"<<endl;
    }
}

int main() {
    Book books[] = {
        Book("Harry Potter", "J.K. Rowling", true),
        Book("Lord of the Rings", "J.R.R. Tolkien", false),
        Book("The Hobbit", "J.R.R. Tolkien", true),
        Book("Pride and Prejudice", "Jane Austen", true),
        Book("1984", "George Orwell", false)
    };

    Library lib("City Library", books, 5);
    LibraryMember member("John Doe", 101);

    lib.print();
    cout << endl;
    member.print();
    cout << endl;

    checkOutBook(member, lib, 0);
    checkOutBook(member, lib, 1);
    checkOutBook(member, lib, 2);
    checkOutBook(member, lib, 3);
    checkOutBook(member, lib, 4);

    return 0;

}
