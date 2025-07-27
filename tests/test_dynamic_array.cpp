#include <cassert>
#include <string>
#include <iostream>
#include "data_structures/dynamic_array.h"

void test_add_and_get()
{
	DataStructures::DynamicArray<int> arr;
	arr.add_last(10);
	arr.add_last(20);
	arr.add_last(30);
	assert(arr.get_size() == 3);
	assert(arr.get(0) == 10);
	assert(arr.get(1) == 20);
	assert(arr.get(2) == 30);
}

void test_add_first()
{
	DataStructures::DynamicArray<std::string> arr;
	arr.add_first("C");
	arr.add_first("B");
	arr.add_first("A");
	assert(arr.get_size() == 3);
	assert(arr.get(0) == "A");
	assert(arr.get(1) == "B");
	assert(arr.get(2) == "C");
}

void test_insert_at_position()
{
	DataStructures::DynamicArray<int> arr;
	arr.add_last(1);
	arr.add_last(3);
	arr.add(1, 2); // Insert 2 at index 1
	assert(arr.get_size() == 3);
	assert(arr.get(0) == 1);
	assert(arr.get(1) == 2);
	assert(arr.get(2) == 3);
}

void test_deletion()
{
	DataStructures::DynamicArray<int> arr;
	arr.add_last(1);
	arr.add_last(2);
	arr.add_last(3);
	arr.add_last(4);
	assert(arr.del(1) == 2); // Delete at index 1
	assert(arr.del_first() == 1); // Delete first
	assert(arr.del_last() == 4); // Delete last
	assert(arr.get_size() == 1);
	assert(arr.get(0) == 3);
}

void test_set()
{
	DataStructures::DynamicArray<char> arr;
	arr.add_last('a');
	arr.add_last('b');
	char old_val = arr.set(1, 'z');
	assert(old_val == 'b');
	assert(arr.get(1) == 'z');
}

void test_exceptions()
{
	DataStructures::DynamicArray<int> arr;
	bool caught = false;
	try {
		arr.get(0);
	} catch (const std::out_of_range&) {
		caught = true;
	}
	assert(caught);
}

int main()
{
	test_add_and_get();
	test_add_first();
	test_insert_at_position();
	test_deletion();
	test_set();
	test_exceptions();
	std::cout << "All DynamicArray tests passed!\n";
	return 0;
}
