 #include <iostream>
#include <vector>
#include "Student.hpp"
using namespace std;
// constructors defualt and filled
Student::Student() {};
Student::Student(string Name, string Major, int Age, double GPA) : name(Name), major(Major), age(Age), gpa(GPA) {}
// getter and setter functions
string Student::get_name() const
{
    return name;
}
string Student::get_major() const
{
    return major;
}
int Student::get_age() const
{
    return age;
}
double Student::get_gpa() const
{
    return gpa;
}
void Student::set_name(string newName)
{
    name = newName;
}
void Student::set_major(string new_major)
{
    major = new_major;
}
void Student::set_age(int new_age)
{
    age = new_age;
}
void Student::set_gpa(double new_gpa)
{
    gpa = new_gpa;
}
// Overloading cout<<
ostream &operator<<(ostream &COUT, const Student &student)
{
    COUT << " [NAME]: " << student.get_name() << ", [MAJOR]: ";
    COUT << student.get_major() << ", [AGE]: ";
    COUT << student.get_age() << ", [GPA]: ";
    COUT << student.get_gpa() << "\n";
    return COUT;
}