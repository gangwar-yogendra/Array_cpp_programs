/**

Segregate 0s and 1s in an array

You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

**/

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Segregate0sAnd1s(int arr[], int n)
{
	int l = 0;
	int r = n-1;

	while (l < r)
	{
		if (arr[l] == 0)
		{
			l++;
		}
		else if (arr[r] == 1)
		{
			r--;
		}
		else
		{
			if (arr[l] == 1 && arr[l] != arr[r])
			{
				swap(arr[l], arr[r]);
				l++;
				r--;
			}
		}
	}

	std::cout << "Segregated Array: ";
	for (int i = 0;i < n;i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = { 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Segregate0sAnd1s(arr, size);

	return 0;
}
