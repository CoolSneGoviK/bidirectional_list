#pragma once

template <class T>
class List2 
{
public:
	void add_element(T data); // ���������� � ������
	void add_end(T data); // ���������� � �����
	void add_by_index(T data, int index = 0); // ���������� �� �������

	T& index_value(int index = 0); // ��������� �������� ��������
	T& operator [] (int index); // ��������� �������� ��������

	void show(); // ����� ���� ��������� ������

	void swap(int index1 = 0, int index2 = 0); // �������� ������� �������� � ������

	void delete_first(); // �������� ������� ��������
	void delete_last(); // �������� ���������� ��������
	void delete_by_index(int index = 0); // �������� �� �������
	void delete_all(); // �������� ���� ��������� ������

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
