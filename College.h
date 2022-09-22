/*Assinment 2
Autor:Lir Goffer, ID:209103274*/

#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "Department.h"

using namespace std;

class Course;

class College {
private:
    Department **departments;
    int numOfDepartments;
    Student **students;
    int numOfStudents;

    void addDepartment();

    void addCourseToDepartment();

    void addStudentToDepartment();

    void registerStudentToCourse();

    void gradingStudentsInCourse();

    void printCourseInfo() const;

    void printStudentInfo() const;

    void printDepartmentInfo() const;

    void findStudentsWithBadAcademicStat();

    int findDepartment(int) const;
  

    void addStudentToCollege(Student &newStud);

public:
    College() : departments(nullptr), numOfDepartments(0), students(nullptr), numOfStudents(0) {}
    College(const College &);
    ~College();

    College &operator=(const College &other);

    void menu();
};
