#pragma once

const int STACK_MAX_SIZE = 1000000;

template<class T>
class TStack {
private:
	T* array;
	int maxsize;
	int size;

public:
	TStack(int ms = 100); //конструктор с параметром
	TStack(const TStack& ts); //конструктор копирования
	~TStack(); //деструктор
	TStack& operator=(const TStack& ts); //присваивание
	void clear(); //очистить стек
	bool isFull(); //заполнен ли стек?
	bool isEmpty(); //пуст ли стек?
	T top(); //вершина стека
	T pop(); //удалить элемент из стека
	void push(const T& element); //добавить элемент в стек
	T operator[](int pos);
	bool operator!=(const TStack& s) const;
	bool operator==(const TStack& s) const;
};

template<class T>
TStack<T>::TStack(int ms) {
	if (ms <= 0 || ms > STACK_MAX_SIZE) throw ms;
	maxsize = ms;
	size = 0;
	array = new T[maxsize];
}

template<class T>
TStack<T>::TStack(const TStack<T>& ts) {
	maxsize = ts.maxsize;
	size = ts.size;
	array = new T[maxsize];
	for (int i = 0; i < size; i++) array[i] = ts.array[i];
}

template<class T>
TStack<T>::~TStack() {
	delete[] array;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack& s) {
	maxsize = s.maxsize;
	size = s.size;
	if (array!=0) delete[] array;
	array = new T[maxsize];
	for (int i = 0; i < size; i++)
		array[i] = s.array[i];
	return *this;
}

template<class T>
bool TStack<T>::isFull() {
	return size == maxsize;
}

template<class T>
bool TStack<T>::isEmpty() {
	return size == 0;
}

template<class T>
T TStack<T>::top() {
	if (isEmpty()) throw - 1;
	return array[size - 1];
}

template<class T>
T TStack<T>::pop() {
	if (isEmpty()) throw - 1;
	size--;
	return array[size];
}

template<class T>
void TStack<T>::push(const T& element) {
	if (isFull())
	{
		maxsize *= 2.0;
		T* temp = new int[maxsize];
		memmove(temp, array, sizeof(array) * size);
		delete[] array;
		array = temp;
	}
	array[size] = element;
	size++;;
}

template<class T>
void TStack<T>::clear() {
	size = 0;
}

template <class T>
T TStack<T>::operator[](int pos) {
	if (pos < 0 || pos > maxsize) throw -1;
	return array[pos];
}

template <class T>
bool TStack<T>::operator!=(const TStack& s) const {
	return !(s == *this);
}

template <class T>
bool TStack<T>::operator==(const TStack& s) const {
	if ((size != s.size) || (maxsize != s.maxsize))	return false;
	for (int i = 0; i < maxsize; i++)
	{
		if (array[i] != s.array[i])	return false;
	}
	return true;
}

template <class T>
class TQueue : public TStack <T> {
protected:
	TStack<T> St_1, St_2;
	int start_index;
	public:
		TQueue(int s=7) {
			TStack <T> temp(s);
			St_1 = St_2 = temp;
			start_index = 0;
		}

		~TQueue() {}

		void pop() {
			while (!St_1.isEmpty())
			{
				St_2.push(St_1.top());
				St_1.pop();
			}
			St_2.pop();
			while (!St_2.isEmpty())
			{
				St_1.push(St_2.top());
				St_2.pop();
			}
		}

		void push(int n) {
			St_1.push(n);
		}
		
		bool operator==(const TQueue& q) {
			if ((!q.St_1.isEmpty()) && (!St_1.isEmpty()))
				if (St_1 == q.St_1) return true;
			if ((!q.St_2.isEmpty()) && (!St_2.isEmpty()))
				if (St_2 == q.St_2) return true;
			return false;
		}

		bool operator!=(const TQueue& q) {
			if (q == *this) return false;
			return true;
		}

		T operator[](int pos) {
			if (St_2.isEmpty()) return St_1[pos + start_index];
			return St_2[pos];
		}
};