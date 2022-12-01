#pragma once
#include <iostream>


const unsigned int DEFAULT_CAPACITY = 256;

template <class T>
class Queue {
private:
	T* data;
	int top;
	int bot;
	int capacity;
	int size;
public:

	Queue<T>(int s = DEFAULT_CAPACITY) : capacity(s), size(0) {
		data = new T[capacity];
		bot = 0;
		top = -1;
	}

	Queue<T>(Queue<T>& old) : capacity(old.capacity), size(old.size), top(old.top), bot(old.bot) {
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = old.data[i];
	}

	~Queue<T>() {
		delete[] data;
	}

	void incCapacity() {

		T* nd = new T[(capacity + (unsigned long long)1) * (unsigned long long)2];
		if(top >= bot)
			for (int i = 0; i <= top; i++) {
				nd[i] = data[i];
			}
		else {
			int i = 0;
			for (int j = bot; j < capacity; j++) {
				nd[i] = data[j];
				i++;
			}
			for (int j = 0; j <= top; j++) {
				nd[i] = data[j];
				i++;
			}
			bot = 0;
			top = i - 1;
		}
		capacity = (capacity + (unsigned long long)1) * (unsigned long long)2;
		delete[] data;
		data = nd;
	}

	int getSize() {
		return size;
	}

	bool empty() {
		return size == 0;
	}

	bool full() {
		return size == capacity;
	}

	T getTop() {
		if (size == 0)
			throw std::exception();
		return data[top];
	}

	T getBottom() {
		if (size == 0)
			throw std::exception();
		return data[bot];
	}

	void push_front(T i) {

		if (size == capacity)
			incCapacity();

		if (top == capacity - 1)
			top = 0;
		else
			top++;

		data[top] = i;
		size++;

	}

	void pop_back() {
		if (size == 0)
			throw std::exception();

		if (bot == capacity - 1)
			bot = 0;
		else
			bot++;


		size--;
	}



};