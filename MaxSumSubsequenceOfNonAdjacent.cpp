/*
* Maximum sum such that no two elements are adjacent

* Given an array of positive numbers, find the maximum sum of a 
* subsequence with the constraint that no 2 numbers in the sequence 
* should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) 
* or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.

* Examples :

* Input : arr[] = {5, 5, 10, 100, 10, 5}
* Output : 110

* Input : arr[] = {1, 2, 3}
* Output : 4

* Input : arr[] = {1, 20, 3}
* Output : 20
*/

#include <iostream>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int maxSubsequenceSum(int arr[], int n)
{
	int incl = 0;
	int excl = 0;
	int old_incl = 0;
	int i = 0;

	while (i < n)
	{
		old_incl = incl;
		incl = max(old_incl, excl + arr[i]);
		excl = old_incl;
		i++;
	}

	return incl;
}

int main()
{
	int arr[] = { 5,  5, 10, 40, 50, 35 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<maxSubsequenceSum(arr, n);

	return 0;
}
