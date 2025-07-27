#ifndef DATA_STRUCTURES_DEQUE_WITH_ARRAY_H
#define DATA_STRUCTURES_DEQUE_WITH_ARRAY_H

#include "circular_array.h"

namespace DataStructures {

/**
 * @class DequeWithArray
 * @brief Deque with array class with all relevant functionality.
 * @tparam T The type of the implementation class.
 */
template <typename T>
class DequeWithArray {
public:
	/**
         * @brief Adds an element to the front of the deque.
         * @param element The element to be added.
         */
	void add_first(const T& element) { arr.add_first(element); }

	/**
         * @brief Adds an element to the back of the deque.
         * @param element The element to be added.
         */
	void add_last(const T& element) { arr.add_last(element); }

	/**
         * @brief Deletes the element at the front of the deque.
         * @return The deleted element from the front.
         */
	T del_first() { return arr.del_first(); }

	/**
         * @brief Deletes the element at the back of the deque.
         * @return The deleted element from the back.
         */
	T del_last() { return arr.del_last(); }

	/**
         * @brief Gets the value of the element at the front of the deque.
         * @return The value of the element at the front of the deque.
         */
	T peek_first() const { return arr.get_first(); }

	/**
         * @brief Gets the value of the element at the back of the deque.
         * @return The value of the element at the back of the deque.
         */
	T peek_last() const { return arr.get_last(); }

private:
	/** The circular array used to internally implement the deque. */
	CircularArray<T> arr;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_DEQUE_WITH_ARRAY_H
