#pragma once
template<class T>
class Vector
{
protected:
	T* data;
	size_t size;
	size_t capacity;
public:
	Vector()
	{
		data = nullptr;
		size = capacity = 0;
	}

	~Vector()
	{
		delete[]data;
		data = nullptr;
	}

	Vector(int n)
	{
		size = capacity = n;
		data = new T[n];
		for (int i = 0; i < n; i++) data[i] = 0;
	}

	Vector(int n, T* array)
	{
		size = capacity = n;
		data = new T[size];
		for (size_t i = 0; i < size; i++) data[i] = array[i];
	}

	Vector(const Vector& v)
	{
		delete[]data;
		size = v.size;
		capacity = v.capacity;
		T* data = new T[size];
		for (size_t i = 0; i < size; i++) data[i] = v.data[i];
	}

	void push_back(T elem)
	{
		if (size == capacity)
		{
			capacity = 1.5 * size;
			T* temp = new T[capacity];
			for (int i = 0; i < size; i++)	temp[i] = data[i];
			if (data != nullptr)
				delete[] data;
			data = temp;
		}
		data[size++] = elem;
	}

	void pop_back()
	{
		size--;
	}

	void resize(int n)
	{
		T* temp = new T[n];
		unsigned int i;
		if (n > size)
		{
			for (i = 0; i < size; i++) temp[i] = data[i];
			for (i = size; i < n; i++) temp[i] = 0;
		}
		else
			for (i = 0; i < n; i++) temp[i] = data[i];
		if (data != nullptr)
			delete[] data;
		data = temp;
	}

	void insert(T Elem, int index)
	{
		T* temp = new T[size + 1];
		unsigned int i;
		for (int i = 0; i < index; i++) temp[i] = data[i];
		temp[index] = Elem;
		for (i = index; i < size; i++) temp[i + 1] = data[i];
		if (data != nullptr)
			delete[] data;
		data = temp;
	}

	void erase(int index)
	{
		T* temp = new T[capacity];
		for (int i = 0; i < index - 1; i++)
			temp[i] = data[i];
		for (int i = index - 1; i < size; i++)
			temp[i] = data[i + 1];
		delete[]data;
		data = temp;
		size--;
	}

	T& operator[](int index)
	{
		return this->data[index];
	}
	T operator[](int index)const
	{
		return this->data[index];
	}
}; 

/*.........................................................*/

template <class T>
class Queue : protected Vector<T> {
private:
	int start, end;
	void resize(int n) {//переопределение перепаковки
		T* temp = new T[n];
		if (start < end)
		{
			for (size_t i = start; i <= end; i++) temp[i - start] = data[i];
		}
		else {
			for (size_t i = start; i < size; i++) temp[i - start] = data[i];
			for (size_t i = 0; i <= end; i++) temp[i + size - start] = data[i];
		}
		if (data) delete[]data;
		data = temp;
	}
public:
	Queue() :Vector() {
		start = end = 0;
	}

	Queue(int n) :Vector(n) {
		start = 0;
		end = size - 1;
	}

	~Queue() {}

	T Front() {
		return data[start];
	}

	T Back() {
		return data[end];
	}

	void push(T elem) {
		if (full()) resize(size_t(2.0 * capacity));
		end++;
		if (end == capacity) end = 0;
		data[end] = elem;
		size++;
	}

	void pop() {
		if (size == 0) throw - 1;
		start++;
		size--;
		if (start == capacity ) start = 0;
	}

	bool empty() {
		return (size == 0);
	}

	bool full() {
		return (size == capacity);
	}

	T operator[](int index)const {
		return this->data[index];
	}
};

