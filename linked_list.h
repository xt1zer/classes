#pragma once

#include "collection.h"
#include <iostream>

template<class T>
class List : public Collection<T> {
private:
    class Node {
    public:
        Node *_next;
        Node *_prev;
        T _data;
    };

    Node *_head;
    Node *_tail;

public:
    List() : _head(nullptr), _tail(nullptr) {}

    List(const T arr[]){
        for(const T &n: arr)
            this->push_back(n);
    }

    List(const List & copy): _head(nullptr), _tail(nullptr) {
        Node *temp = copy._head;

        while (temp != nullptr) {
            push_back(temp->_data);
            temp = temp->_next;
        }
    }

    ~List() {
        while (_head) {
            _tail = _head->_next;
            delete _head;
            _head = _tail;
        }
    }

    List<T> & operator=(List l){
//        this->~List();
//        Node *temp = l._head;
//
//        while (temp != nullptr) {
//            push_back(temp->_data);
//            temp = temp->_next;
//        }
//

//        List<T> tmp(l);
        std::swap(_head, l._head);
        std::swap(_tail, l._tail);

        return *this;
    }

    Node *find_node(const T &data) {
        if (is_empty())
            std::exit(1);

        Node *temp = _head;
        while (temp != nullptr) {
            if (temp->_data == data)
                break;
            temp = temp->_next;
        }

        return temp;
    }

    void push_back(const T &data) {
        Node *newNode = new Node;
        newNode->_data = data;
        newNode->_next = nullptr;

        if (is_empty()) {
            newNode->_prev = nullptr;
            _head = _tail = newNode;
        } else {
            newNode->_prev = _tail;
            _tail->_next = newNode;
            _tail = newNode;
        }
    }

    void push_front(const T &data) {
        Node *newNode = new Node;
        newNode->_data = data;
        newNode->_next = _head;
        newNode->_prev = nullptr;

        if (!is_empty())
            _head->_prev = newNode;
        else
            _tail = newNode;

        _head = newNode;
    }

    const T pop_back() {
        if (is_empty())
            std::exit(1);

        Node *temp = _tail;
        const T data = temp->_data;

        _tail = _tail->_prev;

        if (_tail)
            _tail->_next = nullptr;
        if (temp == _head)
            _head = nullptr;

        delete temp;

        return data;
    }

    const T pop_front() {
        if (is_empty())
            std::exit(1);

        Node *temp = _head;
        const T data = temp->_data;

        _head = _head->_next;

        if (_head)
            _head->_prev = nullptr;
        if (temp == _tail)
            _tail = nullptr;

        delete temp;

        return data;
    }

    const bool is_empty() const {
        return _head == nullptr;
    }

    const size_t size() const {
        if (is_empty())
            return 0;

        size_t num = 0;
        for (Node *temp = _head; temp != nullptr; temp = temp->_next)
            ++num;

        return num;
    }

	void print() const {
        if (is_empty())
            return;

        for (Node * temp = _head; temp != nullptr; temp = temp->_next)
            std::cout << temp->_data << " ";
    }

    void reverse() {
        if (is_empty())
            return;

        for (;;) {
            std::swap(_head->_prev, _head->_next);

            Node *temp = _head->_prev;
            if (temp == nullptr)
                break;

            _head = temp;
        }
    }
};
