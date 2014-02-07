#include <stdio.h>
#include <stdlib.h>
//#include <iomanip.h>

void printArray(int *);
void selection(int *);
void insertion(int *);
void bubble(int *);
void shell(int *);
void randArray(int, int*);
void testSelectionSort(void);
void testInsertionSort(void);
void testBubbleSort(void);
void testShellSort(void);

static int SEED = 12;
static int selectionComp = 0;
static int insertionComp = 0;
static int bubbleComp = 0;
static int shellComp = 0;

void main()
{
	testSelectionSort();
	testInsertionSort();
	testBubbleSort();
	testShellSort();
}

void randArray(int seed, int *a)
{
	int count;
	srand(seed);
	for(count = 0; count < 20; count++)
	{
		a[count] = (rand()%20)+1;
	}
}

void printArray(int *a)
{
	int count;
	for(count = 0; count < 20; count++)
	{
		printf("%d ", a[count]);
	}

	printf("\n");
}

void selection(int *a)
{
	int i, j;
	int min, temp;
	selectionComp = 0;

	for(i = 0; i < 19; i++)
	{
		min = i;
		for(j = i+1; j < 20; j++)
		{
			selectionComp++;
			if(a[j] < a[min])
			{
				min = j;
			}
		}

		if(min != i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
		printArray(a);
	}
}

void insertion(int *a)
{
	int i, j, index;
	insertionComp = 0;

	for(i = 1; i < 20; i++)
	{
		index = a[i];
		j = i;

		while((j > 0) && (a[j-1] > index))
		{
			insertionComp++;
			a[j] = a[j-1];
			j--;
		}

		a[j] = index;
		printArray(a);
	}
}

void bubble(int *a)
{
	int i, j, temp;
	bubbleComp = 0;

	for(i = 19; i >= 0; i--)
	{
		for(j = 1; j <= i; j++)
		{
			bubbleComp++;
			if(a[j-1] > a[j])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}

		printArray(a);
	}
}

void shell(int *a)
{
	int i, j, h, temp, subtract;

	h = 8;
	subtract = 5;
	shellComp = 0;

	while(h > 0)
	{
		printf("(h = %d)  ", h);
		for(i = 0; i < 20; i++)
		{
			j = i;
			temp = a[i];

			while((j >= h) && (a[j-h] > temp))
			{
				shellComp++;
				a[j] = a[j-h];
				j = j - h;
			}

			a[j] = temp;
		}

		subtract--;

		if((h - subtract) > 0)
		{
			h = h - subtract;
		}

		else if(h == 1)
		{
			h = 0;
		}

		else
		{
			h = 1;
		}

		printArray(a);
	}
}

void testSelectionSort(void)
{
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	printf("Arrays before sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("Selection Sort of A:\n");
	selection(A);
	printf("\tComparisons: %d\n", selectionComp);
	printf("Selection Sort of B:\n");
	selection(B);
	printf("\tComparisons: %d\n", selectionComp);
	printf("Selection Sort of C:\n");
	selection(C);
	printf("\tComparisons: %d\n", selectionComp);
	printf("Arrays after sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("\n");
}

void testInsertionSort(void)
{
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	printf("Arrays before sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("Insertion Sort of A:\n");
	insertion(A);
	printf("\tComparisons: %d\n", insertionComp);
	printf("Insertion Sort of B:\n");
	insertion(B);
	printf("\tComparisons: %d\n", insertionComp);
	printf("Insertion Sort of C:\n");
	insertion(C);
	printf("\tComparisons: %d\n", insertionComp);
	printf("Arrays after sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("\n");
}

void testBubbleSort(void)
{
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	printf("Arrays before sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("Bubble Sort of A:\n");
	bubble(A);
	printf("\tComparisons: %d\n", bubbleComp);
	printf("Bubble Sort of B:\n");
	bubble(B);
	printf("\tComparisons: %d\n", bubbleComp);
	printf("Bubble Sort of C:\n");
	bubble(C);
	printf("\tComparisons: %d\n", bubbleComp);
	printf("Arrays after sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("\n");
}

void testShellSort(void)
{
	int A[20] = {1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int B[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int C[20];
	randArray(SEED, C);
	printf("Arrays before sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("Shell Sort of A:\n");
	shell(A);
	printf("\tComparisons: %d\n", shellComp);
	printf("Shell Sort of B:\n");
	shell(B);
	printf("\tComparisons: %d\n", shellComp);
	printf("Shell Sort of C:\n");
	shell(C);
	printf("\tComparisons: %d\n", shellComp);
	printf("Arrays after sort:\n");
	printf("A: ");
	printArray(A);
	printf("B: ");
	printArray(B);
	printf("C: ");
	printArray(C);
	printf("\n");
}

