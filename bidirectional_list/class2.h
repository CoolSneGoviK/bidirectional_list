#pragma once

#include <iostream>
using namespace std;

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

	void show_start_end(); // вывод всех элементов списка с head (с головы) +
	void show_end_start(); // вывод всех элементов списка с tail (с хвоста) +

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

	Node<T>* current = head;
	while (head) 
	{ // если не пуст // добавить приравнивание последнего элемент а tail и с указателями понять что как
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
}

template <class T> // вывод элементов с head
void List2<T>::show_start_end()
{
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


