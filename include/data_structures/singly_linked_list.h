#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

namespace DataStructures {

/**
 * @class SinglyLinkedList
 * @brief Singly linked list class with all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class SinglyLinkedList {
public:
	/**
         * @brief Constructor for the SinglyLinkedList class.
         *
         * Initializes the head node and points the tail to the head. Size is
         * initialized to zero.
         */
	SinglyLinkedList()
	{
		head = new Node(T());
		tail = head;
		size = 0;
	}

	/**
         * @brief Destructor for the SinglyLinkedList class.
         *
         * Clears the singly linked list and deletes the head and tail pointers.
         */
	~SinglyLinkedList()
	{
		Node* cur = head;
		while (cur != nullptr) {
			Node* next = cur->next;
			delete cur;
			cur = next;
		}
	}

	/* Add functions */
	/**
         * @brief Adds a new node at the start of the list.
         *
         * This is achieved by linking the new node to the node pointed by head
         * and updating head to point to the new node. If the list was empty
         * earlier then the tail is updated. The size is incremented by unity.
         * 
         * @param data The data of the node to be added.
         */
	void add_first(const T& data)
	{
		Node* x = new Node(data);
		x->next = head->next;
		head->next = x;
		if (size == 0) {
			tail = x;
		}
		size++;
	}

	/** 
         * @brief Adds a new node at the end of the list.
         *
         * This is achieved by linking the node pointed by the tail to the new
         * node and then updating the tail to point to the new node. The size is
         * incremented by unity.
         * 
         * @param data The data of the node to be added.
         */
	void add_last(const T& data)
	{
		Node* x = new Node(data);
		tail->next = x;
		tail = x;
		size++;
	}

	/** 
         * @brief Adds a new node at a valid position index.
         *
         * This is achieved by first checking the position index to make sure 
         * its valid using the private @ref check_position_index() function. If
         * its the last valid position then we directly use the @ref add_last()
         * function, otherwise we link the node before the position we want to 
         * add at to the new node and then link the new node to the node after
         * it. The size is incremented by unity.        
         *
         * @param pos_index Position index at which the new node is to be 
         *                  added.
         * @param data Data of the node to be added.
         */
	void add(int pos_index, const T& data)
	{
		check_position_index(pos_index);
		if (pos_index == int(size)) {
			add_last(data);
			return;
		}
		Node* prev = head;
		for (int i = 0; i < pos_index; i++) {
			prev = prev->next;
		}
		Node* x = new Node(data);
		x->next = prev->next;
		prev->next = x;
		size++;
	}

	/* Erase functions */
	/**
         * @brief Deletes the first node in the list.
         *
         * This is achieved by first using the utility @ref is_empty() function
         * to check that the singly linked list is not empty and then linking
         * the head to the node after the first node and updating the tail if the
         * list contains only a single node after the operation. The size is
         * updated, the node's memory freed and its old value returned.
         *
         * @return The data of the first node that will be deleted.
         * @throws std::out_of_range if the list is empty. The exception message
         *         states that there are "No nodes to remove".
         */
	T del_first()
	{
		if (is_empty()) {
			throw std::out_of_range("No nodes to remove");
		}
		Node* first = head->next;
		head->next = first->next;
		if (size == 1) {
			tail = head;
		}
		size--;
		T data = first->data;
		delete first;
		return data;
	}

	/** 
         * @brief Deletes the last node in the list.
         *
         * This is achieved by first using the utility @ref is_empty() function
         * to check that the singly linked list is not empty and then getting
         * the data of the last node, freeing its memory and linking the node
         * before it @c nullptr. The size and tail pointer are updated and the
         * old data returned.
         *
         * @return The data of the ending node that will be deleted.
         * @throws std::out_of_range if the list is empty. The exception message
         *         states that there are "No nodes to remove".
         */
	T del_last()
	{
		if (is_empty()) {
			throw std::out_of_range("No nodes to remove");
		}
		Node* prev = head;
		while (prev->next != tail) {
			prev = prev->next;
		}
		T data = tail->data;
		delete tail;
		prev->next = nullptr;
		tail = prev;
		size--;
		return data;
	}

	/** 
         * @brief Delete a node at a particular index.
         *
         * This is achieved by using the private @ref check_element_index()
         * function to first check if the index is valid and then linking the
         * node before the node to be deleted to the node after the node to be 
         * deleted. If the index happens to be the last index of the list then
         * the tail pointer is updated. Lastly, the size is decremented by 
         * unity, the node's memory freed and its old data returned.
         * 
         * @return The data of the node that will be deleted. 
         */
	T del(int index)
	{
		check_element_index(index);
		Node* prev = head;
		for (int i = 0; i < index; i++) {
			prev = prev->next;
		}
		Node* x = prev->next;
		prev->next = x->next;
		if (index == int(size) - 1) {
			tail = prev;
		}
		size--;
		T data = x->data;
		delete x;
		return data;
	}

	/* Get functions */
	/** 
         * @brief Get the data stored in the first node.
         *
         * Uses the utility @ref is_empty() function to check if the first
         * element exists and if it does, returns the data in the first node.
         *
         * @return The data in the first node.
         * @throws std::out_of_range when the list is empty. The exception 
         *         message states that there are "No nodes in the list". 
         */
	T get_first() const
	{
		if (is_empty()) {
			throw std::out_of_range("No nodes in the list");
		}
		return head->next->data;
	}

	/** 
         * @brief Get the data stored in the last node.
         *
         * Uses the utility @ref is_empty() function to check if the last 
         * element exists and if it does, returns the data in the last node.
         *
         * @return The data in the last node.
         * @throws std::out_of_range when the list is empty. The exception 
         *         message states that there are "No nodes in the list".
         */
	T get_last() const
	{
		if (is_empty()) {
			throw std::out_of_range("No nodes in the list");
		}
		return tail->data;
	}

	/**
         * @brief Get the data stored in a node at a particular index.
         *
         * Uses the private @ref get_node() function to check if the index is
         * valid and returns the requested node's data.
         *
         * @param index Index of the element.
         * @return The data of the requested node.
         */
	T get(int index) const
	{
		Node* p = get_node(index);
		return p->data;
	}

	/* Set function */
	/** 
         * @brief Set the data in a node at a particular index.
         *
         * Uses the private @ref get_node() function to check if the index 
         * given is valid, sets its data and returns the old data.
         *
         * @param index Index of the node to be set.
         * @param data Value to be set to.
         */
	T set(int index, const T& data)
	{
		Node* p = get_node(index);
		T x = p->data;
		p->data = data;
		return x;
	}

	/* Utility functions */
	/** 
         * @brief Get the current size of the singly linked list.
         * @return Current size of the singly linked list.
         */
	size_t get_size() const { return size; }

	/** 
         * @brief Check if the singly linked list is empty.
         * @return true if the list contains no elements, false otherwise. 
         */
	bool is_empty() const { return size == 0; }

	/** 
         * @brief Display the values in the nodes of the singly linked list. 
         */
	void display() const
	{
		std::cout << "Size = " << size << '\n';
		Node* p = head->next;
		while (p != tail) {
			std::cout << p->data << "->";
			p = p->next;
		}
		std::cout << "nullptr" << '\n';
		std::cout << '\n';
	}

private:
	/** @brief Struct representing a node in a singly linked list */
	struct Node {
		T data; /** The data stored in the node. */
		Node* next; /** Pointer to the next node. */

		/**
                 * @brief Constructs a new node with given data and
                 *        initializes the value of the next pointer.
                 *
                 * @param val The value of the data to store in the node.
                 */
		Node(T val) : data(val), next(nullptr) {}
	};
	/** Dummy head node. */
	Node* head;
	/** Actual tail node. */
	Node* tail;
	/** Current size of the linked list. */
	size_t size;

	/** 
         * @brief Get the requested node.
         *
         * Checks if the requested element index is valid and efficiently gets 
         * the required node based on the requested index.
         *
         * @param index Index of the desired node.
         * @return Pointer to the requested node.
         */
	Node* get_node(int index) const
	{
		check_element_index(index);
		Node* p = head->next;
		for (int i = 0; i < index; i++) {
			p = p->next;
		}
		return p;
	}

	/** 
         * @brief Checks if a given element index is valid i.e in [0, size).
         * @param index Index to be checked.
         * @return true if valid, false otherwise.
         */
	bool is_element_index(int index) const
	{
		return index >= 0 && index < int(size);
	}

	/** 
         * @brief Checks if a position index is valid i.e in [0, size]. 
         * @param pos_index Position index to be checked.
         * @return true if valid, false otherwise.
         */
	bool is_position_index(int pos_index) const
	{
		return pos_index >= 0 && pos_index <= int(size);
	}

	/**
         * @brief Checks the given index and throws an exception if out of 
         *        range.
         * @param index Index to be checked.
         * @throws std::out_of_range is thrown when the index is out of the
         *         valid range i.e [0, size). The exception message includes
         *         the invalid index and the current size of the singly 
         *         linked list.
         */
	void check_element_index(int index) const
	{
		if (!is_element_index(index)) {
			throw std::out_of_range(
				"Index: " + std::to_string(index) +
				", Size: " + std::to_string(size));
		}
	}

	/**
         * @brief Checks the given position index and throws an exception if 
         *        out of range.
         * @param pos_index Position index to be checked.
         * @throws std::out_of_range is thrown when the position index is out
         *         of the valid range i.e [0, size]. The exception message 
         *         includes the invalid position index and the current size of
         *         the singly linked list.
         */
	void check_position_index(int pos_index) const
	{
		if (!is_position_index(pos_index)) {
			throw std::out_of_range(
				"Index: " + std::to_string(pos_index) +
				", Size: " + std::to_string(size));
		}
	}
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_LINKED_LIST_H
