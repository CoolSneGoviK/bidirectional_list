#pragma once

#include <iostream>
using namespace std;

template <class T>
class List2 
{
public:
	List2() {};
	~List2() {};

	void add_element(T data = T()); // ���������� � ����� +
	void add_start(T data = T()); // ���������� � ������ +
	void add_by_index(T data = T(), int index = 0); // ���������� �� �������, ���� ��������� ���������� � 0 +

	T& index_value(int index = 0); // ��������� �������� ��������, ���� ��������� ���������� � 0 (�����) +
	T& operator [] (int index); // ��������� �������� ��������, ���� ��������� ���������� � 0 (������������� ��������) +

	void show_start_end(); // ����� ���� ��������� ������ � head (� ������) +
	void show_end_start(); // ����� ���� ��������� ������ � tail (� ������) +

	void swap(int index1 = 0, int index2 = 0); // �������� ������� �������� � ������ +

	void delete_first(); // �������� ������� ��������
	void delete_last(); // �������� ���������� ��������
	void delete_by_index(int index = 0); // �������� �� �������
	void delete_all(); // �������� ���� ��������� ������

	int get_Size() { return Size; }; // ��� ��������� ����������� ���������

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

template <class T> // ���������� �������� � ����� ������
void List2<T>::add_element(T data) 
{ 
	if (head == nullptr) 
	{ // ���� ������ ����
		head = new Node<T>(data);
		Size++;
		return;
	}

	Node<T>* current = head;
	while (head) 
	{ // ���� �� ���� // �������� ������������� ���������� ������� � tail � � ����������� ������ ��� ���
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

template <class T> // ���������� �������� ������ � ������
void List2<T>::add_start(T data)
{
	if (Size == 0) 
	{ // ���� ������ ������
		add_element(data);
		return;
	}

	Node<T>* current = new Node<T>(data, nullptr, head);
	head->previos = current;
	head = current;
	Size++;
};

template <class T> // ���������� ��������� �� �������, ���� ��������� ���������� � 0
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
	Node<T>* new_node = nullptr; // ����� ����

	while (head) 
	{ 
		if (counter == index - 1) 
		{ // ����� ������� �� ������� ����� �������� �����
			new_node = new Node<T>(data, head, head->next); // �������� ��������/��������� �� ����������/��������� �� ���������
			head->next = new_node;
			head->next->next->previos = new_node;
			head = current;
			break;
		}
		head = head->next;
		counter++;
	}
};

template <class T> // ���������� �������� �������� �� ��������� �������, ������� �� 0
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

template <class T> // ���������� �������� �������� �� ��������� �������, ������� �� 0
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

template <class T> // ����� ��������� � head
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

template <class T> // ����� ��������� � tail
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

template <class T> // ������ ������� �������� � ������ 
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

