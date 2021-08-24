#pragma once

template <class T>
class List2 
{
public:
	void add_element(T data); // добавление в начало
	void add_end(T data); // добавление в конец
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
		Node* next = nullptr;
		Node* previos = nullptr;
		T data = T();
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int Size = 0;
};
