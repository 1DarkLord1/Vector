#include <iostream>
#include <cassert>

#include "my_vector.h"

template <typename T>
static void test_my_vector_default_constructible(const T& first, const T& second) {
	std::cout << "-------------------------------------------" << std::endl;
	my_vector::my_vector <T> vec0(10);
	std::cout << "Vector vec0 initialized by default values: " << vec0 << std::endl;
	assert(vec0.size() == 10);
	for(std::size_t i = 0; i < 10; i++) {
		vec0[i] = second;
	}
	std::cout << "Main vector vec0: " << vec0 << std::endl;
	vec0.pop_back();
	assert(vec0.size() == 9);
	my_vector::my_vector<T> vec1 = vec0;
	std::cout << "Copied vector vec1: " << vec1 << std::endl;
	vec1.clear();
	assert(vec1.size() == 0);
	vec1.push_back(second);
	vec1[0] = first;
	assert(vec1.size() == 1);
	my_vector::my_vector <T> vec2(12);
	my_vector::my_vector <T> vec3(10);
	vec2 = vec3;
	assert(vec2.size() == vec3.size());
	std::cout << "All asserts passed!!!" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

template <typename T>
static void test_my_vector(const T& first, const T& second) {
	std::cout << "-------------------------------------------" << std::endl;
	my_vector::my_vector <T> vec0;
	vec0.push_back(first);
	vec0.push_back(second);
	vec0.push_back(first);
	vec0.push_back(second);
	assert(vec0.size() == 4);
	std::cout << "Main vector vec0: " << vec0 << std::endl;
	vec0.pop_back();
	assert(vec0.size() == 3);
	my_vector::my_vector<T> vec1 = vec0;
	std::cout << "Copied vector vec1: " << vec1 << std::endl;
	vec1[0] = vec1[2] = second;
	std::cout << "Changed vector vec1: " << vec1 << std::endl;
	vec1.clear();
	assert(vec1.size() == 0);
	vec1.push_back(second);
	assert(vec1.size() == 1);
	std::cout << "All asserts passed!!!" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

int main() {
    test_my_vector_default_constructible<int>(5, 10);
    return 0;
}
