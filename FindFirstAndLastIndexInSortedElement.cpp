/*
Find first and last positions of an element in a sorted array

Given a sorted array with possibly duplicate elements, the task 
is to find indexes of first and last occurrences of an element x in the given array.

Examples:

Input : arr[] = {1, 3, 5, 5, 5, 5 ,67, 123, 125}    
        x = 5
Output : First Occurrence = 2
         Last Occurrence = 5

Input : arr[] = {1, 3, 5, 5, 5, 5 ,7, 123 ,125 }    
        x = 7
Output : First Occurrence = 6
         Last Occurrence = 6
*/

#include <iostream>

using namespace std;

int firstIndex(int arr[], int low, int high, int x)
{
	int index = -1;

	while (high >= low) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) 	{
			index = mid;
			high = mid - 1;
		}
		else if (arr[mid] > x) {
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

	while (high >= low) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) {
			index = mid;
			low = mid + 1;
		}
		else if (arr[mid] > x) {
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return index;
}

int main() 
{
	int arr[] = { 1, 3, 5, 5, 5, 5 ,67, 123, 125 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int x = 5;

	int first = firstIndex(arr, 0, size-1, x);
	cout << "lower index: " << first << "\n";
	int last = lastIndex(arr, 0, size-1, x);
	cout << "higher index: " << last << "\n";

	return 0;
}
