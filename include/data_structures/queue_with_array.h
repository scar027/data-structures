#ifndef DATA_STRUCTURES_QUEUE_WITH_ARRAY_H
#define DATA_STRUCTURES_QUEUE_WITH_ARRAY_H

#include "circular_array.h"

namespace DataStructures {

/**
 * @class QueueWithArray
 * @brief Queue with array class with all releated functionality.
 * @tparam T The type of the implementation class.
 */
template <typename T>
class QueueWithArray {
public:
	/**
         * @brief Default constructor for the QueueWithArray class to intialize
         *        the internal deque to an empty deque.
         */
	QueueWithArray() { arr = CircularArray<T>(); }
	/**
         * @brief Pushes the element at the back of the queue.
         * @param element The element to be pushed.
         */
	void push(const T& element) { arr.add_last(element); }

	/**
         * @brief Pops an element from the front of the queue and returns its
         *        value.
         * @return val The value of the popped element.
         */
	T pop() { return arr.del_first(); }

	/**
         * @brief Gets the value of the element at the front of the queue.
         * @return The value of the element at the front of the queue.
         */
	T peek() const { return arr.get_first(); }

	/**
         * @brief Gets the current size of the queue.
         * @return The current size of the queue.
         */
	size_t size() const { return arr.get_size(); }

private:
	/** The circular array used to internally implement the queue. */
	CircularArray<T> arr;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_QUEUE_WITH_ARRAY_STL_H
