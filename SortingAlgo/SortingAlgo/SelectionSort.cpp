#include "pch.h"
#include "SelectionSort.h"


template <class Type>
SelectionSort<Type>::SelectionSort()
{
}

template <class Type>
SelectionSort<Type>::~SelectionSort()
{
}

template <class Type>
void SelectionSort<Type>::Sort(vector<Type> &vec)
{
	try
	{
		size_t size = vec.size();
		for (size_t i = 0; i < size; i++)
		{
			int min = i;
			for (size_t j = i + 1; j < size; j++)
			{
				if ((j < size) && (vec[j] < vec[min]))
					min = j;
			}
			BaseSort<Type>::Exchange (vec, i, min);
		}
	}
	catch (std::out_of_range&)
	{
	}
}