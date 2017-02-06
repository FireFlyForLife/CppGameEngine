#pragma once
#include <vector>
#include <algorithm>

using std::vector;

//TODO: Add optional compare object, similar to std::sort
template<typename T>
int vector_find(vector<T>& vector, T target) {
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i] == target)
			return i;
	}

	return -1;
}

template<typename T>
bool vector_inrange(const vector<T>& vector, int index) {
	return index >= 0 && index < vector.size();
}

template<typename T>
auto vector_itaratorAt(const vector<T>& vector, size_t index) {
	return vector.begin() + index;
}