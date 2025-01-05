#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
----This is the header file for students.cpp, their are 4 files dependent on this file, studentsMain.cpp,students.cpp
ClassRoom.cpp/hpp
-----All method definitons and constructor definitions are in the corrasponding cpp file with their description
*/
class Student
{
public:
    Student();
    Student(string Name, string Major, int Age, double GPA);
    string get_name() const;
    int get_age() const;
    double get_gpa() const;
    string get_major() const;
    void set_name(string newName);
    void set_major(string new_major);
    void set_age(int new_age);
    void set_gpa(double new_gpa);
    friend ostream &operator<<(ostream &COUT, const Student &student);
private:
    string name;
    string major;
    int age;
    double gpa;
};
#endif