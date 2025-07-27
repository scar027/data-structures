#ifndef DATA_STRUCTURES_DYNAMIC_ARRAY_H
#define DATA_STRUCTURES_DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

namespace DataStructures {

/**
 * @class DynamicArray
 * @brief Dynamic array class with all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class DynamicArray {
public:
	/**
         * @brief Default constructor for the DynamicArray class.
         *
         * Initializes an array of type T and size default initial capacity. The
         * current size is set to zero and the capacity is initializd to the 
         * default initial capacity.
         */
	DynamicArray()
	{
		data = new T[init_cap];
		size = 0;
		cap = init_cap;
	}

	/**
         * @brief Constructor for DynamicArray class with specified initial
         *        capacity.
         *
         * Initalizes an array of type T and size specified initial capacity. 
         * The current size is set to zero and the capacity is initialized to
         * the specified initial capacity.
         *
         * @param init_cap Desired initial capacity of the dynamic array.
         * */
	DynamicArray(int initial_capacity)
	{
		data = new T[initial_capacity];
		size = 0;
		cap = initial_capacity;
	}

	/**
         * @brief Default destructor for the DynamicArray class.
         *
         * Frees the memory used by the array.
         */
	~DynamicArray() { delete[] data; }

	/** Add functions */
	/**
         * @brief Adds an element at the end of the array.
         *
         * This is achieved by first checking if the array is full, doubling its
         * size if it is and then adding the element and incrementing the 
         * current size by unity.
         *
         * @param element The element to be inserted.
         */
	void add_last(const T& element)
	{
		if (int(size) == cap) {
			resize(2 * cap);
		}
		data[size] = element;
		size++;
	}

	/**
         * @brief Adds an element at a specified index.
         *
         * This is achieved by first checking if the position index is valid
         * using the private @ref check_position_index() function. If the array
         * is full then its size is doubled. The elements to the right of the
         * desired position are shifted to the right, the new element added and
         * the size incremented by unity.
         *
         * @param pos_index Position index where the new element is desired to
         *                  be added.
         * @param element The element to be added.
         */
	void add(int pos_index, const T& element)
	{
		check_position_index(pos_index);
		if (int(size) == cap) {
			resize(2 * cap);
		}
		for (int i = int(size) - 1; i >= pos_index; i--) {
			data[i + 1] = data[i];
		}
		data[pos_index] = element;
		size++;
	}

	/**
         * @brief Adds an element at the start of the array.
         *
         * Internally uses the @ref add() function with @c pos_index zero to add
         * the element to the start of the array.
         *
         * @param element The element to be added.
         */
	void add_first(const T& element) { add(0, element); }

	/* Delete functions */
	/**
         * @brief Deletes the last element of the array and returns its value.
         *
         * This is achieved by first checking if the array is empty, if the
         * current size is one-fourth the capacity alloted then the array is
         * resized to half its size. The last element is cleared, the current
         * size of the array updated and the last element's value is returned.
         *
         * @return The deleted last element.
         */
	T del_last()
	{
		if (size == 0) {
			throw std::out_of_range("The array is empty");
		}
		if (int(size) == cap / 4) {
			resize(cap / 2);
		}
		T last_element = data[int(size) - 1];
		data[int(size) - 1] = T();
		size--;
		return last_element;
	}

	/**
         * @brief Deletes the element at a particular index.
         *
         * This is achieved by first checking if the index is valid, halfing the
         * size of the array if its current size is one-fourth its capacity, 
         * then shifting all elements to the right of the index to the left, 
         * clearing its value, updating the size and finally returning the 
         * deleted element.
         *
         * @param index The index of the element to be erased.
         * @return The deleted element.
         */
	T del(int index)
	{
		check_element_index(index);
		if (int(size) == cap / 4) {
			resize(cap / 2);
		}
		T deleted_element = data[index];
		for (int i = index + 1; i < int(size); i++) {
			data[i - 1] = data[i];
		}
		data[int(size) - 1] = T();
		size--;
		return deleted_element;
	}

	/** 
         * @brief Deletes the first element in the array.
         *
         * Internally uses the @ref del() function with @c index zero to delete
         * the first element in the array.
         *
         * @return The deleted first element.
         */
	T del_first() { return del(0); }

	/* Get functions */
	/**
         * @brief Get the element at a specified index.
         *
         * Checks if the requested element's index is valid using the private
         * @ref check_element_index() function and returns the element if it is.
         *
         * @param index Index of the element.
         * @return Element at the specified index.
         */
	T get(int index) const
	{
		check_element_index(index);
		return data[index];
	}

	/* Set functions */
	/**
         * @brief Sets the value of an element at a particular index.
         *
         * This is achieved by first checking if the index is valid using the
         * private @ref check_element_index(), setting it's value and then
         * returning the old value.
         *
         * @param index The index of the element whose value is to be set.
         * @param val The new value to be set to.
         * @return The old value. 
         */
	T set(int index, const T& val)
	{
		check_element_index(index);
		T old_val = data[index];
		data[index] = val;
		return old_val;
	}

	/* Utility functions */
	/**
         * @brief Get the current size of the array.
         * @return Size of the array.
         */
	size_t get_size() const { return size; }

	/**
         * @brief Check if the array is empty.
         * @return true if the array is empty, false otherwise.
         */
	bool is_empty() const { return size == 0; }

	/**
         * @brief Resize the array to a new capacity.
         *
         * Creates an array with the new capacity, copies the old data to it and
         * makes the old array pointer point to this new array. The capacity is
         * updated accordingly.
         */
	void resize(int new_cap)
	{
		T* temp = new T[new_cap];
		for (int i = 0; i < int(size); i++) {
			temp[i] = data[i];
		}
		data = temp;
		cap = new_cap;
	}

	/**
         * @brief Checks if the given element index is valid i.e in [0, size).
         * @param index Index to be checked.
         * @return true if the index is valid, false otherwise.
         */
	bool is_element_index(int index) const
	{
		return index >= 0 && index < int(size);
	}

	/**
         * @brief Checks if the given position index is valid i.e in [0, size].
         *
         * @param pos_index Position index to be checked.
         * @return true if the position index is valid, false otherwise.
         */
	bool is_position_index(int pos_index) const
	{
		return pos_index >= 0 && pos_index <= int(size);
	}

	/** 
         * @brief Checks the given element index and throws an exception if out
         *        of range.
         * @param index Index to be checked.
         * @throws std::out_of_range thrown when the index is out of the valid 
         *         range i.e [0, size). The exception message states that the 
         *         "Element index is out of bounds".
         */
	void check_element_index(int index) const
	{
		if (!is_element_index(index)) {
			throw std::out_of_range(
				"Element index is out of bounds");
		}
	}

	/** 
         * @brief Checks the given position index and throws an exception if out
         *        of range.
         * @param pos_index Position index to be checked.
         * @throws std::out_of_range thrown when the position index is out of 
         *         the valid range i.e [0, size]. The exception message states
         *         that the "Position index is out of bounds".
         */
	void check_position_index(int pos_index) const
	{
		if (!is_position_index(pos_index)) {
			throw std::out_of_range(
				"Position index is out of bounds");
		}
	}

	/** 
         * @brief Report the current size and capacity of the array and display
         *        the values of its elements. 
         */
	void display()
	{
		std::cout << "Size = " << size << "Capacity = " << cap << '\n';
		for (int i = 0; i < int(size); i++) {
			std::cout << data[i] << " \n"[i == int(size) - 1];
		}
	}

private:
	/** The underlying array that actually stores the data. */
	T* data = nullptr;
	/** Current number of elements. */
	size_t size = 0;
	/** Maximum element capacity. */
	int cap = 0;
	/** Default initial capacity. */
	static constexpr int init_cap = 1;
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_DYNAMIC_ARRAY_H
