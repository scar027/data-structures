#include <cassert>
#include <string>
#include <iostream>
#include "data_structures/stack_with_array.h"

void test_push_and_peek()
{
	DataStructures::StackWithArray<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	assert(stack.peek() == 30);
	assert(stack.size() == 3);
}

void test_pop()
{
	DataStructures::StackWithArray<int> stack;
	stack.push(100);
	stack.push(200);
	assert(stack.pop() == 200);
	assert(stack.peek() == 100);
	assert(stack.size() == 1);
}

void test_string_stack()
{
	DataStructures::StackWithArray<std::string> stack;
	stack.push("A");
	stack.push("B");
	stack.push("C");
	assert(stack.pop() == "C");
	assert(stack.peek() == "B");
	assert(stack.size() == 2);
}

int main()
{
	test_push_and_peek();
	test_pop();
	test_string_stack();
	std::cout << "All StackWithArray tests passed." << '\n';
	return 0;
}
