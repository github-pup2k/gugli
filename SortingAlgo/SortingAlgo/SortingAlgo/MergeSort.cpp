#include "pch.h"
#include "MergeSort.h"

template <class Type>
MergeSort<Type>::MergeSort()
{
}

template <class Type>
MergeSort<Type>::~MergeSort()
{
}


template <class Type>
void MergeSort<Type>::Sort(vector<Type> &vec)
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
void MergeSort<Type>::SubSort(vector<Type> &vec, size_t lo, size_t hi)
{
	if (hi <= lo) 
		return;

	size_t mid = lo + (hi - lo) / 2;

	// Divide and Conquer
	SubSort(vec, lo, mid);
	SubSort(vec, mid + 1, hi);

	//optimization: stop to devide further if already sorted.
	if (vec[mid] < vec[mid + 1])
		return;

	//Merg the sorted sub parts
	Merge(vec, lo, mid, hi);
}

template <class Type>
void MergeSort<Type>::Merge(vector<Type> &vec, size_t lo, size_t mid, size_t hi)
{
	aux_ = vec;

	size_t leftpart = lo, rightpart = mid + 1;

	for (size_t k = lo; k <= hi; k++)
	{
		//left part is finished then copy the right part
		if (leftpart > mid)
			vec[k++] = aux_[rightpart++];

		// right part is finished then copy the left part
		else if (rightpart > hi)
			vec[k] = aux_[leftpart++];

		//move the lowest element
		else if (aux_[leftpart] < aux_[rightpart])
		{
			BaseSort<Type>::NoOfComparisons_++;
			vec[k] = aux_[leftpart++];
		}
		else
		{
			BaseSort<Type>::NoOfComparisons_++;
			vec[k] = aux_[rightpart++];
		}
	}
}
