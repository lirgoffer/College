/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#include "Student.h"
#include<iostream>

using namespace std;

Student::Student() : stname(string()), id(string()), gender('M'), age(0), clist(NULL), co_number(0) {}

Student::Student(string name, string id1, char gen, int age1) : stname(name), id(id1), gender(gen), age(age1), clist(NULL), co_number(0) {}

Student::Student(Student const &other) : stname(other.stname), id(other.id), gender(other.gender), age(other.age), co_number(other.co_number) {
    this->clist = other.clist;
    if (co_number > 0) {
        this->clist = new Course *[co_number];
        for (int i = 0; i < co_number; i++) {
            clist[i] = other.clist[i];
        }
    } else
        clist = NULL;
}

Student::~Student() {
    for (int i = 0; i < co_number; i++) {
        delete[] clist[i];
    }
    delete[] clist;
}

Student &Student::operator=(const Student &other) {
    if (this != &other) {
        this->stname = other.stname;
        this->id = other.id;
        this->gender = other.gender;
        this->age = other.age;
        this->co_number = other.co_number;
        clist = new Course *[co_number];

        for (int i = 0; i < co_number; i++) {
            this->clist[i] = new Course(*clist[i]);
        }
        

    }
    return *this;

}


ostream &operator<<(ostream &out, const Student &other) {
    out << "Name:" << other.stname << endl;
    out << "ID" << other.id << endl;
    out << "Gender" << other.gender << endl;
    out << "Age:" << other.age << endl;
    out << "The student is:" << endl;

    return out;
}


bool Student::operator==(const Student &other) {
    if (this->id == other.id)
        return true;

    return false;
}

Course &Student::operator[](int num) {
    if (num >= 0 && num <= co_number) {  
        return *clist[num];
    } else {
        cout << "Not in the range" << endl;
        exit(1);
    }
}

istream &operator>>(istream &in, Student &other) {

    cout << "Enter student's name:" << endl;
    in >> other.stname;
    cout << "Enter student's's id:" << endl;
    in >> other.id;
    cout << "Enter student's gender <F-female/M-male>" << endl;
    in >> other.gender;
    return in;
}

float Student::calAvg() {

    int sum = 0;

    if (!this->clist)
        return 0;

    for (int i = 0; i < this->co_number; i++)
    {
        sum += this->clist[i]->getGrade(&id);
    }
    return sum / co_number;
}

string* Student::getId() {
    return &id;
}