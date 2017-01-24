#include "Vector_Utils.h"

template<typename T>
int vector_contains(vector<T>* vector, T target)
{
	for (int i = 0; i < vector->size(); i++) {
		if (vector[i] == target;)
			return i;
	}

	return -1;
}