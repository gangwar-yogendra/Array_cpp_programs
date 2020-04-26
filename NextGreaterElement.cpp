/*

Next Greater Element

Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element 
on the right side of x in array. Elements for which no greater element 
exist, consider next greater element as -1.

Examples:

    For any array, rightmost element always has next greater element as -1.
    For an array which is sorted in decreasing order, all elements have next greater element as -1.
    For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.
Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
*/

#include <iostream>
#include <stack>

using namespace std;

void nextGreaterElement(int arr[], int n)
{
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		if (s.empty())
		{
			s.push(arr[i]);
		}
		else
		{
			while (s.empty() == false && s.top() < arr[i])
			{
				cout << "NGE: " << s.top() << " --> " << arr[i]<<"\n";
				s.pop();
			}

			s.push(arr[i]);
		}
	}

	while (s.empty() == false) {
		cout << "NGE: " << s.top() << " --> " << -1 << "\n";
		s.pop();
	}
}

int main()
{
	int arr[] = { 5,3,2,10,6,8,1,4,12,7,4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	nextGreaterElement(arr, size);

	return 0;
}
