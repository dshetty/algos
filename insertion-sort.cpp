//============================================================================
// Name        : insertion-sort.cpp
// Author      : Dhiraj Vasudeva Shetty
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int findPos(int arr[], int arrSize, int B, int val)
{
	for (int i = 0; i < B; ++i)
	{
		if (val < arr[i])
		{
			return i;
		}
	}

	//OPT_1 can check if val >= arr[B]
	return B;
}

void resize(int arr[], int arrSize, int B, int pos)
{
	if (pos != B)
	{
		int i = B;

		while (i > pos)
		{
			arr[i] = arr[i-1];
			--i;
		}
	}
}

void insertionSort(int arr[], int arrSize)
{
	int B = 1;
	int val = 0;
	int pos = 0;

	if (0 == arrSize || 1 == arrSize)
	{
		return;
	}

	if (2 == arrSize)
	{
		if (arr[0] < arr[1])
		{
			return;
		}
	}

	while (B < arrSize)
	{
		val = arr[B];
		pos = findPos(arr, arrSize, B, val);
		resize(arr, arrSize, B, pos);
		arr[pos] = val;
		++B;
	}
}

void printArray(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		cout << arr[i] << ", ";
	}

	cout << endl;
}

int main() {
//	int arr[] = {6, 4, 2, 9, 1, 3};
//	int arr[] = {12, 3, 0, 5, 6, 7, 8, 9, 2, 1};
//	int arr[] = {6, 4};
//	int arr[] = {6};
	int arr[] = {1, 2, 3, 4, 5};
	int count = sizeof(arr)/sizeof(int);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "Before Sort" << endl;
	printArray(arr, count);

	insertionSort(arr, count);

	cout << "After Sort" << endl;
	printArray(arr, count);

	return 0;
}
