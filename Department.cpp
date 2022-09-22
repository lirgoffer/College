/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#include "Department.h"
#include<iostream>

using namespace std;

Department::Department() : dep_name(string()), code(0), dep_clist(nullptr), course_number(0), dep_stlist(nullptr), st_dep(0),fail(nullptr), num_fail(0) {}


Department::Department(string name, int code1) : dep_clist(nullptr), course_number(0), dep_stlist(nullptr), st_dep(0), fail(nullptr), num_fail(0) {
    this->dep_name = name;
    this->code = code1;
}

Department::Department(const Department &other) : dep_name(other.dep_name), code(other.code), course_number(other.course_number), st_dep(other.st_dep), num_fail(other.num_fail) {  //copy

    if (course_number > 0) {
        this->dep_clist = new Course *[course_number];
        for (int i = 0; i < course_number; i++) {
            dep_clist[i] = other.dep_clist[i];
        }
    } else
        dep_clist = nullptr;

    if (st_dep > 0) {
        this->dep_stlist = new Student *[st_dep];
        for (int j = 0; j < st_dep; j++) {
            dep_stlist[j] = other.dep_stlist[j];
        }
    } else
        dep_stlist = nullptr;

    if (num_fail > 0) {
        this->fail = new Student *[num_fail];
        for (int k = 0; k < num_fail; k++) {
            fail[k] = other.fail[k];
        }
    } else
        fail = nullptr;
}

Department::~Department() {
    for (int i = 0; i < course_number; i++) {
        delete[] dep_clist[i];
    }
    delete[] dep_clist;

    for (int j = 0; j < st_dep; j++) {
        delete[] dep_stlist[j];
    }
    delete[] dep_stlist;

    for (int k = 0; k < num_fail; k++) {
        delete[] fail[k];
    }
    delete[] fail;
}

Department &Department::operator=(const Department &other) {
    if (this != &other) {
        this->dep_name = other.dep_name;
        this->code = other.code;
        this->course_number = other.course_number;
        this->st_dep = other.st_dep;
        this->num_fail = other.num_fail;

        dep_clist = new Course *[course_number];
        for (int i = 0; i < course_number; i++) {
            this->dep_clist[i] = new Course(*dep_clist[i]);
        }

        dep_stlist = new Student *[st_dep];
        for (int i = 0; i < st_dep; i++) {
            this->dep_stlist[i] = new Student(*dep_stlist[i]);
        }
        fail = new Student *[num_fail];
        for (int i = 0; i < num_fail; i++) {
            this->fail[i] = new Student(*fail[i]);


        }
    }
    else{
        cout << "same" << endl;
    }
    return *this;
}


bool Department::operator==(const Department &other) const {
    if (this->code == other.code)
        return true;

    return false;
}


Course &Department::return_course(int num) {
    if (num >= 0 && num <= course_number) {  
        return *dep_clist[num];
    } else {
        cout << "Not in the range" << endl;
    }
}

Student &Department::return_student(int num) {
    if (num >= 0 && num <= st_dep) {  
        return *dep_stlist[num];
    } else {
        cout << "Not in the range" << endl;
    }
}

ostream &operator<<(ostream &out, const Department &other) {
    out << "Department: " << other.dep_name << endl;
    out << "Department code: " << other.code << endl;
    out << "Courses in the department: " << other.course_number << endl;
    out << "Students in the department: " << other.st_dep << endl;
    out << "Failing student in the department: " << other.num_fail << endl;

    return out;
}


istream &operator>>(istream &in, Department &other) {

    cout << "Enter department's name:" << endl;
    in >> other.dep_name;
    cout << "Enter department's id:" << endl;
    in >> other.code;

    return in;
}

int Department::getCode() {
    return this->code;
}

Department& Department::operator += (Student object)
{

    if (object.calAvg() < 60)
    {
        Student** temparray = new Student * [num_fail];
        for (size_t i = 0; i < num_fail; i++)
        {
            temparray[i] = fail[i];
        }
        for (size_t i = 0; i < num_fail; i++)
        {
            delete fail[i];
        }
        delete[] fail;
        this->num_fail = num_fail + 1;
        fail = new Student * [num_fail];
        int i;
        for (i = 0; i < num_fail; i++)
        {
            fail[i] = temparray[i];
        }
        fail[i] = &object;
        for (size_t i = 0; i < num_fail-1; i++)
        {
            delete temparray[i];
        }
        delete[] temparray;
    }

    return *this;
}

int Department::getNumberOfCourse() {
    return this->course_number;
}

void Department::addCourse(Course course){
    if (this->course_number == 0){
        this->course_number++;
        this->dep_clist = new Course*[this->course_number];
        this->dep_clist[0] = &course;
    }
    else{
        Course **temp = new Course*[this->course_number];
        for (int i = 0; i < this->course_number; ++i) {
            temp[i] = this->dep_clist[i];
        }
        for (int i = 0; i < this->course_number; ++i) {
            delete this->dep_clist[i];
        }
        delete[] this->dep_clist;
        this->course_number++;
        this->dep_clist = new Course*[this->course_number];
        int i = 0;
        for (; i < this->course_number - 1; ++i) {
            this->dep_clist[i] = temp[i];
        }
        this->dep_clist[i] = &course;
    }

}

