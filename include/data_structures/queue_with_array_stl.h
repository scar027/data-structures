#ifndef DATA_STRUCTURES_QUEUE_WITH_ARRAY_STL_H
#define DATA_STRUCTURES_QUEUE_WITH_ARRAY_STL_H

#include <deque>

namespace DataStructures {

/**
 * @class QueueWithArraySTL
 * @brief Queue with STL array class with all releated functionality.
 * @tparam T The type of the implementation class.
 */
template <typename T>
class QueueWithArraySTL {
public:
	/**
         * @brief Default constructor for the QueueWithArray class to intialize
         *        the internal deque to an empty deque.
         */
	QueueWithArraySTL() { arr = std::deque<T>(); }
	/**
         * @brief Pushes the element at the back of the queue.
         * @param element The element to be pushed.
         */
	void push(const T& element) { arr.push_back(element); }

	/**
         * @brief Pops an element from the front of the queue and returns its
         *        value.
         * @return val The value of the popped element.
         * @throws std::out_of_range stating that "Queue is empty".
         */
	T pop()
	{
		if (arr.empty()) {
			throw std::out_of_range("Queue is empty");
		}
		T val = arr.front();
		arr.pop_front();
		return val;
	}

	/**
         * @brief Gets the value of the element at the front of the queue.
         * @return The value of the element at the front of the queue.
         * @throws std::out_of_range stating that "Queue is empty".
         */
	T peek() const
	{
		if (arr.empty()) {
			throw std::out_of_range("Queue is empty");
		}
		return arr.front();
	}

	/**
         * @brief Gets the current size of the queue.
         * @return The current size of the queue.
         */
	size_t size() const { return arr.size(); }

private:
	/** The deque used to internally implement the queue. */
	std::deque<T> arr;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_QUEUE_WITH_ARRAY_STL_H
