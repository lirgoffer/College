/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#pragma once

#include<iostream>
#include<string>
#include "Course.h"
#include"Department.h"

using namespace std;


class Course;
class Department;

class Student {
private:
    string stname; 
    string id;  
    char gender; 
    int age;  
    Course **clist; 
    int co_number; 



public:
    Student(); 
    Student(string, string, char, int);
    Student(Student const &);
    ~Student(); 

    Student &operator=(const Student &); 
    bool operator==(const Student &); 
    Course &operator[](int); 
    friend ostream &operator<<(ostream &, const Student &);
    friend istream &operator>>(istream &, Student &); 

    float calAvg();
    string* getId();

};
