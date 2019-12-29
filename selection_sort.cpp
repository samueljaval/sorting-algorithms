#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

//Average O(n^2) time, O(1) space
vector<int> selectionSort(vector<int> array)
{
    int sublist_index = 0;
    while (sublist_index < array.size()-1)
    {
        int smallest = array[sublist_index];
        int smallest_i = sublist_index;

        for (int i = sublist_index + 1; i < array.size() ; i++)
        {
          if (array[i] < smallest)
          {
              smallest = array[i];
              smallest_i = i;
          }
        }
        swap(&array[sublist_index], &array[smallest_i]);
        sublist_index++;
    }
    return array;
}

int main()
{
    // has to be run with C++11 or later version
    std::vector<int> v = {-4, 50,  10, 8,  -10, -6, -4, -2, -5, 3,
                            5,  -4, -5, -1, 1,   6,  -7, -6, -7, 8};
    print_vector(selectionSort(v));
    return 0;
}
