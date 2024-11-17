#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*

Quick Sort Implementation

1. Select a Pivot (Default last element in array)
2. Partition array around the pivot
	example: [4 6 3 8 9 7 2 1 5] -> [4 3 2 1] [5] [6 8 9 7]
3. Take both sides of the partition and repeat this process for each side on repeat until each sub list is sorted
	[4 3 2 1] [5] [6 8 9 7] -> [1] [4 3 2] [5] [6] [7] [8 9] -> [1] [2] [4 3] [5] [6] [7] [8] [9] -> [1] [2] [3] [4] [5] [6] [7] [8] [9]
4. Merge all the sublist

*/

#define MAXARRAYLENGTH 10

void Swap(int* a, int* b);
void QuickSortHelper(int* array, int low, int high);
void QuickSort(int* array, int length);
int Partition(int* array, int low, int high);
void PrintArray(int* array, int length);
int sortAndFindMMedian(int* numbers, int length);

int main() 
{
	int numbers[] = {-4, -3, -2, -1, -1, -1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 11, 31, 55, 61, 77, 89, 100, 399, 2815};
	int length = sizeof(numbers) / sizeof(int);

	printf("Test Case: ");
	PrintArray(numbers, length);

	printf("Median of numbers: %d\n", sortAndFindMMedian(numbers, length));

	printf("----------------------------------------------------\n");
	int UserNumbers[MAXARRAYLENGTH];
	char LineBuffer[256];

	printf("Enter integers (Max 10) Ex: 6 5 4 3 2 1 9 8 7\n");
	fgets(LineBuffer, sizeof(LineBuffer), stdin);
	char* LineNumbers = strtok(LineBuffer, " \n");
	int LineNumber;

	int i = 0;
	while (LineNumbers != NULL && i < MAXARRAYLENGTH) {
		sscanf(LineNumbers, "%d", &LineNumber);
		UserNumbers[i] = LineNumber;
		i++;
		LineNumbers = strtok(NULL, " \n"); // Get the next line number
	}
	printf("Entered Integers: \n");
	PrintArray(UserNumbers, i);

	printf("Median of Entered Integers: %d\n", sortAndFindMMedian(UserNumbers, i));
	printf("Sorted Integers: \n");
	PrintArray(UserNumbers, i);


	printf("Press Enter to Quit\n");
	int wait = getchar(); // Wait for user input to close terminal

	return 0;
}

void Swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSortHelper(int* array, int low, int high) 
{
	if (low < high) {
		int PivotIndex = Partition(array, low, high);
		QuickSortHelper(array, low, PivotIndex - 1);
		QuickSortHelper(array, PivotIndex + 1, high);
	}
}

void QuickSort(int* array, int length) 
{
	QuickSortHelper(array, 0, length - 1);	
}

int Partition(int* array, int low, int high) 
{
	int Pivot = array[high];

	int SmallestElementIndex = low - 1;
	
	for (int i = low; i < high; i++) {
		if (array[i] < Pivot) {
			SmallestElementIndex++;
			Swap(&array[SmallestElementIndex], &array[i]);
		}
	}
	Swap(&array[SmallestElementIndex + 1], &array[high]);

	return SmallestElementIndex+1;
}

void PrintArray(int* array, int length) 
{
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int sortAndFindMMedian(int* numbers, int length) 
{
	QuickSort(numbers, length);

	if (length % 2 == 0) {
		return ((numbers[length / 2 - 1] + numbers[length / 2]) / 2);
	}
	else {
		return numbers[length / 2];
	}
}