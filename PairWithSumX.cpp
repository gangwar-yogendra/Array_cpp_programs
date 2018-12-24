/**
    * Given an array A[] and a number x, check for pair in A[] with sum as x
    * Write a program that, given an array A[] of n numbers and another number x, 
    * determines whether or not there exist two elements in S whose sum is exactly x.
    * This solution has complexity O(nlogn)
    * You can improve complexity using hash table till O(n)
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

/**
    * This will print all the
    * Pairs of array which has
    * sum equal to 15
*/
void HasPairImprove(int arr[], int n, int sum)
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


/**
    * This will return true
    * Pairs of array which has
    * sum equal to 15
*/
bool hasPair(int arr[], int n, int sum)
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

int main(int argc, char **argv)
{
    /* Array List */
    int arr[] = {3, 6, 7, 8, 9, 10};

    int arrSize = sizeof(arr)/sizeof(arr[0]);
    
    // Given Sum
    int sum = 15;
    
    if(hasPair(arr, arrSize, sum))
    {
        std::cout<<"Pair exist\n";
    }
    else
    {
        std::cout<<"Pair does not exist\n";
    }

    std::cout<<"This output with complexity of O(n):-\n";
    HasPairImprove(arr, arrSize, sum);
     
    return 0;
}
