#pragma once
#include <iostream>


const unsigned int DEFAULT_CAPACITY = 256;

template <class T>
class Stack {
private:
	T* data;
	unsigned long long capacity;
	unsigned long long size;
public:
	
	Stack<T>(int s = DEFAULT_CAPACITY) : capacity(s), size(0){
		data = new T[capacity];
	}
	
	Stack<T>(Stack<T>& old): capacity(old.capacity), size(old.size) {
		data = new T[capacity];
		for (int i = 0; i < size; i++)
			data[i] = old.data[i];
	}
	
	~Stack<T>() {
		delete[] data;
	}

	void incCapacity() {
		T* nd = new T[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			nd[i] = data[i];
		}
		delete[] data;
		data = nd;
	}

	int getSize() {
		return size;
	}

	bool empty() {
		return size == 0;
	}

	T getTop() {
		if (size == 0)
			throw std::exception();
		return data[size - 1];
	}

	void push(T i) {
		if (size >= capacity) {
			incCapacity();
		}
		data[size] = i;
		size++;
	}

	void pop() {
		if (size == 0) {
			throw std::exception();
		}
		size--;
	}



};


