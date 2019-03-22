#pragma once

#ifndef _INSERTIONSORT_H
#define _INSERTIONSORT_H

#include "BaseSort.h"

template <class Type>

class InsertionSort : public BaseSort<Type>
{
public:
	InsertionSort();
	~InsertionSort();

	void Sort(vector<Type> &vec) override;
};

#include "InsertionSort.cpp"



#endif //_INSERTIONSORT_H
