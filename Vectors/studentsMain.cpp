/*
-----WARNING you must compile "g++ studentsMain.cpp students.cpp ClassRoom.cpp" WARNING--------
*/
#include <iostream>
#include <vector>
#include <map>
#include "Student.hpp"
#include "ClassRoom.hpp"
int main()
{
    ClassRoom classRoom;
    // loading the vector with three base students per assignment guidelines  void ClassRoom::addStudents(Student &student) string Name, string Major, int Age, double GPA
    Student student1("Xavier", "Computer Science", 26, 3.7);
    Student student2("Kristian", "Mechanical Engineering", 27, 3.5);
    Student student3("P DIDDY", "Rizzology", 51, 4.0);
    classRoom.addStudents(student1);
    classRoom.addStudents(student2);
    classRoom.addStudents(student3);
    classRoom.UseSwitch();
    return 0;
    //returns 0;
}
