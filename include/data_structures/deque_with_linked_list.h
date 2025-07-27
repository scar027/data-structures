#ifndef DATA_STRUCTURES_DEQUE_WITH_LINKED_LIST_H
#define DATA_STRUCTURES_DEQUE_WITH_LINKED_LIST_H

#include "doubly_linked_list.h"

namespace DataStructures {

/**
 * @class DequeWithLinkedList
 * @brief Deque with linked list class with all related functionality.
 * @tparam T The type of the implementation class.
 */
template <typename T>
class DequeWithLinkedList {
public:
	/**
         * @brief Adds an element to the front of the deque.
         * @param element The element to be added.
         */
	void add_first(const T& element) { list.add_first(element); }

	/**
         * @brief Adds an element to the back of the deque.
         * @param element The element to be added.
         */
	void add_last(const T& element) { list.add_last(element); }

	/**
         * @brief Deletes the element at the front of the deque.
         * @return The deleted element from the front.
         */
	T del_first()
	{
		T front_element = list.get_first();
		list.del_first();
		return front_element;
	}

	/**
         * @brief Deletes the element at the back of the deque.
         * @return The deleted element from the back.
         */
	T del_last()
	{
		T back_element = list.get_last();
		list.del_last();
		return back_element;
	}

	/**
         * @brief Gets the value of the element at the front of the deque.
         * @return The value of the element at the front of the deque.
         */
	T peek_first() const { return list.get_first(); }

	/**
         * @brief Gets the value of the element at the back of the deque.
         * @return The value of the element at the back of the deque.
         */
	T peek_last() const { return list.get_last(); }

private:
	/** The doubly linked list used to internally implement the deque. */
	DoublyLinkedList<T> list;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_DEQUE_WITH_LINKED_LIST_H
