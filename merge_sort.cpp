#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int mid1, int high);

// Perform mergeSort to sort an array of integers.
// Inputs:
//   arr is the input array of arrSize integers.
//   low and high are the indices to sort to/from, e.g. 0 arrSize-1 to sort entire array
// Postcondition:
//   arr[low] ... arr[high] will contain the original values, sorted in increasing order.
void mergeSort(int arr[], int low, int high)
{
	// TO DO:: Fill in this code.
	if (low < high) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = low+(high-low)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, low, mid); 
        mergeSort(arr, mid+1, high); 
  
        merge(arr, low, mid, mid+1, high); 
    } 

	
}

// Perform a merge of two sorted sub-arrays.
// Inputs:
//   arr is the input array on which to perform a merge.
//   low-mid and mid1-high are the two sub-arrays to merge.
// Precondition:
//   arr[low]...arr[mid] is sorted in increasing order.
//   arr[mid1]...arr[high] is sorted in increasing order.
//   These should be disjoint, contiguous sub-arrays too.
// Postcondition:
//   arr[low]...arr[high] is sorted in increasing.
void merge(int arr[], int low, int mid, int mid1, int high)
{

	int i, j, k; 
    int n1 = mid - low + 1; 
    int n2 =  high - mid; 
	int temp[high-low+1];
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++)
	{
		L[i] = arr[low + i]; 
	} 


    for (j = 0; j < n2; j++) 
	{
		R[j] = arr[mid + 1 + j]; 

	}

    i = 0; 
    j = 0; 
    k = 0; 

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            temp[k] = L[i];
            i++; 
        } 
        else
        { 
            temp[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

  
    while (i < n1) 
    { 
        temp[k] = L[i]; 
		//cout << "Left subarray last insert: " << L[i] << endl;
        i++; 
        k++; 
    } 
  
 
    while (j < n2) 
    { 
        temp[k] = R[j]; 
		//cout << "Right subarray last insert: " << R[j] << endl;
		k++; 
        j++; 
        
    } 

	for(int i = low ; i < (high-low +1); i++)
	{
		arr[i] = temp[i];
		k++;
	}

}

// A driver program to test mergeSort.
// Reads in a number of integers (number, then sequence of values).
// Sorts using mergeSort.
// Prints the values in sorted order.
int main(void)
{
	int n;

	// Get the number of values.
	cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	int *values;
	values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number:" << endl;
		cin >> values[i];
	}
	

	// Call mergeSort to sort entire array.
	mergeSort(values, 0, n - 1);

	// Print values, should be sorted.
	for (int i = 0; i < n; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;

	// Free up memory.  Note use of delete [], since this is an array.
	delete[] values;

	return 0;
}
