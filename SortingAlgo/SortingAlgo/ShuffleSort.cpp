#include "pch.h"
#include "ShuffleSort.h"
#include <cstdlib>   // for srand and rand

template <class Type>
ShuffleSort<Type>::ShuffleSort()
{
}

template <class Type>
ShuffleSort<Type>::~ShuffleSort()
{
}

template <class Type>
void ShuffleSort<Type>::Sort(vector<Type> &vec)
{
	try
	{
		size_t size = vec.size();
		for (size_t i = 0; i < size; i++)
		{
			int r = rand() % vec.size();
			BaseSort<Type>::Exchange(vec, i, r);
		}
	}
	catch (std::out_of_range&)
	{
	}
}
