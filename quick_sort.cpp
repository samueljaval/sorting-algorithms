#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>* v)
{
    for (int i = 0; i < (*v).size(); i++) cout << v->at(i) << endl;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//helper function to put an element at the right place in the list
int helper(vector<int>* array, int low, int high)
{
    int initial_low = low;
    int pivot = array->at(initial_low);
    low = low + 1;
    while (low <= high)
    {
        while (array->at(high) >= pivot && low <= high) high--;
        while (array->at(low) <= pivot && low <= high) low++;
        if (low <= high) swap(&array->at(high), &array->at(low));
    }
    swap(&array->at(initial_low), &array->at(high));
    return high;
}

//Average O(nlog(n)) time, O(log(n)) space
void quickSort(vector<int>* array, int low, int high)
{
    if (low < high)
    {
        int divide_array = helper(array, low, high);
        quickSort(array, low, divide_array - 1);
        quickSort(array, divide_array + 1, high);
    }
}

int main()
{
    // has to be run with C++11 or later version
    std::vector<int> v = {2, 50,  10, 8,  -10, -6, -4, -2, -5, 3,
                            5,  -4, -5, -1, 1,   6,  -7, -6, -7, 8};
    vector<int>* point_v = &v;
    quickSort(point_v,0,v.size()-1);
    print_vector(point_v);
    return 0;
}
