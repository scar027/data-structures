#ifndef DATA_STRUCTURES_QUEUE_WITH_LINKED_LIST_H
#define DATA_STRUCTURES_QUEUE_WITH_LINKED_LIST_H

#include "doubly_linked_list.h"

namespace DataStructures {

/**
 * @class QueueWithLinkedList
 * @brief Queue with linked list class and all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class QueueWithLinkedList {
public:
	/**
         * @brief Pushes the element at the back of the queue.
         * @param element The element to be pushed.
         */
	void push(const T& element) { list.add_last(element); }

	/**
         * @brief Pops the element from the front of the queue and returns its
         *        value.
         * @return The value of the popped element.
         */
	T pop()
	{
		T front = list.get_first();
		list.del_first();
		return front;
	}

	/**
         * @brief Gets the value of the element at the front of the queue.
         * @return The value of the element at the front of the queue.
         */
	T peek() const { return list.get_first(); }

	/**
         * @brief Gets the size of the queue.
         * @return The current size of the queue.
         */
	size_t size() const { return list.get_size(); }

private:
	/**
         * The doubly linked list used for internally implementing the queue.
         */
	DoublyLinkedList<T> list;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_QUEUE_WITH_LINKED_LIST_H
