#ifndef DATA_STRUCTURES_STACK_WITH_LINKED_LIST_STL_H
#define DATA_STRUCTURES_STACK_WITH_LINKED_LIST_STL_H

#include <list>

namespace DataStructures {

/**
 * @class StackWithLinkedListSTL
 * @brief Stack with STL linked list class with all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class StackWithLinkedListSTL {
public:
	/**
         * @brief Push an element onto the top of the stack.
         * @param element The element to be pushed.
         */
	void push(const T& element) { list.push_back(element); }

	/**
         * @brief Pop an element from the top of the stack and return its value.
         * @return The value of the popped element.
         */
	T pop()
	{
		T top = list.back();
		list.pop_back();
		return top;
	}

	/**
         * @brief Get the value of the top element of the stack.
         * @return The value of the top element of the stack.
         */
	T peek() const { return list.back(); }

	/**
         * @brief Get the size of the stack.
         * @return Size of the stack.
         */
	size_t size() const { return list.size(); }

private:
	/** 
         * The doubly linked list used for internally implementing the stack.
         */
	std::list<T> list;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_STACK_WITH_LINKED_LIST_STL_H
