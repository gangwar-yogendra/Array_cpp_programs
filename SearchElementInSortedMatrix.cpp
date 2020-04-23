/*

Search in a row wise and column wise sorted matrix

Given an n x n matrix and a number x, find the position of x 
in the matrix if it is present in it. Otherwise, print “Not Found”. 
In the given matrix, every row and column is sorted in increasing order. 
The designed algorithm should have linear time complexity.

Example:

Input: mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output: Found at (2, 1)
Explanation: Element at (2,1) is 29

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 100
Output : Element not found
Explanation: Element 100 is not found

*/

#include <iostream>

using namespace std;

#define RC 4

int search(int arr[RC][RC], int n, int value)
{
    if (value < arr[0][0] && value > arr[n - 1][n - 1])
    {
        return -1;
    }

    int i = 0;
    int j = n - 1;

    while (i < n && j >= 0)
    {
        if (arr[i][j] == value)
        {
            cout << "Index (" << i << ", " << j << ")\n";
            return 0;
        }

        if (arr[i][j] > value)
        {
            j--;
        }
        else // if mat[i][j] < value 
        {
            i++;
        }
    }

    cout << "\n Element not found\n";
    return 0;
}

int main()
{
    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };

    int x = 29;

    search(mat, RC, x);

    return 0;
}
