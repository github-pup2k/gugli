#pragma once
#ifndef _MERGESORT_H
#define _MERGESORT_H
#include "BaseSort.h"

template <class Type>
class MergeSort : public BaseSort<Type>
{
public:
	MergeSort();
	~MergeSort();

	void Sort(vector<Type> &vec) override;
private:
	void SubSort(vector<Type> &vec, size_t lo, size_t hi);
	void Merge(vector<Type> &vec, size_t lo, size_t mid, size_t hi);
private:
	vector<Type> aux_;
};

#include "MergeSort.cpp"
#endif //_MERGESORT_H

