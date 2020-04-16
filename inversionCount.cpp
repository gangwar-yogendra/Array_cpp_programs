/* Count Inversions in an array (Using Merge Sort) 
   Reference: https://www.youtube.com/watch?v=owZhw-A0yWE
*/

#include <iostream>

int count = 0;

int merge(int arr[], int p, int q, int r)
{
	int count = 0;
	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[p + i];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = arr[q + 1 + i];
	}

	std::cout << "L Array:			R Array\n";
	for (int i = 0; i < n1; i++)
	{
		std::cout << L[i] << " ";
	}
	std::cout << "				";

	for (int i = 0; i < n2; i++)
	{
		std::cout << R[i] << " ";
	}
	std::cout << "\n";

	int i = 0;
	int j = 0;
	int k = p;
  
	while (i < n1 && j < n2)
	{
		if (L[i] > R[j])
		{	
			arr[k] = R[j];
			j++;
			k++;

			if (i != n1-1)
			{
				count += (n1 - i);
			}
			else
			{
				count++;
			}
		}
		else
		{
			arr[k] = L[i];
			i++;
			k++;
		}
	}

	// Copy the remaining elements
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;

	return count;
}

void mergeSort(int arr[], int l, int r) {
	
	if (r > l) {
		int mid = l + (r - l) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);

		count += merge(arr, l, mid, r);
	}	
}

int main()
{
	int arr[] = { 1, 20, 6, 7, 5, 8, 11, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Given Array: \n";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	mergeSort(arr, 0, size - 1);

	std::cout << "Inversion count: " << count << "\n";

	return 0;
}
