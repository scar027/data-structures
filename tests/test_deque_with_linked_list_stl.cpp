#include <cassert>
#include <iostream>
#include <stdexcept>
#include "data_structures/deque_with_linked_list_stl.h"

void test_empty_deque_behavior()
{
	DataStructures::DequeWithLinkedListSTL<int> dq;
	bool caught1 = false, caught2 = false, caught3 = false, caught4 = false;
	try {
		dq.del_first();
	} catch (const std::out_of_range&) {
		caught1 = true;
	}
	try {
		dq.del_last();
	} catch (const std::out_of_range&) {
		caught2 = true;
	}
	try {
		dq.peek_first();
	} catch (const std::out_of_range&) {
		caught3 = true;
	}
	try {
		dq.peek_last();
	} catch (const std::out_of_range&) {
		caught4 = true;
	}
	assert(caught1 && caught2 && caught3 && caught4);
}

void test_add_peek_operations()
{
	DataStructures::DequeWithLinkedListSTL<int> dq;
	dq.add_first(10);
	assert(dq.peek_first() == 10);
	assert(dq.peek_last() == 10);
	dq.add_first(5);
	assert(dq.peek_first() == 5);
	assert(dq.peek_last() == 10);
	dq.add_last(20);
	assert(dq.peek_first() == 5);
	assert(dq.peek_last() == 20);
}

void test_delete_operations()
{
	DataStructures::DequeWithLinkedListSTL<int> dq;
	dq.add_last(1);
	dq.add_last(2);
	dq.add_last(3);
	dq.add_last(4);
	assert(dq.del_first() == 1);
	assert(dq.del_last() == 4);
	assert(dq.peek_first() == 2);
	assert(dq.peek_last() == 3);
}

void test_mixed_operations()
{
	DataStructures::DequeWithLinkedListSTL<std::string> dq;
	dq.add_last("end");
	dq.add_first("start");
	dq.add_last("final");
	assert(dq.peek_first() == "start");
	assert(dq.peek_last() == "final");
	dq.del_first(); // removes "start"
	dq.del_last(); // removes "final"
	assert(dq.peek_first() == "end");
	assert(dq.peek_last() == "end");
}

int main()
{
	test_empty_deque_behavior();
	test_add_peek_operations();
	test_delete_operations();
	test_mixed_operations();
	std::cout << "All DequeWithLinkedListSTL tests passed!\n";
	return 0;
}
