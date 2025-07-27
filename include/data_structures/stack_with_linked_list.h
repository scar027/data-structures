#ifndef DATA_STRUCTURES_STACK_WITH_LINKED_LIST_H
#define DATA_STRUCTURES_STACK_WITH_LINKED_LIST_H

#include "doubly_linked_list.h"

namespace DataStructures {

/**
 * @class StackWithLinkedList
 * @brief Stack with linked list class with all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class StackWithLinkedList {
public:
	/**
         * @brief Push an element onto the top of the stack.
         * @param element The element to push.
         */
	void push(const T& element) { list.add_last(element); }

	/**
         * @brief Pop the element at the top of the stack and return its value.
         * @return Value of the popped element.
         */
	T pop()
	{
		T top = list.del_last();
		return top;
	}

	/**
         * @brief Get the value of the top element of the stack.
         * @return The value of the top element of the stack.
         */
	T peek() const { return list.get_last(); }

	/**
         * @brief Get the size of the stack.
         * @return Size of the stack.
         */
	size_t size() const { return list.get_size(); }

private:
	/** 
         * The doubly linked list used for internally implementing the stack.
         */
	DoublyLinkedList<T> list;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_STACK_WITH_LINKED_LIST_H
