#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// this class holds templated sorting algorithms and a binary search
template <typename T>
class SORT
{
public:
    // constructors, not sure if i need the first one tbh
    SORT();
    SORT(T Data);
    T the_Data;
    // virtual function to make different types of arrays, just make a new child class with whatever data type and overide this, feel like this was pointless and over complicated everything
    virtual vector<T> RandomVector() const = 0;

    // sortin algo prototypes and binary search
    bool isSorted(vector<T> &ARRAY, int n);
    void shuffle(vector<T> &ARRAY, int n);
    void bogoSort(vector<T> &ARRAY, int n);

    int BinarySearch(vector<T> ARRAY, T DataUwant, T low, T high);
    int partition(vector<T> &ARRAY, int low, int high);
    void QuickSort(vector<T> &ARRAY, int low, int high);

    void GnomeSort(vector<T> &ARRAY);

    void SelectionSort(vector<T> &ARRAY);

    void print();

    // using templates, have to basically overide every key word in c++ if you want it to work
    template <typename X>
    friend bool operator<(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend bool operator>(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend bool operator>=(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend bool operator<=(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend bool operator==(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend T operator-(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend T operator+(const SORT<X> &Left_Side, const SORT<X> &Right_Side);

    template <typename X>
    friend ostream &operator<<(ostream &COUT, const SORT<X> &Sort);
};

template <typename T>
SORT<T>::SORT(){};

template <typename T>
SORT<T>::SORT(T Data) : the_Data(Data){};

template <typename X>
bool operator<(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data < Right_Side.the_Data;
}

template <typename X>
bool operator>(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data > Right_Side.the_Data;
}

template <typename X>
bool operator>=(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data >= Right_Side.the_Data;
}

template <typename X>
bool operator<=(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data <= Right_Side.the_Data;
}

template <typename X>
bool operator==(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data == Right_Side.the_Data;
}

template <typename X>
X operator-(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data + Right_Side.the_Data;
}

template <typename X>
X operator+(const SORT<X> &Left_Side, const SORT<X> &Right_Side)
{
    return Left_Side.the_Data - Right_Side.the_Data;
}

template <typename X>
ostream &operator<<(ostream &COUT, const SORT<X> &Sort)
{
    COUT << "the data" << Sort.the_Data << " ";
    return COUT;
}

template <typename T>
void SORT<T>::print()
{
    cout << the_Data << " ";
}

// Sorting algos below , takes any type

template <typename T>
void SORT<T>::GnomeSort(vector<T> &ARRAY)
{
    int index = 0;
    int n = ARRAY.size();

    while (index < n)
    {
        if (index == 0 or ARRAY[index] >= ARRAY[index - 1])
        {
            index++;
        }
        else
        {
            swap(ARRAY[index], ARRAY[index - 1]);
            index--;
        }
    }
}

template <typename T>
int SORT<T>::partition(vector<T> &ARRAY, int low, int high)
{
    T pivot = ARRAY[high];
    int j = low - 1;

    for (int i = low; i <= high - 1; i++)
    {
        if (ARRAY[i] < pivot)
        {
            j++;
            swap(ARRAY[j], ARRAY[i]);
        }
    }

    swap(ARRAY[j + 1], ARRAY[high]);
    return j + 1;
}

template <typename T>
void SORT<T>::QuickSort(vector<T> &ARRAY, int low, int high)
{
    if (low < high)
    {
        int Pivot = partition(ARRAY, low, high);

        QuickSort(ARRAY, low, Pivot - 1);
        QuickSort(ARRAY, Pivot + 1, high);
    }
}

template <typename T>
int SORT<T>::BinarySearch(vector<T> ARRAY, T DataUwant, T low, T high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (ARRAY[mid] == DataUwant)
        {
            return mid;
        }

        if (ARRAY[mid] > DataUwant)
        {
            return BinarySearch(ARRAY, DataUwant, low, high - 1);
        }

        else
        {
            return BinarySearch(ARRAY, DataUwant, mid + 1, high);
        }
    }
    return -1;
}

template <typename T>
bool SORT<T>::isSorted(vector<T> &ARRAY, int n)
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

template <typename T>
void SORT<T>::shuffle(vector<T> &ARRAY, int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(ARRAY[i], ARRAY[rand() % n]);
    }
}

template <typename T>
void SORT<T>::bogoSort(vector<T> &ARRAY, int n)
{
    while (!isSorted(ARRAY, n))
    {
        shuffle(ARRAY, n);
    }
}

template <typename T>
void SORT<T>::SelectionSort(vector<T> &ARRAY)
{
    int minIndex;
    for (int i = 0; i < ARRAY.size() - 1; i++)
    {
        minIndex = i;

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

// child classes down below all essentially the same execpt for how I implment the pseudo randomness
class intDATA : public SORT<int>
{
private:
    vector<int> data;

public:
    intDATA(const vector<int> &DATA) : data(DATA) {};

    vector<int> RandomVector() const override
    {
        vector<int> randomInt(data.size());
        int randomNumbers = 0;
        for (int i = 0; i < data.size(); i++)
        {
            randomNumbers = rand() % 25;
            randomInt[i] = randomNumbers;
        }
        return randomInt;
    }
};

class DoubleDATA : public SORT<double>
{
private:
    vector<double> data;

public:
    DoubleDATA(const vector<double> &DATA) : data(DATA) {};

    vector<double> RandomVector() const override
    {
        srand(time(0));
        vector<double> randomDouble(data.size());

        for (int i = 0; i < data.size(); i++)
        {

            double randomNumbers = (double)rand() / RAND_MAX * 10;
            randomNumbers = floor(randomNumbers * 100.0) / 10.0;
            randomDouble[i] = randomNumbers;
        }
        return randomDouble;
    }
};

class CharDATA : public SORT<char>
{
private:
    vector<char> data;

public:
    CharDATA(const vector<char> &DATA) : data(DATA) {};

    vector<char> RandomVector() const override
    {
        vector<char> randomC_String(data.size());
        char randomChars = 'a';
        for (int i = 0; i < data.size(); i++)
        {
            randomChars = 'a' + (rand() % 26);
            randomC_String[i] = randomChars;
        }
        return randomC_String;
    };
};
