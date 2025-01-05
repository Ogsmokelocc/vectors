#include <iterator>
#include <vector>
#include <unordered_map>
#include "ClassRoom.hpp"
#define UwU switch
using namespace std;
// ClassRoom defualt constructor will auto load vector of type student
ClassRoom::ClassRoom() {};
// Adding student objects to the class classroom vector
void ClassRoom::addStudents(Student &student)
{
    students.push_back(student);
}
// returns index if found or -1 if name does not exist;
size_t ClassRoom::find(string name)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if ((students.at(i).get_name() == name))
        {
            cout << students.at(i).get_name() << " Is at INDEX: " << i << "" << "\n";
            return i;
        }
    }
    return -1;
}
// friend function to overload the ostream pipe operators
ostream &operator<<(ostream &COUT, const ClassRoom &classRoom)
{
    // COUT << " }";
    // // 3: Bob, CS, 3.55, 20#
    // // returns COUT
    // return COUT;
    // 1: Bob, CS, 3.55, 20#
    // 2: Joe, MATH, 4.01, 12#
    for (size_t i = 0; i < classRoom.students.size(); i++)
    {
        COUT << i << " : " << classRoom.students.at(i);
    }
    return COUT;
}
/*function to add N amount of objects to the class room vector,
the amount N is passed in via the function parameter,
then the functiontakes in the data types for the object in a loop that is incrementented N(user input in parameter) time
*/
void ClassRoom::Add(int amountOfObjects)
{
    string name;
    string major;
    int age;
    double gpa;
    int i = 0;
    while (i < amountOfObjects)
    {
        cout << "enter students Name:" << endl;
        getline(cin >> ws, name);
        cout << "Enter students Major:" << endl;
        getline(cin >> ws, major);
        cout << "Enter students Age:" << endl;
        cin >> age;
        cout << "Enter students GPA:" << endl;
        cin >> gpa;
        cout << "\n";
        Student newStudent(name, major, age, gpa);
        cout << "Would you like to add the student to the front or back of the roster? Enter F or B:" << endl;
        char choice;
        cin >> choice;
        if (choice == 'f' or choice == 'F')
        {
            students.push_back(newStudent);
        }
        else if (choice == 'B' or choice == 'b')
        {
            students.insert(students.begin(), newStudent);
        }
        i++;
    };
}
// deletes object from object vector at index input in function parameter
void ClassRoom::remove(size_t removeAtIndex)
{
    students.erase(students.begin() + removeAtIndex);
};
// returns the total amount of idencies in  object vector
size_t ClassRoom::totalStudents()
{
    return students.size();
    // returns students.size()
};
/*
this is essesntially the user interface in the terminal, lets you pick between all the methods to manipulate the
vector, ADD,Remove,Search,PrintALL....
*/
void ClassRoom::UseSwitch()
{
    char choice;
    char GlockSwitch;
    string NameToSearch;
    int howmanyUwant;
    int IndexToRemove;
    cout << "Enter [Y/N]: To Enter User Interface" << endl;
    cin >> choice;
    
    while (choice == 'y' or choice == 'Y')
    {
        cout << "Enter [A]: to add"
                "\n"
                "Enter [R]: to remove"
                "\n"
                "Enter [S]: to search name"
                "\n"
                "Enter [T]: to find total amount of students"
                "\n"
                "Enter [M]: to print all"
                "\n"
                "Enter [Q]: to Exit"
             << endl;
        cin >> GlockSwitch;

        UwU(GlockSwitch)
        {
        case 'A':
            cout << "how many students do you want to add?" << endl;
            cin >> howmanyUwant;
            Add(howmanyUwant);
            break;
        case 'R':
            cout << "enter the index to be removed" << endl;
            cin >> IndexToRemove;
            remove(IndexToRemove);
            break;
        case 'S':
            cout << "Enter the name to be searched" << endl;
            getline(cin >> ws, NameToSearch);
            find(NameToSearch);
            break;
        case 'T':
            cout << totalStudents() << endl;
            break;
        case 'M':
            cout << *this;
            break;
        case 'Q':
            cout << "Enter Q to exit:" << endl;
            cin >> choice;
        default:
            break;
        }
    }
}
