/*

Segregate Even and Odd numbers

Given an array A[], write a function that segregates even and odd numbers. 
The functions should put all even numbers first, and then odd numbers.

Example:

Input  = {12, 34, 45, 9, 8, 90, 3}
Output = {12, 34, 8, 90, 45, 9, 3}

In the output, the order of numbers can be changed, i.e., in the above example, 34 can come before 12 and 3 can come before 9.
*/

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void segregateEvenAndOdd(int arr[], int l, int r)
{
    while (l < r)
    {
        /* if number is even */
        if (arr[l]%2 == 0)
        {
            l++;
        }
        else if (arr[r]%2 != 0) /* if number is odd */
        {
            r--;
        }
        else
        {
            if (arr[l] != arr[r] && (arr[l]%2 != 0))
            {
                swap(arr[l], arr[r]);
                l++;
                r--;
            }
        }
    }
}

int main()
{
    int arr[] = { 12, 34, 45, 9, 8, 90, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array List: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    segregateEvenAndOdd(arr, 0, n-1);

    cout << "\nArray List After Segregate: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
