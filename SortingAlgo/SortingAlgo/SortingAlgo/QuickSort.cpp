#include "pch.h"
#include "QuickSort.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

template <class Type>
QuickSort<Type>::QuickSort()
{
}

template <class Type>
QuickSort<Type>::~QuickSort()
{
}


template <class Type>
void QuickSort<Type>::Sort(vector<Type> &vec)
{
	try
	{
		SubSort(vec, 0, vec.size() - 1);
	}
	catch (std::out_of_range&)
	{
	}
}

template <class Type>
size_t QuickSort<Type>::Partition(vector<Type> &vec, int lo, int hi)
{
	int i = lo + 1;
	int j = hi;

	while (true)
	{
		//Find the element greater than pivot and break the loop
		while (vec[i] < vec[lo])
		{
			BaseSort<Type>::NoOfComparisons_++;
			i++;
			if (i >= hi) break;
		}

		//Find the element lesser than pivot and break the loop
		while (vec[j] > vec[lo])
		{
			BaseSort<Type>::NoOfComparisons_++;
			j--;
			if (j <= lo) break;
		}

		//Pointer are crossed so break the outer loop
		if (i >= j)
			break;

		BaseSort<Type>::Exchange(vec, i, j);

	}

	BaseSort<Type>::Exchange(vec, lo, j);

	return j;
}


template <class Type>
void QuickSort<Type>::SubSort(vector<Type> &vec, int lo, int hi)
{
	if (hi <= lo) 
		return;

	int partIndex = Partition(vec, lo, hi);
	
	SubSort(vec, lo, partIndex - 1);
	SubSort(vec, partIndex + 1, hi);
}