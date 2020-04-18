/*

Find the second smallest and highest elements in an array

Write an efficient C program to second smallest and highest element in an array.
*/

#include <iostream>

using namespace std;

int secondHighestNumber(int arr[], int n)
{
	int second = INT_MIN;
	int first = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > first)
		{
			second = first;
			first = arr[i];
		}
		if (arr[i] != first && arr[i] > second)
		{
			second = arr[i];
		}
	}

	return second;
}

int secondSmallestNumber(int arr[], int n)
{
	int second = INT_MAX;
	int first = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < first)
		{
			second = first;
			first = arr[i];
		}
		if (arr[i] != first && arr[i] < second)
		{
			second = arr[i];
		}
	}

	return second;
}

int main()
{
	int arr[] = { 85, 45, 12, 69, 24, 28, 78, 88 };

	int size = sizeof(arr) / sizeof(arr[0]);

	cout<< "Second highest number: "<<secondHighestNumber(arr, size)<<"\n";
	cout << "Second smallest number: "<<secondSmallestNumber(arr, size) << "\n";

	return 0;
}
