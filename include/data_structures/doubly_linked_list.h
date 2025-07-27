/** @brief Implementation of doubly linked list data structure. */

#ifndef DATA_STRUCTURES_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURES_DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

namespace DataStructures {

/**
 * @class DoublyLinkedList
 * @brief Doubly linked list class with all related functionality.
 * @tparam T Type of the implementation class.
 */
template <typename T>
class DoublyLinkedList {
public:
	/**
         * @brief Constructor for the DoublyLinkedList class.
         *
         * Initializes the head and tail pointers by linking them to each other.
         */
	DoublyLinkedList()
	{
		head = new Node(T());
		tail = new Node(T());
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	/**
         * @brief Destructor for the DoublyLinkedList class.
         *
         * Clears the doubly linked list and deletes the head and tail 
         * pointers.
         */
	~DoublyLinkedList()
	{
		while (size > 0) {
			del_first();
		}
		delete head;
		delete tail;
	}

	/* Insert functions */
	/**
         * @brief Adds a new node at the start of the doubly linked list.
         *
         * This is achieved by first linking the new node before the currently 
         * first node and then consequently linking the head to this new start 
         * node. The size of the doubly linked list is incremented by unity.
         *
         * @param data The data of the node.
         */
	void add_first(const T& data)
	{
		Node* x = new Node(data);
		Node* temp = head->next;
		temp->prev = x;
		x->next = temp;
		head->next = x;
		x->prev = head;
		size++;
	}

	/** 
         * @brief Adds a new node at the end of a doubly linked list.
         *
         * This is achieved by first linking the new node after the currently 
         * last node and then consequently linking the tail to this new end 
         * node. The size of the doubly linked list is incremented by unity.
         *
         * @param data The data of the node.
         */
	void add_last(const T& data)
	{
		Node* x = new Node(data);
		Node* temp = tail->prev;
		temp->next = x;
		x->prev = temp;
		x->next = tail;
		tail->prev = x;
		size++;
	}

	/** 
         * @brief Adds a new node at a valid position index.
         *
         * This is achieved by first checking the position index to make sure 
         * its valid. If its the last valid position then we directly use the
         * @ref add_last() function, otherwise we link the node before the node
         * at the desired position to the our new node and then link the new 
         * node to the original node that was at its position.
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
		Node* p = get_node(pos_index);
		Node* temp = p->prev;
		Node* x = new Node(data);
		temp->next = x;
		x->prev = temp;
		x->next = p;
		p->prev = x;
		size++;
	}

	/* Delete functions */
	/**
         * @brief Delete the first node in the list.
         *
         * This is achieved by first checking that the doubly linked list is 
         * not empty and then linking the head to the next node after the first 
         * node. Memory of the node is freed, the size is updated and its data
         * returned.
         *
         * @return The data of the first node that will be deleted.
         */
	T del_first()
	{
		if (size == 0) {
			throw std::out_of_range("No elements to remove");
		}
		Node* x = head->next;
		Node* temp = x->next;
		head->next = temp;
		temp->prev = head;
		T data = x->data;
		delete x;
		size--;
		return data;
	}

	/** 
         * @brief Delete the last node in the list.
         *
         * This is achieved by first checking that the doubly linked list is 
         * not empty and then linking the second last node to the tail. Memory 
         * of the node is freed, the size is updated and its data is returned.
         *
         * @return The data of the ending node that will be deleted.
         */
	T del_last()
	{
		if (size == 0) {
			throw std::out_of_range("No elements to remove");
		}
		Node* x = tail->prev;
		Node* temp = tail->prev->prev;
		tail->prev = temp;
		temp->next = tail;
		T data = x->data;
		x->prev = nullptr;
		x->next = nullptr;
		delete x;
		size--;
		return data;
	}

	/** 
         * @brief Delete a node at a particular index.
         *
         * This is achieved by first checking if the index is valid and then
         * linking the node previous to the node in concern and the node next 
         * to it. Memory of the node to be deleted is freed, its size updated 
         * and data returned.
         *
         * @return The data of the node that will be deleted. 
         */
	T del(int index)
	{
		check_element_index(index);
		Node* x = get_node(index);
		Node* prev = x->prev;
		Node* next = x->next;
		prev->next = next;
		next->prev = prev;
		T data = x->data;
		x->prev = nullptr;
		x->next = nullptr;
		delete x;
		size--;
		return data;
	}

	/* Get Functions */
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
		return tail->prev->data;
	}

	/**
         * @brief Get the data stored in a node at a particular index.
         *
         * Uses the private @ref get_node() function to check if the node index
         * is valid and returns the requested node's data.
         *
         * @param index Index of the element.
         * @return The data of the requested node.
         */
	T get(int index)
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
	T set(int index, T data)
	{
		Node* p = get_node(index);
		T old_val = p->data;
		p->data = data;
		return old_val;
	}

	/* Utility functions */
	/** 
         * @brief Get the current size of the doubly linked list.
         * @return Current size of the doubly linked list.
         */
	size_t get_size() const { return size; }

	/** 
         * @brief Check if the doubly linked list is empty.
         * @return true if the list contains no elements, false otherwise. 
         */
	bool is_empty() const { return size == 0; }

	/** 
         * @brief Display the values in the nodes of the doubly linked list. 
         */
	void display() const
	{
		std::cout << "Size = " << size << '\n';
		Node* p = head->next;
		while (p != tail) {
			std::cout << p->data << " <-> ";
			p = p->next;
		}
		std::cout << "nullptr" << '\n';
		std::cout << '\n';
	}

private:
	/** @brief Struct representing a node in a doubly linked list. */
	struct Node {
		/** The data stored in the node. */
		T data;
		/** Pointer to the previous node. */
		Node* prev;
		/** Pointer to the next node. */
		Node* next;

		/**
                 * @brief Constructs a new node with the given data and
                 *        initializes prev and next to nullptr.
                 *
                 * @param val The value of the data to store in the node.
                 */
		Node(T val) : data(val), prev(nullptr), next(nullptr) {}
	};
	/** Dummy head node. */
	Node* head;
	/** Dummy tail node. */
	Node* tail;
	/** Current size of the doubly linked list. */
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
	Node* get_node(int index)
	{
		check_element_index(index);
		Node* p = head->next;
		if (index < int(size) / 2) {
			p = head->next;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
		} else {
			p = tail->prev;
			for (int i = int(size) - 1; i > index; i--) {
				p = p->prev;
			}
		}
		return p;
	}

	/** 
         * @brief Checks if the given element index is valid i.e in [0, size).
         * @param index Index to be checked.
         * @return true if the element index is valid, false otherwise.
         */
	bool is_element_index(int index) const
	{
		return index >= 0 && index < int(size);
	}

	/** 
         * @brief Checks if the given position index is valid i.e in [0, size].
         * @param pos_index Index to be checked.
         * @return true if the position index is valid, false otherwise.
         */
	bool is_position_index(int pos_index) const
	{
		return pos_index >= 0 && pos_index <= int(size);
	}

	/** 
         * @brief Checks the given index and throws an exception if out of 
         *        range.
         * @param index Index to be checked.
         * @throws std::out_of_range thrown when the index is out of the valid 
         *         range i.e [0, size). The exception message includes the 
         *         invalid index and the current size of the doubly linked 
         *         list. 
         */
	void check_element_index(int index) const
	{
		if (!is_element_index(index)) {
			throw std::out_of_range(
				"Element Index: " + std::to_string(index) +
				", Size: " + std::to_string(size));
		}
	}

	/** 
         * @brief Checks the given position and throws an exception if out of
         *        range.
         * @param pos_index Position index to be checked.
         * @throws std::out_of_range thrown when the position index is out of 
         *         the valid range i.e [0, size]. The exception message 
         *         includes the invalid position index and the current size of
         *         the doubly linked list. 
         */
	void check_position_index(int pos_index) const
	{
		if (!is_position_index(pos_index)) {
			throw std::out_of_range(
				"Position Index: " + std::to_string(pos_index) +
				", Size: " + std::to_string(size));
		}
	}
};

} // namespace DataStructures

#endif // DATA_STRUCTURES_DOUBLY_LINKED_LIST_H
