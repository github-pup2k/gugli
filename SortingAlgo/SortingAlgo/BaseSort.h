#pragma once
#ifndef _BASESORT_H
#define _BASESORT_H
#include <vector>

using namespace std;
template <class Type>
class BaseSort
{
public:
	BaseSort() {};
	virtual ~BaseSort() {};
	virtual void Sort(vector<Type> &vec) {}

protected:
	void Exchange(vector<Type> &vec, size_t i, size_t j)
	{
		Type tmp = vec[i];
		vec[i] = vec[j];
		vec[j] = tmp;
	}

};

#endif //_BASESORT_H
