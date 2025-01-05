#include <iostream>
#include <random>
using namespace std;
int size;
// cout //cin size size will be size of dynamic arr

void gnomeSort(int *arr = new int[10000])
{
    int i = 0;
    int n =100000;
    while (i < n)
    {
        if ((i == 0) or arr[i - 1] <= arr[i])
            i++;
        else
        {
            int temp = arr[i];
            arr[i] = arr[i - 1]; // can just swap method for this
            arr[i - 1] = temp;
            i--;
        }
    }
}

int main()
{
    int *arr = new int[100000];

    for (int i = 0; i < 100000; i++)
    {
        int randomNums = rand() % 100000;
        arr[i] = randomNums;
    };

    for (int i = 0; i < 100000; i++)
    {
        cout << arr[i] << " ";
    };

    cout << "------------------------------------------------" << endl;
    gnomeSort(arr);

    for (int i = 0; i < 100000; i++)
    {
        cout << arr[i] << " ";
    };

    return 0;
}