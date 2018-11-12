#pragma once

template<class T>
class Collection {
protected:
	Collection() {

	}
	~Collection() {

	}

	virtual void pushBack(T) = 0;
	virtual const T popBack() = 0;
	virtual const bool isEmpty() = 0;
	virtual const size_t size() = 0;
	virtual void print() = 0;
	virtual void reverse() = 0;
};
