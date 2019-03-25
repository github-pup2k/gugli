#pragma once
#ifndef _SORT_H
#include <vector>

using namespace std;
template <class Type>
class BaseSort
{
public:
	Sort() {};
	virtual ~Sort() {};

	void Exchange(vector<Type> &vec, size_t i, size_t j)
	{
		Type tmp = vec[i];
		vec[i] = vec[j];
		vec[j] = tmp;
	}
};

#endif //_SORT_H
