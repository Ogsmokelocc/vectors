#include <iostream>
#include <vector>
#include <random>
#include "TemplateSort.hpp"

using namespace std;
using IntSort = SORT<int>;
using CharSort = SORT<char>;
using DoubleSort = SORT<double>;

int main()
{
    // making array of diffent type
    vector<int> IntArray(10);
    vector<double> DoubleArray(10);
    vector<char> CharArray(10);

    // intializing classes and derived class
    IntSort *S;
    DoubleSort *D;
    CharSort *C;

    // derived classes
    intDATA DerivedOBJ_Int(IntArray);
    DoubleDATA DerivedOBJ_Double(DoubleArray);
    CharDATA DerivedOBJ_Char(CharArray);

    // derived objects
    IntArray = DerivedOBJ_Int.RandomVector();
    DoubleArray = DerivedOBJ_Double.RandomVector();
    CharArray = DerivedOBJ_Char.RandomVector();

    // printing random
    cout << "Psuedo Randon Arrays: " << endl;
    for (auto &i : IntArray)
    {
        cout << i << " ";
    };
    cout << "\n";
    cout << "\n";
    for (auto &i : DoubleArray)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    for (auto &i : CharArray)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    // passing unsorted arrays into sorting algos

    //DerivedOBJ_Int.SelectionSort(IntArray);
    // DerivedOBJ_Int.bogoSort(IntArray, IntArray.size());
    // DerivedOBJ_Int.GnomeSort(IntArray);
    DerivedOBJ_Int.QuickSort(IntArray, 0, IntArray.size() - 1);

    //DerivedOBJ_Double.SelectionSort(DoubleArray);
    // DerivedOBJ_Double.bogoSort(DoubleArray, DoubleArray.size());
    // DerivedOBJ_Double.GnomeSort(DoubleArray);
    DerivedOBJ_Double.QuickSort(DoubleArray, 0, DoubleArray.size() - 1);

    // DerivedOBJ_Char.SelectionSort(CharArray);
    // DerivedOBJ_Char.bogoSort(CharArray, CharArray.size());
    // DerivedOBJ_Char.GnomeSort(CharArray);
    DerivedOBJ_Char.QuickSort(CharArray, 0, CharArray.size() - 1);

    // pritning sorting array
    // cout<<"sorting Arrays using Selection Sort"<<endl;
    // cout<<"sorting Arrays using GnomeSort"<<endl;
    // cout<<"sorting Arrays using GnomeSort"<<endl;
    cout<<"sorting Arrays using QuickSort"<<endl;
    for (auto &i : IntArray)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    for (auto &i : DoubleArray)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    for (auto &i : CharArray)
    {
        cout << i << " ";
    }

    cout<<"\n"<<endl;
    // second argument is what binary sehrch is looking for, this is also the binary search being called returns -1 if array doest not contian said element
    int result=DerivedOBJ_Int.BinarySearch(IntArray, 5, 0, IntArray.size());
    int Dresult=DerivedOBJ_Double.BinarySearch(DoubleArray, 3.7, 0, DoubleArray.size());
    int Cresult = DerivedOBJ_Char.BinarySearch(CharArray, 'e', 0, CharArray.size());
    cout<<"the number you want is at index: "<< result<<endl;
    cout<<"the double you want is at index: "<<Dresult<<endl;
    cout<<"the char you want is at index: "<<Cresult<<endl;

    return 0;
}