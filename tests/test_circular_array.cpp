#include <cassert>
#include <stdexcept>
#include <iostream>
#include "data_structures/circular_array.h"

void test_empty_array_behavior()
{
	DataStructures::CircularArray<int> ca;
	assert(ca.is_empty());
	assert(ca.get_size() == 0);
	bool caught1 = false, caught2 = false, caught3 = false, caught4 = false;
	try {
		ca.get_first();
	} catch (const std::out_of_range&) {
		caught1 = true;
	}
	try {
		ca.get_last();
	} catch (const std::out_of_range&) {
		caught2 = true;
	}
	try {
		ca.del_first();
	} catch (const std::out_of_range&) {
		caught3 = true;
	}
	try {
		ca.del_last();
	} catch (const std::out_of_range&) {
		caught4 = true;
	}
	assert(caught1 && caught2 && caught3 && caught4);
}

void test_basic_add_remove()
{
	DataStructures::CircularArray<int> ca;
	ca.add_first(10);
	assert(!ca.is_empty());
	assert(ca.get_size() == 1);
	assert(ca.get_first() == 10);
	assert(ca.get_last() == 10);
	ca.add_last(20);
	assert(ca.get_size() == 2);
	assert(ca.get_first() == 10);
	assert(ca.get_last() == 20);
	ca.add_first(5);
	assert(ca.get_first() == 5);
	assert(ca.get_last() == 20);
	assert(ca.get_size() == 3);
	int first = ca.del_first();
	assert(first == 5);
	assert(ca.get_first() == 10);
	assert(ca.get_size() == 2);
	int last = ca.del_last();
	assert(last == 20);
	assert(ca.get_last() == 10);
	assert(ca.get_size() == 1);
	ca.del_last(); // now empty again
	assert(ca.is_empty());
}

void test_resizing_behavior()
{
	DataStructures::CircularArray<int> ca(2);
	ca.add_last(1);
	ca.add_last(2);
	ca.add_last(3); // triggers resize
	ca.add_first(0);
	assert(ca.get_size() == 4);
	assert(ca.get_first() == 0);
	assert(ca.get_last() == 3);
}

int main()
{
	test_empty_array_behavior();
	test_basic_add_remove();
	test_resizing_behavior();
	std::cout << "All CircularArray tests passed!\n";
	return 0;
}
