#ifndef DATA_STRUCTURES_CIRCULAR_ARRAY_H
#define DATA_STRUCTURES_CIRCULAR_ARRAY_H

#include <stdexcept>
#include <vector>

namespace DataStructures {

template <typename T>
class CircularArray {
public:
	CircularArray() : CircularArray(1) {}

	explicit CircularArray(size_t init_size)
		: arr(init_size), start(0), end(0), size(0)
	{
	}

	void add_first(const T& val)
	{
		if (is_full()) {
			resize(arr.size() * 2);
		}
		start = (start - 1 + int(arr.size())) % int(arr.size());
		arr[static_cast<size_t>(start)] = val;
		size++;
	}

	void add_last(const T& val)
	{
		if (is_full()) {
			resize(arr.size() * 2);
		}
		arr[static_cast<size_t>(end)] = val;
		end = (end + 1) % int(arr.size());
		size++;
	}

	T del_first()
	{
		if (is_empty()) {
			throw std::out_of_range("Array is empty");
		}
		T val = arr[static_cast<size_t>(start)];
		arr[static_cast<size_t>(start)] = T();
		start = (start + 1) % int(arr.size());
		size--;
		if (size > 0 && int(size) == int(arr.size()) / 4) {
			resize(arr.size() / 2);
		}
		return val;
	}

	T del_last()
	{
		if (is_empty()) {
			throw std::out_of_range("Array is empty");
		}
		end = (end - 1 + int(arr.size())) % int(arr.size());
		T val = arr[static_cast<size_t>(end)];
		arr[static_cast<size_t>(end)] = T();
		size--;
		if (size > 0 && int(size) == int(arr.size()) / 4) {
			resize(arr.size() / 2);
		}
		return val;
	}

	T get_first() const
	{
		if (is_empty()) {
			throw std::out_of_range("Array is empty");
		}
		return arr[static_cast<size_t>(start)];
	}

	T get_last() const
	{
		if (is_empty()) {
			throw std::out_of_range("Array is empty");
		}
		return arr[static_cast<size_t>((end - 1 + int(arr.size())) %
					       int(arr.size()))];
	}

	bool is_full() const { return size == arr.size(); }

	size_t get_size() const { return size; }

	bool is_empty() const { return size == 0; }

private:
	std::vector<T> arr;
	int start;
	int end;
	size_t size;

	void resize(size_t new_size)
	{
		std::vector<T> new_arr(new_size);
		for (size_t i = 0; i < size; i++) {
			new_arr[i] = arr[static_cast<size_t>((start + int(i)) %
							     int(arr.size()))];
		}
		arr = std::move(new_arr);
		start = 0;
		end = int(size);
	}
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_CIRCULAR_ARRAY_H
