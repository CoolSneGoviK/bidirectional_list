#pragma once

#include <iostream>
using namespace std;

template <class T>
class List2 
{
public:
	List2() {};
	~List2() {};

	void add_element(T data); // ���������� � �����
	void add_start(T data); // ���������� � ������
	void add_by_index(T data, int index = 0); // ���������� �� �������

	T& index_value(int index = 0); // ��������� �������� ��������
	T& operator [] (int index); // ��������� �������� ��������

	void show_start_end(); // ����� ���� ��������� ������ � head (� ������) +
	void show_end_start(); // ����� ���� ��������� ������ � tail (� ������) +

	void swap(int index1 = 0, int index2 = 0); // �������� ������� �������� � ������

	void delete_first(); // �������� ������� ��������
	void delete_last(); // �������� ���������� ��������
	void delete_by_index(int index = 0); // �������� �� �������
	void delete_all(); // �������� ���� ��������� ������

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


