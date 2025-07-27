#ifndef DATA_STRUCTURES_STACK_WITH_ARRAY_STL_H
#define DATA_STRUCTURES_STACK_WITH_ARRAY_STL_H

#include <vector>

namespace DataStructures {

/**
 * @class StackWithArraySTL
 * @brief Stack with STL array class and all related functionality.
 * @tparam T Type of the the implementation class.
 */
template <typename T>
class StackWithArraySTL {
public:
	/**
         * @brief Push the element at the top of the stack.
         * @param element The element to be pushed.
         */
	void push(const T& element) { arr.push_back(element); }

	/**
         * @brief Pop the element from the top of the stack and return its
         *        value.
         * @return The value of the element that has been popped.
         */
	T pop()
	{
		T top = arr.back();
		arr.pop_back();
		return top;
	}

	/**
         * @brief Get the value of the element at the top of the stack.
         * @return The value of the element at the top of the stack.
         */
	T peek() const { return arr.back(); }

	/**
         * @brief Get the current size of the stack.
         * @return The current size of the stack.
         */
	size_t size() const { return arr.size(); }

private:
	/**
         * The dynamic array used to internally implement the stack.
         */
	std::vector<T> arr;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_STACK_WITH_ARRAY_H
