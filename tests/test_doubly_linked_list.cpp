#include <cassert>
#include <iostream>
#include <stdexcept>
#include "data_structures/doubly_linked_list.h"

void test_initially_empty()
{
	DataStructures::DoublyLinkedList<int> list;
	assert(list.get_size() == 0);
}

void test_add_first()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_first(5);
	list.add_first(10);
	assert(list.get_size() == 2);
	assert(list.get_first() == 10);
	assert(list.get_last() == 5);
}

void test_add_last()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_last(7);
	list.add_last(14);
	assert(list.get_size() == 2);
	assert(list.get_first() == 7);
	assert(list.get_last() == 14);
}

void test_delete_first()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_first(42);
	list.del_first();
	assert(list.get_size() == 0);
}

void test_delete_last()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_first(1);
	list.add_first(2);
	list.del_last();
	assert(list.get_size() == 1);
	assert(list.get_first() == 2);
}

void test_add_at_index()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add(0, 10); // [10]
	list.add(1, 30); // [10, 30]
	list.add(1, 20); // [10, 20, 30]
	list.add(3, 40); // [10, 20, 30, 40]

	assert(list.get_size() == 4);
	assert(list.get(0) == 10);
	assert(list.get(1) == 20);
	assert(list.get(2) == 30);
	assert(list.get(3) == 40);
}

void test_del_at_index()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_last(100);
	list.add_last(200);
	list.add_last(300); // [100, 200, 300]
	int val = list.del(1); // Should remove 200 i.e [100, 300]
	assert(val == 200);
	assert(list.get_size() == 2);
	assert(list.get(0) == 100);
	assert(list.get(1) == 300);
}

void test_get_at_index()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add(0, 5);
	list.add(1, 15);
	list.add(2, 25); // [5, 15, 25]
	assert(list.get(0) == 5);
	assert(list.get(1) == 15);
	assert(list.get(2) == 25);
}

void test_set_at_index()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_last(1);
	list.add_last(2);
	list.add_last(3); // [1, 2, 3]
	int old = list.set(1, 99); // [1, 99, 3]
	assert(old == 2);
	assert(list.get(1) == 99);
}

void test_invalid_index_throws()
{
	DataStructures::DoublyLinkedList<int> list;
	list.add_last(10);
	bool caught1 = false, caught2 = false, caught3 = false;
	try {
		list.get(5);
	} catch (std::out_of_range&) {
		caught1 = true;
	}
	try {
		list.set(2, 50);
	} catch (std::out_of_range&) {
		caught2 = true;
	}
	try {
		list.del(3);
	} catch (std::out_of_range&) {
		caught3 = true;
	}
	assert(caught1 && caught2 && caught3);
}

void test_throw_on_empty_delete()
{
	DataStructures::DoublyLinkedList<int> list;
	bool caught1 = false, caught2 = false;
	try {
		list.del_first();
	} catch (std::out_of_range&) {
		caught1 = true;
	}
	try {
		list.del_last();
	} catch (std::out_of_range&) {
		caught2 = true;
	}
	assert(caught1 && caught2);
}

void test_clear_list()
{
	DataStructures::DoublyLinkedList<int> list;
	for (int i = 0; i < 10; ++i)
		list.add_last(i);
	for (int i = 0; i < 10; ++i)
		list.del_first();
	assert(list.get_size() == 0);
}

int main()
{
	try {
		test_initially_empty();
		test_add_first();
		test_add_last();
		test_delete_first();
		test_delete_last();
		test_add_at_index();
		test_del_at_index();
		test_get_at_index();
		test_set_at_index();
		test_invalid_index_throws();
		test_throw_on_empty_delete();
		test_clear_list();
		std::cout << "All DoublyLinkedList tests passed.\n";
		return 0;
	} catch (...) {
		std::cerr << "A DoublyLinkedList test failed.\n";
		return 1;
	}
}
