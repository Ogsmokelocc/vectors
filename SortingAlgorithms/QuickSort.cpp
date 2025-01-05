/*
Modify your existing sorting algorithm to use templates so that you can sort arrays of any (base) type.

dd a binary search function. Given an array and a value it searches for the item in the array and returns true (or 1) if the item is in the array and false (or 0) if the item is not in the array.
*/

#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;
const long sizeOfArray = 1000;

vector<int> deepFried(); // making dynamic array "vector"
// quick sort algorithm, using pivot number and low and high numbers
int partition(vector<int> &ARRAY, int low, int high);

void QuickSORT(vector<int> &SortedArray, int low, int high);

int main()
{
    vector<int> UnsortedArray = deepFried();
    // vector before sorting applied
    //-1 from sizeOfArr in place of high in quicksort function
    QuickSORT(UnsortedArray, 0, sizeOfArray-1);

    for(int i = 0; i < sizeOfArray; i++)
    {
        cout<<UnsortedArray[i]<<" ";
    }
};

vector<int> deepFried() // making dynamic array "vector"
{
    int deepfriedNUM = 0;

    vector<int> arr(sizeOfArray);
    // fill vector type 
    for (int i = 0; i < sizeOfArray; i++)
    {
        deepfriedNUM = rand() % 1000;
        arr[i] = deepfriedNUM;
    };

    return arr;
};

int partition(vector<int> &ARRAY, int low, int high)
{
    int pivotPoint = ARRAY[high]; // pivot number
    int j = low - 1;              // index of the smallest emelement in array;

    // traverse ARRAY[low high] and move all the smaller elements to the left side, elements from low to j shrink every recursion;
    for (int i = low; i <= high - 1; i++)
    {
        if (ARRAY[i] < pivotPoint)
        {
            j++;
            swap(ARRAY[j], ARRAY[i]);
        }
    }

    // now i am moving the pivot number to be after the smaller elements;
    swap(ARRAY[j + 1], ARRAY[high]);
    return j + 1;
};

void QuickSORT(vector<int> &SortedArray, int low, int high)
{
    if (low < high)
    {
        int IndexOfPivot = partition(SortedArray, low, high);

        // recursion
        QuickSORT(SortedArray, low, IndexOfPivot - 1);
        QuickSORT(SortedArray, IndexOfPivot + 1, high);
    }
};
