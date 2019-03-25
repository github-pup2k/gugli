// SortingAlgo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "BaseSort.h"
#include <memory>

using namespace std;

#include "QuickSort.h"
void FireQuickSort()
{
	unique_ptr< BaseSort<int> > pBaseSort = make_unique< QuickSort<int> >();

	vector<int> ages = { 1, 12, 5, 26, 7, 14, 3, 8, 2 };

	pBaseSort->Sort(ages);

	cout << "Quick sort Comparisons: " << pBaseSort->Comparisons() << endl;
}

#include "MergeSort.h"
void FireMergeSort()
{
	unique_ptr< BaseSort<int> > pBaseSort = make_unique< MergeSort<int> >();

	vector<int> ages = { 1, 12, 5, 26, 7, 14, 3, 8, 2 };

	pBaseSort->Sort(ages);

	cout << "Merge sort Comparisons: " << pBaseSort->Comparisons() << endl;
}


#include "SelectionSort.h"
void FireSelectionSort()
{
	unique_ptr< BaseSort<int> > pBaseSort = make_unique< SelectionSort<int> >();

	vector<int> ages = { 1, 12, 5, 26, 7, 14, 3, 8, 2 };

	pBaseSort->Sort(ages);

	cout << "Selection sort Comparisons: " << pBaseSort->Comparisons() << endl;
}

#include "InsertionSort.h"
void FireInsertionSort()
{
	unique_ptr< BaseSort<int> > pBaseSort = make_unique< InsertionSort<int> >();

	vector<int> ages = { 1, 12, 5, 26, 7, 14, 3, 8, 2 };

	pBaseSort->Sort(ages);

	cout << "Insertion sort Comparisons: " << pBaseSort->Comparisons() << endl;
}

int main()
{ 
	try
	{
		FireSelectionSort();
		FireInsertionSort();
		FireMergeSort();
		FireQuickSort();
	}
	catch (std::bad_alloc& e)
	{
		cout << "Out of memory: " << e.what() << endl;
	}



    std::cout << "Hello World!\n"; 
}

