/*
In selection sort you find a minimal (or maximal) element and put it to top (bottom), then repeat it again for the rest of list.
*/

#include <iostream>
#include <vector>
#include <random>
#include<variant>
#include"TemplateSort.hpp"
using namespace std;

//define variant type that can hold int, char and 
using VariantType = std::variant<int, char, double>;

void SelectionSort(vector<int> &ARRAY);
bool isSorted(vector<int> &ARRAY, int n);
void shuffle(vector<int> &ARRAY, int n);
void bogoSort(vector<int> &ARRAY, int n);

int main()
{

    // vector<pair<int, char> > ARRAY;

    // for(int i = 0; i<10; i++)
    // {
    //     ARRAY.push_back(make_pair(i,'a'+i));
    // };

    // for(auto &n: ARRAY)
    // {
    //     cout<<n.first<< " "<<n.second<<" "<<endl;
    // }
//making a variant its like a vector idk

//defining the demensions

const int depth = 1;
const int rows= 2;
const int cols= 3;

//3d vector with variant types

vector<vector<vector<VariantType> > > SuperArray(depth, vector<vector<VariantType> >(rows, vector<VariantType>(cols)));

for(int d = 0; d<depth; d++)//might need to be ++d
{
    for(int i= 0; i < rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            if(d==0)
            {
                SuperArray[d][i][j]=(i*cols+j); // FILL ME UP SENPAI uwu with ints
            } else if(d== 1 and i ==0)
            {
                SuperArray[d][i][j] = static_cast<double>(j)/2.0;//filled up with double
            } else
            {
                char value = 'a'+ (i*cols +j);
                SuperArray[d][i][j] = value;//fill with chars
                cout<<"Assinged: "<< value<< " at Depth "<< d<< " Rows: " << i << "cols: " << j <<endl;
            }
        }
    }
}

//displaying this monstrasity

for(int d = 0; d< depth; ++d)
{
    for(int i = 0; i <rows; ++i)
    {
        for(int j =0; j <cols; ++j)
        {
            cout<<" Depth: "<< d << " Rows: "<< i << " Cols: "<< j << "-->";
            std::visit([](const auto &value) 
            {
                std:: cout<< value << std::endl;
            }, SuperArray[d][i][j]);//visting variants to print value
        }
    }
}


return 0;
};

bool isSorted(vector<int> &ARRAY, int n)
{
    while (--n > 0)
    {

        if (ARRAY[n] < ARRAY[n - 1])
        {
            return false;
        }
    }
    return true;
}

void shuffle(vector<int> &ARRAY, int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(ARRAY[i], ARRAY[rand() % n]);
    }
}

void bogoSort(vector<int> &ARRAY, int n)
{
    while (!isSorted(ARRAY, n))
    {
        shuffle(ARRAY, n);
    }
}

/*
In selection sort you find a minimal (or maximal) element and put it to top (bottom), then repeat it again for the rest of list.
*/
void SelectionSort(vector<int> &ARRAY)
{

    for (int i = 0; i < ARRAY.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < ARRAY.size(); j++)
        {
            if (ARRAY[j] < ARRAY[minIndex])
            {
                minIndex = j;
            }
        }

        swap(ARRAY[i], ARRAY[minIndex]);
    }
}


