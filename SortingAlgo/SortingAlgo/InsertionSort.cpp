#include "pch.h"
#include "InsertionSort.h"

template <class Type>
InsertionSort<Type>::InsertionSort()
{
}

template <class Type>
InsertionSort<Type>::~InsertionSort()
{
}

template <class Type>
void InsertionSort<Type>::Sort(vector<Type> &vec)
{
	try
	{
		size_t size = vec.size();
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = i; j >= 0; j--)
			{
				if ((j > 0) && (vec[j] < vec[j-1]))
					BaseSort<Type>::Exchange(vec, j, j-1);
				else
					break;
			}
		}
	}
	catch (std::out_of_range&)
	{
	}
}
