#ifndef STUDENT_CLASSROOM_H
#define STUDENT_CLASSROOM_H
#include "Student.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
------This is the header file to ClassRooms.cpp(has all methods/definitions and descriptions)
------DEPENDENT on Student.hpp
*/
class ClassRoom
{
public:
    ClassRoom();
    void addStudents(Student &student);
    void Add(int amoutOfObjects);
    void remove(size_t RemoveAtIndex);
    void UseSwitch();
    size_t totalStudents();
    size_t find(string name);
    friend ostream &operator<<(ostream &COUT, const ClassRoom &classRoom);
private:
    vector<Student> students;
};
#endif