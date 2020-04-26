/*

Count number of occurrences (or frequency) in a sorted array

Given a sorted array arr[] and a number x, write a function that
counts the occurrences of x in arr[]. Expected time complexity is O(Logn)

Examples:

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
  Output: 4 // x (or 2) occurs 4 times in arr[]

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
  Output: 1 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1
  Output: 2 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 4
  Output: -1 // 4 doesn't occur in arr[] 
*/

#include <iostream>

using namespace std;

int firstIndex(int arr[], int low, int high, int x)
{
	int index = -1;

	while (high >= low) 
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) 	
		{
			index = mid;
			high = mid - 1;
		}
		else if (arr[mid] > x) 
		{
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return index;
}

int lastIndex(int arr[], int low, int high, int x)
{
	int index = -1;

	while (high >= low) 
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) 
		{
			index = mid;
			low = mid + 1;
		}
		else if (arr[mid] > x) 
		{
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return index;
}

int frequencyOfNumber(int arr[], int n, int x)
{
	int first = firstIndex(arr, 0, n - 1, x);
	cout << "lower index: " << first << "\n";
	int last = lastIndex(arr, 0, n - 1, x);
	cout << "higher index: " << last << "\n";

	return (last - first + 1);
}

int main() 
{
	int arr[] = { 1, 3, 5, 5, 5, 5 ,67, 123, 125 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int x = 5;

	cout << "Frequency of number: " << frequencyOfNumber(arr, size, x)<<"\n";
	

	return 0;
}

