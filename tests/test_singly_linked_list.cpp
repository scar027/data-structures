#include <cassert>
#include <iostream>
#include <stdexcept>
#include "data_structures/singly_linked_list.h"

void test_add_methods()
{
	DataStructures::SinglyLinkedList<int> list;
	list.add_first(2); // [2]
	list.add_last(4); // [2, 4]
	list.add(1, 3); // [2, 3, 4]
	list.add(0, 1); // [1, 2, 3, 4]
	assert(list.get_size() == 4);
	assert(list.get_first() == 1);
	assert(list.get_last() == 4);
	assert(list.get(2) == 3);
}

void test_del_methods()
{
	DataStructures::SinglyLinkedList<int> list;
	list.add_last(10);
	list.add_last(20);
	list.add_last(30); // [10, 20, 30]
	list.del_first(); // [20, 30]
	assert(list.get_first() == 20);
	list.del_last(); // [20]
	assert(list.get_last() == 20);
	list.del(0); // []
	assert(list.get_size() == 0);
}

void test_get_methods()
{
	DataStructures::SinglyLinkedList<int> list;
	list.add_last(100);
	list.add_last(200);
	list.add_last(300); // [100, 200, 300]
	assert(list.get(0) == 100);
	assert(list.get(1) == 200);
	assert(list.get(2) == 300);
	assert(list.get_first() == 100);
	assert(list.get_last() == 300);
}

void test_set_method()
{
	DataStructures::SinglyLinkedList<int> list;
	list.add_last(1);
	list.add_last(2);
	list.add_last(3); // [1, 2, 3]
	list.set(1, 42); // [1, 42, 3]
	assert(list.get(1) == 42);
}

void test_exceptions()
{
	DataStructures::SinglyLinkedList<int> list;
	bool got1 = false, got2 = false, got3 = false;
	try {
		list.get(0);
	} catch (std::out_of_range&) {
		got1 = true;
	}
	try {
		list.set(5, 100);
	} catch (std::out_of_range&) {
		got2 = true;
	}
	try {
		list.del(3);
	} catch (std::out_of_range&) {
		got3 = true;
	}
	assert(got1 && got2 && got3);
}

int main()
{
	try {
		test_add_methods();
		test_del_methods();
		test_get_methods();
		test_set_method();
		test_exceptions();
		std::cout << "All SinglyLinkedList tests passed.\n";
		return 0;
	} catch (...) {
		std::cerr << "A SinglyLinkedList test failed.\n";
		return 1;
	}
}
