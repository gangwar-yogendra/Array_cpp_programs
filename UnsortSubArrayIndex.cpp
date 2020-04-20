/*

Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted

Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray
arr[s..e] such that sorting this subarray makes the whole array sorted.

Examples:
1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your 
program should be able to find that the subarray lies between the indexes 3 and 8.

2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should 
be able to find that the subarray lies between the indexes 2 and 5.
*/

#include <iostream>
using namespace std;


void unsortSubArray(int arr[], int l, int r)
{
    int min = INT_MAX;
    int max = INT_MIN;

    int start = 0;
    int end = r;

    for (start = 0; start < r; start++)
    {
        if (arr[start] > arr[start + 1])
            break;
    }
    if (start == r) { cout << "Array is already sorted\n"; return; }

    for (end = r; end >= 0; end--)
    {
        if (arr[end] < arr[end - 1])
            break;
    }

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    for (int i = 0; i < start; i++)
    {
        if (arr[i] > min)
        {
            start = i;
            break;
        }
    }

    for (int i = r; i >= end+1; i--)
    {
        if (arr[i] < max)
        {
            end = i;
            break;
        }
    }

    cout << "The unsorted subarray which"
        << " makes the given array" << endl
        << "sorted lies between the indees "
        << start << " and " << end;
}

int main()
{
    int arr[] = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array List: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    unsortSubArray(arr, 0, n - 1);
    cout << "\n";

    return 0;
}
