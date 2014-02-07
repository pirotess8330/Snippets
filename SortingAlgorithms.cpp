// Include necessary libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
// Using standard IO
using namespace std;

// Function prototypes
void printArray(int *);
void selection(int *);
void insertion(int *);
void bubble(int *);
void shell(int *, int *);
void randArray(int, int*);
void testSelectionSort(void);
void testInsertionSort(void);
void testBubbleSort(void);
void testShellSort(void);

// Variables to be used throughout the program
static int SEED = 12;
static int selectionComp = 0;
static int insertionComp = 0;
static int bubbleComp = 0;
static int shellComp = 0;

// Main function which executes test methods.
void main()
{
	testSelectionSort();
	testInsertionSort();
	testBubbleSort();
	testShellSort();
}

// Function to populate arrays of length 20 with pseudo-random values
// from 1 to 20.
// Parameters:
//		seed - The seed for the srand() function.
//		a - A reference to the array to populate.
void randArray(int seed, int *a)
{
	int count;
	srand(seed);
	for(count = 0; count < 20; count++)
	{
		a[count] = (rand()%20)+1;
	}
}

// Function to print the contents of an array of length 20 with a
// space between each number for better readability.
// Parameter:
//		a - A reference to the array to print.
void printArray(int *a)
{
	int count;
	for(count = 0; count < 20; count++)
	{
		cout << a[count] << " ";
	}

	cout << endl;
}

// Function which implements selection sort.
// Parameter:
//		a - A reference to the array to sort.
void selection(int *a)
{
	// Variables to use in function
	int i, j;
	int min, temp;
	// Make sure the comparison counter is set to zero in case this
	// function was already called.
	selectionComp = 0;

	// Loop through each element of the array looking for the minimum.
	for(i = 0; i < 19; i++)
	{
		min = i;
		// Compare the ith element with all others in the array,
		// looking for minimum.
		for(j = i+1; j < 20; j++)
		{
			// Increment the comparison counter.
			selectionComp++;
			// Find the minimum element.
			if(a[j] < a[min])
			{
				min = j;
			}
		}

		if(min != i)
		{
			// Swap
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
		// Print the contents of the array after each iteration
		// of outer for loop.
		printArray(a);
	}
}

// Function which implements insertion sort.
// Parameter:
//		a - A reference to the array to sort.
void insertion(int *a)
{
	int i, j, index;
	// Make sure the comparison counter is set to zero in case this
	// function was already called.
	insertionComp = 0;

	// Loop through each element for placement in the sorted sublist.
	for(i = 1; i < 20; i++)
	{
		index = a[i];
		j = i;

		// Find the correct place in the sublist.
		while((j > 0) && (a[j-1] > index))
		{
			// Increment the comparison counter.
			insertionComp++;
			a[j] = a[j-1];
			j--;
		}

		a[j] = index;
		// Print the contents of the array after each iteration
		// of outer for loop.
		printArray(a);
	}
}

// Function which implements bubble sort.
// Parameter:
//		a - A reference to the array to sort.
void bubble(int *a)
{
	int i, j, temp;
	// Make sure the comparison counter is set to zero in case this
	// function was already called.
	bubbleComp = 0;

	// Loop through to find max element to bubble up.
	for(i = 19; i >= 0; i--)
	{
		// Compare the ith element with all others.
		for(j = 1; j <= i; j++)
		{
			// Increment the comparison counter.
			bubbleComp++;
			if(a[j-1] > a[j])
			{
				// Swap
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
		// Print the contents of the array after each iteration
		// of outer for loop.
		printArray(a);
	}
}

// Function which implements shell sort.
// Parameter:
//		a - A reference to the array to sort.
//		h - A reference to an array containing partition numbers.
void shell(int *a, int * h)
{
	int i, j, temp, index, val;

	index = 0;
	// Make sure the comparison counter is set to zero in case this
	// function was already called.
	shellComp = 0;
	// Initialize val to the first partition value.
	val = h[index];

	// While the partition values have not yet completed.
	while(val > 0)
	{
		// Print the current partition value.
		cout << "(h = " << val << ") ";
		// Insertion sort for each partition value.
		for(i = 0; i < 20; i++)
		{
			j = i;
			temp = a[i];

			while((j >= val) && (a[j-val] > temp))
			{
				// Increment the comparison counter.
				shellComp++;
				a[j] = a[j-val];
				j = j - val;
			}

			a[j] = temp;
		}

		// Check if the partition value is 1.
		// If it is 1, the last iteration is complete.
		// If it is not 1, there are still more partitions to go through.
		if(val != 1)
		{
			// Set val to the next partition value
			val = h[++index];
		}

		// Set val to zero, so while loop will terminate.
		else
		{
			val = 0;
		}
		// Print the contents of the array after each iteration
		// of outer for loop.
		printArray(a);
	}
}

// Function to test the selection sort function.
// Easier to read in main().
void testSelectionSort(void)
{
	// Initialize the arrays.
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	// Print the arrays before the sort.
	cout << "Arrays before sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	// Print the arrays before the sort.
	cout << "Selection Sort of A:\n";
	selection(A);
	cout << "\tComparisons: " << selectionComp << endl;
	cout << "Selection Sort of B:\n";
	selection(B);
	cout << "\tComparisons: " << selectionComp << endl;
	cout << "Selection Sort of C:\n";
	selection(C);
	cout << "\tComparisons: " << selectionComp << endl;
	// Print the arrays after the sort.
	cout << "Arrays after sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	cout << endl;
}

// Function to test the insertion sort function.
// Easier to read in main().
void testInsertionSort(void)
{
	// Initialize the arrays.
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	// Print the arrays before the sort.
	cout << "Arrays before sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	// Print the arrays before the sort.
	cout << "Insertion Sort of A:\n";
	insertion(A);
	cout << "\tComparisons: " << insertionComp << endl;
	cout << "Insertion Sort of B:\n";
	insertion(B);
	cout << "\tComparisons: " << insertionComp << endl;
	cout << "Insertion Sort of C:\n";
	insertion(C);
	cout << "\tComparisons: " << insertionComp << endl;
	// Print the arrays after the sort.
	cout << "Arrays after sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	cout << endl;
}

// Function to test the bubble sort function.
// Easier to read in main().
void testBubbleSort(void)
{
	// Initialize the arrays.
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	// Print the arrays before the sort.
	cout << "Arrays before sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	// Print the arrays before the sort.
	cout << "Bubble Sort of A:\n";
	bubble(A);
	cout << "\tComparisons: " << bubbleComp << endl;
	cout << "Bubble Sort of B:\n";
	bubble(B);
	cout << "\tComparisons: " << bubbleComp << endl;
	cout << "Bubble Sort of C:\n";
	bubble(C);
	cout << "\tComparisons: " << bubbleComp << endl;
	// Print the arrays after the sort.
	cout << "Arrays after sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	cout << endl;
}

// Function to test the shell sort function.
// Easier to read in main().
void testShellSort(void)
{
	// Initialize the arrays.
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	// Set the partition values.
	int h[3] = {8, 4, 1};
	// Print the arrays before the sort.
	cout << "Arrays before sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	// Print the arrays before the sort.
	cout << "Shell Sort of A:\n";
	shell(A, h);
	cout << "\tComparisons: " << shellComp << endl;
	cout << "Shell Sort of B:\n";
	shell(B, h);
	cout << "\tComparisons: " << shellComp << endl;
	cout << "Shell Sort of C:\n";
	shell(C, h);
	cout << "\tComparisons: " << shellComp << endl;
	// Print the arrays after the sort.
	cout << "Arrays after sort:\n";
	cout << "A: ";
	printArray(A);
	cout << "B: ";
	printArray(B);
	cout << "C: ";
	printArray(C);
	cout << endl;
}

