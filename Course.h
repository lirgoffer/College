/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#pragma once

#include<iostream>
#include<string>
#include"Department.h"
#include "Student.h"

using namespace std;


class Student;
class Department;

class Course {
private:
    string c_name; 
    int c_num; 
    Student **st_list; 
    int st_num; 
    int *grades;
    Department *dep_course; 

public:
    Course(); 
    Course(string, int); 
    Course(Course const &);
    ~Course(); 

    Course &operator=(const Course &); 
    bool operator==(const Course &) const;
    Student &operator[](int); 
    friend ostream &operator<<(ostream &, const Course &); 
    friend istream &operator>>(istream &, Course &); 

    int getGrade(string*);
};
