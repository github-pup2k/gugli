#pragma once
#ifndef _BASESORT_H
#define _BASESORT_H
#include <vector>

using namespace std;
template <class Type>
class BaseSort
{
public:
	BaseSort() { NoOfComparisons_ = 0; };
	virtual ~BaseSort() {};
	virtual void Sort(vector<Type> &vec) {}
	size_t Comparisons() { return NoOfComparisons_; }

protected:
	void Exchange(vector<Type> &vec, size_t i, size_t j)
	{
		Type tmp = vec[i];
		vec[i] = vec[j];
		vec[j] = tmp;
	}
protected:
	size_t NoOfComparisons_;
};

#endif //_BASESORT_H
