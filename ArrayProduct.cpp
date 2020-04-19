/*

A Product Array Puzzle

Given an array arr[] of n integers, construct a Product Array prod[] 
(of same size) such that prod[i] is equal to the product of all the 
elements of arr[] except arr[i]. Solve it without division operator in O(n) time.

Example :

Input: arr[]  = {10, 3, 5, 6, 2}
Output: prod[]  = {180, 600, 360, 300, 900}

Explanation: product array should be {180, 600, 360, 300, 900}
3 * 5 * 6 * 2 product of other array elements except 10 is 180
10 * 5 * 6 * 2 product of other array elements except 3 is 600
10 * 3 * 6 * 2 product of other array elements except 5 is 360
10 * 3 * 5 * 2 product of other array elements except 6 is 300
10 * 3 * 6 * 5 product of other array elements except 2 is 900


Input: arr[]  = {1, 2, 3, 4, 5}
Output: prod[]  = {120, 60, 40, 30, 24 }

Explanation: product array should be {120, 60, 40, 30, 24 }
2 * 3 * 4 * 5  product of other array elements except 1 is 120
1 * 3 * 4 * 5  product of other array elements except 2 is 60
1 * 2 * 4 * 5  product of other array elements except 3 is 40
1 * 2 * 3 * 5  product of other array elements except 4 is 30
1 * 2 * 3 * 4  product of other array elements except 5 is 24

Use property of log to multiply large numbers
x = a * b * c * d
log(x) = log(a * b * c * d)
log(x) = log(a) + log(b) + log(c) + log(d)
x = antilog(log(a) + log(b) + log(c) + log(d))

*/

#include <iostream>
#include <math.h>

using namespace std;

int antiLog(long double num)
{
    int x = pow(10.00, num);

    return x;
}

void arrayProduct(int arr[], int n)
{
    long double logP = 0.0;
    int* pArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        logP += log10(arr[i]);
    }

    cout << "\nlog sum of all array element: " << logP << "\n";

    for (int i = 0; i < n; i++)
    {
        arr[i] = antiLog(logP - log10(arr[i]));
    }

    cout << "Product Array List: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array List: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    arrayProduct(arr, n);

    return 0;
}
