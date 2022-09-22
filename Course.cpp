/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#include "Course.h"
#include<iostream>

using namespace std;

Course::Course() : c_name(""), c_num(0), st_list(nullptr), st_num(0), grades(nullptr), dep_course(nullptr) {}


Course::Course(string name, int courseId) : c_name(name), c_num(courseId), st_list(nullptr), st_num(0), grades(nullptr), dep_course(nullptr) {}


Course::Course(const Course &other) : c_name(other.c_name), c_num(other.c_num), st_num(other.st_num) {  
    this->dep_course = other.dep_course;
    if (st_num > 0) {
        this->st_list = new Student *[st_num];
        this->grades = new int[st_num];
        for (int i = 0; i < st_num; i++) {
            st_list[i] = other.st_list[i];
            grades[i] = other.grades[i];
        }
    } else {
        st_list = nullptr;
        grades = nullptr;
    }
}


Course::~Course() 
{
    for (int i = 0; i < st_num; i++) {
        delete[] st_list[i];
    }
    delete[] st_list;
    delete[] dep_course;
}

Course &Course::operator=(const Course &other) {
    if (this != &other) {
        this->c_num = other.c_num;
        this->st_num = other.st_num;
        this->grades = new int[st_num];
        st_list = new Student *[st_num];

        for (int i = 0; i < st_num; i++) {
            this->grades[i] = grades[i];
            this->st_list[i] = new Student(*st_list[i]);
        }

        dep_course = new Department(dep_course[0]);
        *this->dep_course = *dep_course;
    } else {
        cout << "Same" << endl;
    }

    return *this;
}

bool Course::operator==(const Course &other) const {
    if (this->c_num == other.c_num)
        return true;

    return false;
}

Student &Course::operator[](int num) {
    if (num >= 0 && num <= st_num) { 
        return *st_list[num];
    } else {
        cout << "Not in the range" << endl;
        exit(1);
    }
}

ostream &operator<<(ostream &out, const Course &other) {
    out << "Course name:" << other.c_name << endl;
    out << "Course ID:" << other.c_num << endl;
    out << "The course is a " << other.dep_course << endl;
    out << "Number of student in course:" << other.st_num << endl;

    for (int i = 0; i < other.st_num; i++) {
        out << "Student:" << other.st_list[i] << endl;
        out << "Grade:" << other.grades[i] << endl;
    }
    return out;
}

istream &operator>>(istream &in, Course &other) {
    cout << "Enter course's name:" << endl;
    in >> other.c_name;
    cout << "Enter course's id:" << endl;
    in >> other.c_num;

    return in;
}

int Course::getGrade(string* studentID) {

    int temp;
    for (size_t i = 0; i < st_num; i++)
    {
        if (this->st_list[i]->getId() == studentID)
        {
            temp = i;
            break;
        }
    }
    return grades[temp];
}


