#ifndef DATA_STRUCTURES_STACK_WITH_ARRAY_H
#define DATA_STRUCTURES_STACK_WITH_ARRAY_H

#include "dynamic_array.h"

namespace DataStructures {

/**
 * @class StackWithArray
 * @brief Stack with array class and all related functionality.
 * @tparam T Type of the the implementation class.
 */
template <typename T>
class StackWithArray {
public:
	/**
         * @brief Push the element at the top of the stack.
         * @param element The element to be pushed.
         */
	void push(const T& element) { arr.add_last(element); }

	/**
         * @brief Pop the element from the top of the stack and return its
         *        value.
         * @return The value of the element that has been popped.
         */
	T pop()
	{
		T top = arr.get(int(arr.get_size()) - 1);
		arr.del_last();
		return top;
	}

	/**
         * @brief Get the value of the element at the top of the stack.
         * @return The value of the element at the top of the stack.
         */
	T peek() const { return arr.get(int(arr.get_size()) - 1); }

	/**
         * @brief Get the current size of the stack.
         * @return The current size of the stack.
         */
	size_t size() const { return arr.get_size(); }

private:
	/**
         * The dynamic array used to internally implement the stack.
         */
	DynamicArray<T> arr;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_STACK_WITH_ARRAY_H
