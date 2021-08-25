#pragma once

template <class T>
class List2 
{
public:
	List2() {};
	~List2() {};

	void add_element(T data); // добавление в конец
	void add_start(T data); // добавление в начало
	void add_by_index(T data, int index = 0); // добавление по индексу

	T& index_value(int index = 0); // получение значения элемента
	T& operator [] (int index); // получение значения элемента

	void show(); // вывод всех элементов списка

	void swap(int index1 = 0, int index2 = 0); // поменять местами значения в списке

	void delete_first(); // удаление первого элемента
	void delete_last(); // удаление последнего элемента
	void delete_by_index(int index = 0); // удаление по индексу
	void delete_all(); // удаление всех элементов списка

private:
	template <class T>
	class Node 
	{
	public:
		Node(T data = T(), Node<T>* next = nullptr, Node<T>* previos = nullptr)
		{
			this->data = data;
			this->next = next;
			this->previos = previos;
		};

		~Node() {};

		Node<T>* next = nullptr;
		Node<T>* previos = nullptr;
		T data = T();
	};

	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int Size = 0;
};

template <class T>
void List2<T>::add_element(T data) 
{ 
	if (head = nullptr) 
	{ // если список пуст
		head = new Node<T>(data);
		Size++;
		return;
	}

}
