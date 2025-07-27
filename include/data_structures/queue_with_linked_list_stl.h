#ifndef DATA_STRUCTURES_QUEUE_WITH_LINKED_LIST_STL_H
#define DATA_STRUCTURES_QUEUE_WITH_LINKED_LIST_STL_H

#include <list>

namespace DataStructures {

/**
 * @class QueueWithLinkedListSTL
 * @brief Queue with STL linked list class and all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class QueueWithLinkedListSTL {
public:
	/**
         * @brief Push the element at the back of the queue.
         * @param element The element to be pushed.
         */
	void push(const T& element) { list.push_back(element); }

	/**
         * @brief Pop the element from the front of the queue and return its
         *        value.
         * @return The value of the popped element.
         * @throws std::out_of_range stating that "Queue is empty".
         */
	T pop()
	{
		if (list.empty()) {
			throw std::out_of_range("Queue is empty");
		}
		T front = list.front();
		list.pop_front();
		return front;
	}

	/**
         * @brief Get the value of the element at the front of the queue.
         * @return The value of the element at the front of the queue.
         * @throws std::out_of_range stating that "Queue is empty".
         */
	T peek() const
	{
		if (list.empty()) {
			throw std::out_of_range("Queue is empty");
		}
		return list.front();
	}

	/**
         * @brief Get the size of the queue.
         * @return The current size of the queue.
         */
	size_t size() const { return list.size(); }

private:
	/**
         * The doubly linked list used for internally implementing the queue.
         */
	std::list<T> list;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_QUEUE_WITH_LINKED_LIST_STL_H
