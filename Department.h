/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#pragma once

#include<iostream>
#include<string>
#include "Student.h"
#include"Course.h"

using namespace std;

class Student;
class Course;

class Department {
private:
    string dep_name;
    int code;
    Course **dep_clist;
    int course_number;
    Student **dep_stlist;
    int st_dep;
    Student **fail;
    int num_fail;

public:
    Department();
    Department(string, int);
    Department(Department const &);
    ~Department();

    Department &operator=(const Department &);
    bool operator==(const Department &) const;

    Department& operator += (Student );

    Course &return_course(int);

    Student &return_student(int);

    friend ostream &operator<<(ostream &, const Department &);
    friend istream &operator>>(istream &, Department &);

    int getCode();
    int getNumberOfCourse();
    void addCourse(Course );

};
