#pragma once

#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include "BaseSort.h"

template <class Type>
class QuickSort :
	public BaseSort<Type>
{
public:
	QuickSort();
	~QuickSort();

	void Sort(vector<Type> &vec) override;

private:
	void SubSort(vector<Type> &vec, int lo, int hi);
	size_t Partition(vector<Type> &vec, int lo, int hi);

};

#include "QuickSort.cpp"
#endif //_QUICKSORT_H

