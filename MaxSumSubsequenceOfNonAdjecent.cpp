/*
Algo: 
loop(i):
  old_incl = incl;
  incl = max(old_incl, excl + arr[i]);
  excl = old_incl;

Example:
Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
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
