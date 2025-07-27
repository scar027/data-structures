#ifndef DATA_STRUCTURES_DEQUE_WITH_LINKED_LIST_STL_H
#define DATA_STRUCTURES_DEQUE_WITH_LINKED_LIST_STL_H

#include <list>

namespace DataStructures {

/**
 * @class DequeWithLinkedListSTL
 * @brief Deque with STL linked list class with all related functionality.
 * @tparam T The type of the implementation class.
 */
template <typename T>
class DequeWithLinkedListSTL {
public:
	/**
         * @brief Adds an element to the front of the deque.
         * @param element The element to be added.
         */
	void add_first(const T& element) { list.push_front(element); }

	/**
         * @brief Adds an element to the back of the deque.
         * @param element The element to be added.
         */
	void add_last(const T& element) { list.push_back(element); }

	/**
         * @brief Deletes the element at the front of the deque.
         * @return The deleted element from the front.
         * @throws std::out_of_range stating that the "Deque is empty".
         */
	T del_first()
	{
		if (list.empty()) {
			throw std::out_of_range("Deque is empty");
		}
		T front_element = list.front();
		list.pop_front();
		return front_element;
	}

	/**
         * @brief Deletes the element at the back of the deque.
         * @return The deleted element from the back.
         * @throws std::out_of_range stating that the "Deque is empty".
         */
	T del_last()
	{
		if (list.empty()) {
			throw std::out_of_range("Deque is empty");
		}
		T back_element = list.back();
		list.pop_back();
		return back_element;
	}

	/**
         * @brief Gets the value of the element at the front of the deque.
         * @return The value of the element at the front of the deque.
         * @throws std::out_of_range stating that the "Deque is empty".
         */
	T peek_first() const
	{
		if (list.empty()) {
			throw std::out_of_range("Deque is empty");
		}
		return list.front();
	}

	/**
         * @brief Gets the value of the element at the back of the deque.
         * @return The value of the element at the back of the deque.
         * @throws std::out_of_range stating that the "Deque is empty".
         */
	T peek_last() const
	{
		if (list.empty())
			throw std::out_of_range("Deque is empty");
		return list.back();
	}

private:
	/** The doubly linked list used to internally implement the deque. */
	std::list<T> list;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_DEQUE_WITH_LINKED_LIST_STL_H
