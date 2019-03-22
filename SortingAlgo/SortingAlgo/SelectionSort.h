#pragma once

#ifndef _SELECTIONSORT_H
#define _SELECTIONSORT_H

#include "BaseSort.h"

using namespace std;

template <class Type>
class SelectionSort : public BaseSort<Type>
{
public:
	SelectionSort();
	~SelectionSort();

	void Sort(vector<Type> &vec) override;
};

#include "SelectionSort.cpp"

#endif //_SELECTIONSORT_H

