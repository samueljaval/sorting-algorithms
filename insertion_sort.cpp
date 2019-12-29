#include <vector>
#include <iostream>
using namespace std;


void vshow(vector<int> v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Average O(n^2) time, O(1) space
vector<int> insertionSort(vector<int> array)
{
	for (int i = 0 ; i < array.size()-1; i++)
    {
		if (array[i+1] < array[i])
        {
			swap(&array[i], &array[i+1]);
			for (int j = i; j > 0; j--)
            {
				if (array[j-1] > array[j]) swap(&array[j], &array[j-1]);
			}
		}
	}
	return array;
}

int main()
{
    // has to be run with C++11 or later version
	 std::vector<int> v = {-4, 5,  10, 8,  -10, -6, -4, -2, -5, 3,
                            5,  -4, -5, -1, 1,   6,  -7, -6, -7, 8};
	 vshow(insertionSort(v));
	 return 0;
}
