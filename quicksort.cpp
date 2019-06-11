#include <iostream>

using namespace std; 

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	// set arr[high] as pivot
    int pivot = arr[high];					
    int i = low - 1;		
  
  	// For all values except pivot, move all smaller values to [low]...[i]
    for (int j = low; j <= high - 1; j++)   
    { 
		// if arr[j] is smaller than pivot
        if (arr[j] <= pivot) 	
        { 
			// prepare new position which is arr[i]
            i++;  				

			// move smaller value(arr[j]) to arr[i]
            swap(&arr[i], &arr[j]); 
        } 
    } 

	// Now, all values in [low, i] are smaller than pivot
	// so move pivot to i + 1
    swap(&arr[i + 1], &arr[high]); 
	
	// ... [i] pivot ....	
    return i + 1;  // return pivot index
} 

void quickSort(int arr[], int low, int high) 
{ 
	// array stack is composed of top index and stack array
	// push : stack[++top]
	// pop  : stack[top--]

	// number of elements for sorting
	int stack[high - low + 1];

	// top index
	int top = -1; 

	// push initial values of low and high to stack 
	stack[++top] = low; 
	stack[++top] = high; 

	// while stack is not empty 
	while (top >= 0) { 
		// Pop high and low
		high = stack[top--]; 
		low = stack[top--]; 

		int pivot = partition(arr, low, high); 

		// If there are more than 2 elements on left side of pivot
		if (pivot - low > 1) { 
			stack[++top] = low; 
			stack[++top] = pivot - 1; 
		} 

		// If there are more than 2 elements on right side of pivot
		if (high - pivot > 1) { 
			stack[++top] = pivot + 1; 
			stack[++top] = high; 
		} 
	} 
} 

void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 }; 
	int n = sizeof(arr) / sizeof(*arr); 

	quickSort(arr, 0, n - 1); 

	printArr(arr, n); 
	return 0; 
}