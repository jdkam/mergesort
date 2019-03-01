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
        int mid = (high+low)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, low, mid); //sort first half
        mergeSort(arr, mid+1, high); //sort second half
  
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

	int i = low; //start point 
    int j = mid + 1; //mid point 
    int k =0; //temp index
	int temp[high-low+1]; //where to store sorted array
  

    while (i <= mid && j <= high) //merge arrays in sorted order
    { 
        if (arr[i] <= arr[j]) //if left subarray is less than right
        { 
            temp[k] = arr[i]; //push left subarray element into temp
            i++; 
        } 
        else
        { 
            temp[k] = arr[j]; //push right subarray element into temp
            j++; 
        } 
        k++; 
    } 

  
    while (i <= mid) //push rest of elements of left subarray into temp
    { 
        temp[k] = arr[i]; 
		//cout << "Left subarray last insert: " << L[i] << endl;
        i++; 
        k++; 
    } 
  
 
    while (j <= high) //push rest of elements of right subarray into temp
    { 
        temp[k] = arr[j]; 
		//cout << "Right subarray last insert: " << R[j] << endl;
		k++;  
        j++; 
        
    } 

	for(int i = 0 ; i < (high-low +1); i++)
	{
		arr[i + low] = temp[i];
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
	//cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	int *values;
	values = new int[n];

	for (int i = 0; i < n; i++)
	{
		//cout << "Enter a number:" << endl;
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
