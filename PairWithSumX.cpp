/** 
Given an array A[] and a number x, check for pair in A[] with sum as x

Write a program that, given an array A[] of n numbers and another number x, 
determines whether or not there exist two elements in S whose sum is exactly x.
Examples:

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3 ,1
Explanation: If we calculate the sum,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
Explanation: No valid pair exists

Solution:
    1. With complexity O(nlogn)
    2. With complexity O(n)
**/

#include <iostream>
#include <algorithm>
#include <unordered_set>


/**
    * 1. With complexity O(nlogn)
    * This will return true pairs of array which has
    * sum equal to 15
*/
bool hasPairWith_nLogn_Complexity(int arr[], int n, int sum)
{
    /* Sort the array */
    std::sort(arr, arr + n);

    int start = 0;
    int end = n-1;

    while(start < end)
    {
        if( (arr[start] + arr[end]) == sum)
        {
            return true; /* Return true */
        }
        else if ( (arr[start] + arr[end]) > sum)
        {
            end--;
        }
        else /*  if ( (arr[start] + arr[end]) < sum) */ 
        {
            start++;
        }
    }
    
    return false; /* Return false */
}

/**
    * 2. With complexity O(n)
    * This will print all the pairs of array which has
    * sum equal to 15
*/
void hasPairWith_n_Complexity(int arr[], int n, int sum)
{
    std::unordered_set<int> myset;
    
    for(int i = 0; i<n; i++)
    {
        int subsum = sum - arr[i];
        if(subsum > 0 && myset.find(subsum) != myset.end())
        {
            std::cout<<"( "<<subsum<<", "<<arr[i]<<" )\n";
        }
        myset.insert(arr[i]);
    }
}

int main(int argc, char **argv)
{
    /* Array List */
    int arr[] = {3, 6, 7, 8, 9, 10};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    
    int sum = 15;
    
    if(hasPairWith_nLogn_Complexity(arr, arrSize, sum))
    {
        std::cout<<"Output using complexity of O(nLogn): Pair exist.\n";
    }
    else
    {
        std::cout<<"Output using complexity of O(nLogn): Pair does not exist\n";
    }

    std::cout<<"Output using complexity of O(n):-\n";
    hasPairWith_n_Complexity(arr, arrSize, sum);
     
    return 0;
}
