#pragma once

#include <iostream>
using namespace std;

template <class T>
class List2 
{
public:
	List2() {};
	~List2() { delete_all(); };

	void add_element(T data = T()); // добавление в конец +
	void add_start(T data = T()); // добавление в начало +
	void add_by_index(T data = T(), int index = 0); // добавление по индексу, счет элементов начинается с 0 +

	T& index_value(int index = 0); // получение значения элемента, счет элементов начинается с 0 (метод) +
	T& operator [] (int index); // получение значения элемента, счет элементов начинается с 0 (перегруженный оператор) +

	void show_start_end(); // вывод всех элементов списка с head (с головы) +
	void show_end_start(); // вывод всех элементов списка с tail (с хвоста) +

	void swap(int index1 = 0, int index2 = 0); // поменять местами значения в списке +

	void delete_first(); // удаление первого элемента +
	void delete_last(); // удаление последнего элемента +
	void delete_by_index(int index = 0); // удаление по индексу +
	void delete_all(); // удаление всех элементов списка +

	int get_Size() { return Size; }; // для получения колличества элементов +

private:
	template <class T>
	class Node 
	{
	public:
		Node(T data = T(), Node<T>* previos = nullptr, Node<T>* next = nullptr)
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

template <class T> // добавление элемента в конец списка
void List2<T>::add_element(T data) 
{ 
	if (head == nullptr) 
	{ // если список пуст
		head = new Node<T>(data);
		Size++;
		return;
	}

	// это новое решение, что бы не проходить по всему списку каждый раз, добавляем сразу в конец с помощью tail, работает
	if (tail == nullptr) 
	{ // значит в списке 1 элемент хранящийся в head
		tail = new Node<T>(data, head, nullptr);
		head->next = tail;
		Size++;
		return;
	}

	Node<T>* last = new Node<T>(data, tail, nullptr);
	tail->next = last;
	tail = last;
	Size++;

	// эта версия работает, но попробую подругому
	/* 
	Node<T>* current = head;
	while (head) 
	{ // если список не пуст
		if (head->next == nullptr)
		{
			tail = new Node<T>(data, head, nullptr);
			head->next = tail;
			head = current;
			Size++;
			break;
		}
		head = head->next;
	}
	*/
}

template <class T> // добавление элемента списка в начало
void List2<T>::add_start(T data)
{
	if (Size == 0) 
	{ // если список пустой
		add_element(data);
		return;
	}

	Node<T>* current = new Node<T>(data, nullptr, head);
	head->previos = current;
	head = current;
	Size++;
};

template <class T> // добавление элементов по индексу, счет элементов начинается с 0
void List2<T>::add_by_index(T data, int index)
{
	if (index == Size)
	{
		add_element(data);
		return;
	}

	if (index > Size) 
	{
		cout << "error" << endl;
		return;
	}

	if (index == 0) 
	{
		add_start(data);
		return;
	}

	int counter = 0;
	Node<T>* current = head;
	Node<T>* new_node = nullptr; // новый узел

	while (head) 
	{ 
		if (counter == index - 1) 
		{ // нашли элемент за которым нужно вставить новый
			new_node = new Node<T>(data, head, head->next); // передаем значение/указатель на предыдущий/указатель на следующий
			head->next = new_node;
			head->next->next->previos = new_node;
			head = current;
			break;
		}
		head = head->next;
		counter++;
	}
};

template <class T> // возвращает значение элемента по заданному индексу, считает от 0
T& List2<T>::index_value(int index)
{
	if (index == 0) 
	{
		return head->data;
	}

	if (index == Size - 1) 
	{
		return tail->data;
	}

	if (index > Size -1) 
	{
		cout << "error" << endl;
		return head->data;
	}

	int counter = 0;
	Node<T>* current = head;

	while (head) 
	{
		if (counter == index) 
		{
			Node<T>* current2 = head;
			head = current;
			return current2->data;
		}
		counter++;
		head = head->next;
	}
};

template <class T> // возвращает значение элемента по заданному индексу, считает от 0
T& List2<T>::operator[](int index)
{
	if (index == 0)
	{
		return head->data;
	}

	if (index == Size - 1)
	{
		return tail->data;
	}

	if (index > Size - 1)
	{
		cout << "error" << endl;
		return head->data;
	}

	int counter = 0;
	Node<T>* current = head;

	while (head)
	{
		if (counter == index)
		{
			Node<T>* current2 = head;
			head = current;
			return current2->data;
		}
		counter++;
		head = head->next;
	}
};

template <class T> // вывод элементов с head
void List2<T>::show_start_end()
{
	if (Size == 0)
	{
		cout << "list is empty" << endl;
		return;
	}

	Node<T>* current = head;
	while (head) 
	{
		cout << head->data << " ";
		
		if (head->next == nullptr)
		{
			cout << endl;
			head = current;
			break;
		}
		
		head = head->next;
	}
};

template <class T> // вывод элементов с tail
void List2<T>::show_end_start() 
{
	if (Size == 0) 
	{
		cout << "list is empty" << endl;
		return;
	}

	Node<T>* current = tail;
	while (tail) 
	{
		cout << tail->data << " ";
		
		if (tail->previos == nullptr) 
		{
			cout << endl;
			tail = current;
			break;
		}
		
		tail = tail->previos;
	}
}

template <class T> // меняет местами значения в списке 
void List2<T>::swap(int index1, int index2)
{
	if (index1 < 0 || index2 < 0) 
	{
		cout << "error" << endl;
		return;
	}

	if (index1 > (Size - 1) || index2 > (Size - 1) )
	{
		cout << "error" << endl;
		return;
	}
	
	T current = index_value(index1);
	index_value(index1) = index_value(index2);
	index_value(index2) = current;
};

template <class T> // удаление первого элемента
void List2<T>::delete_first()
{ // как работает с head и tail когда например 2 элемента в списке, проверить на правильность нужно.
	if (head == nullptr)
	{ // если список пуст
		cout << "error - list is empty" << endl;
		return;
	}

	if (head == tail) 
	{
		Node<T>* delete_element = head;
		tail = nullptr;
		head = nullptr;
		delete delete_element;
		Size--;
		return;
	}

	Node<T>* delete_element = head; // присваиваем head указателю, что бы в дальнейшем удалить 1 элемент 
	head = head->next; // head присваиваем следующий элемент в списке
	head->previos = nullptr; // теперь этот элемент первый и перед ним ничего нет
	delete delete_element; // удалили 1 элемент
	Size--;
};

template <class T>
void List2<T>::delete_last() 
{
	Node<T>* last = tail;
	tail = tail->previos;
	tail->next = nullptr;
	delete last;
	Size--;
}

template <class T>
void List2<T>::delete_by_index(int index)
{
	if (index == (Size-1))
	{ // если индекс указывает на последний элемент
		delete_last();
		return;
	}

	if (index > (Size-1))
	{
		cout << "error" << endl;
		return;
	}

	if (index == 0)
	{
		delete_first();
		return;
	}

	int counter = 0;
	Node<T>* current = head;

	while(head) 
	{
		if (counter == index - 1) 
		{ // значит нашли элемент, после которого нужно удалить элемент
			Node<T>* delete_element = head->next;
			head->next = head->next->next; // теперь next показывает через 1 элемент
			
			head->next->previos = head->next->previos->previos;
			delete delete_element;
			Size--;
			head = current;
			break;
		}

		counter++;
		head = head->next;
	}
}

template <class T> // удаляет все элементы
void List2<T>::delete_all()
{ // пока не работает, не понятна ситуация с концом списка при удалении
	while (head)
	{
		delete_first();
	}
};

