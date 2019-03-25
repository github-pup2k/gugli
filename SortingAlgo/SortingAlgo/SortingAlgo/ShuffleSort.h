#pragma once
#ifndef _SHUFFLESORT_H
#define _SHUFFLESORT_H

#include "BaseSort.h"

template <class Type>
class ShuffleSort : public BaseSort<Type>
{
public:
	ShuffleSort();
	~ShuffleSort();

	void Sort(vector<Type> &vec) override;
};

#include "ShuffleSort.cpp"
#endif //_SHUFFLESORT_H
