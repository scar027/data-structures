#include <cassert>
#include <iostream>
#include <stdexcept>
#include "data_structures/queue_with_array_stl.h"

void test_push_and_size()
{
	DataStructures::QueueWithArraySTL<int> q;
	assert(q.size() == 0);
	q.push(10);
	q.push(20);
	q.push(30);
	assert(q.size() == 3);
}

void test_peek()
{
	DataStructures::QueueWithArraySTL<int> q;
	assert(q.size() == 0);
	q.push(100);
	q.push(200);
	assert(q.peek() == 100); // front of queue remains
	assert(q.size() == 2); // should not modify size
}

void test_pop()
{
	DataStructures::QueueWithArraySTL<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	assert(q.pop() == 1); // FIFO
	assert(q.pop() == 2);
	assert(q.size() == 1);
	assert(q.peek() == 3);
}

void test_empty_pop_peek_throws()
{
	DataStructures::QueueWithArraySTL<int> q;
	bool caught1 = false, caught2 = false;
	try {
		q.pop();
	} catch (std::out_of_range&) {
		caught1 = true;
	}
	try {
		q.peek();
	} catch (std::out_of_range&) {
		caught2 = true;
	}
	assert(caught1 && caught2);
}

int main()
{
	try {
		test_push_and_size();
		test_peek();
		test_pop();
		test_empty_pop_peek_throws();
		std::cout << "All QueueWithArraySTL tests passed.\n";
		return 0;
	} catch (...) {
		std::cerr << "A QueueWithArraySTL test failed.\n";
		return 1;
	}
}
