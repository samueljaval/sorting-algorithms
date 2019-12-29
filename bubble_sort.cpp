#include <vector>
#include <iostream>
using namespace std;

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

//Average O(n^2) time, O(1) space
vector<int> bubbleSort(vector<int> array)
{
	while (true)
    {
		int swapped = 0;
		for (int i = 0 ; i < array.size()-1 ; i++)
        {
			if (array[i] > array[i+1])
            {
                swap(&array[i], &array[i+1]);
				swapped += 1;
			}
		}
		if (swapped == 0) return array;
	}
}

int main()
{
    std::vector<int> v = {-4, 5,  10, 8,  -10, -6, -4, -2, -5, 3,
                        5,  -4, -5, -1, 1,   6,  -7, -6, -7, 8};
    print_vector(bubbleSort(v));
    return 0;
}
