#pragma once
#include "collection.h"
#include <iostream>

template<class T>
class List : public Collection<T> {
private:
	struct Node {
		Node * next;
		Node * prev;
		T data;
	};

	Node * head;
	Node * tail;

public:
	List() :head(nullptr), tail(nullptr) {}

	~List() {
		while (head) {
			tail = head->next;
			delete head;
			head = tail;
		}
	}

	void pushBack(T data) {
		Node * temp = new Node;
		temp->data = data;
		temp->next = nullptr;

		if (isEmpty()) {
			temp->prev = nullptr;
			head = tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	void pushFront(T data) {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		newNode->prev = nullptr;

		if (!isEmpty())
			head->prev = newNode;

		head = newNode;
	}

	const T popBack() {
		if (isEmpty())
			std::exit(1);

		Node * temp = tail;
		T data = temp->data;

		tail = tail->prev;

		if (tail)
			tail->next = nullptr;
		if (temp == head)
			head = nullptr;

		delete temp;

		return data;
	}

	const T popFront() {
		if (isEmpty())
			std::exit(1);

		Node * temp = head;
		T data = temp->data;

		head = head->next;

		if (head)
			head->prev = nullptr;
		if (temp == tail)
			tail = nullptr;

		delete temp;

		return data;
	}

	const bool isEmpty() {
		return head == nullptr;
	}

	const size_t size() {
		if (isEmpty())
			return 0;

		size_t num = 0;
		for (Node * temp = head; temp != nullptr; temp = temp->next)
			++num;

		return num;
	}

	void print() {
		if (isEmpty())
			return;

		for (Node * temp = head; temp != nullptr; temp = temp->next)
			std::cout << temp->data << " ";
	}

	void reverse() {
		if (isEmpty())
			return;

		// method one
		//Node * p = head;
		//while (p != nullptr) {
		//	Node * temp = p->next;
		//	p->next = p->prev;
		//	p->prev = temp;
		//	p = temp;
		//}
		//p = tail;
		//tail = head;
		//head = p;

		// method two
		for (;;) {
			std::swap(head->prev, head->next);

			Node * temp = head->prev;
			if (temp == nullptr)
				break;

			head = temp;
		}
	}
};
