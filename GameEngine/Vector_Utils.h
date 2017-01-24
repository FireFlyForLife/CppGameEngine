#pragma once
#include <vector>

using std::vector;

//MAYBE: Add these functions to a class which inherits from vector.

template<typename T>
int vector_contains(vector<T>*, T) {
	for (int i = 0; i < vector->size(); i++) {
		if (vector[i] == target)
			return i;
	}

	return -1;
}

template<typename T>
bool vector_inrange(const vector<T>& vector, int index) {
	return index >= 0 && index < vector.size();
}