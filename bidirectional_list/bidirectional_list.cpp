// двунаправленный список
#include "class2.h"
#include <iostream>
using namespace std;

int main()
{
	List2<int> N;
	N.add_element(1); // добавление элемента в конец
	N.add_element(2);
	N.add_element(3);
	N.add_element(4);
	N.add_element(5);
	N.add_element(6);
	N.add_element(7);

	//N.add_start(10); // добавление элемента в начало

	//N.add_by_index(100, 3); // добавление элемента по индексу
	
	//cout << N.index_value(3) << endl; // получение значения элемента по индексу (метод)
	//cout << N[3] << endl; // получение значения элемента по индексу (перегруженный оператор)

	///N.swap(0, 6); // меняет местами значения в списке 

	//N.delete_first(); // удаление первого элемента

	N.show_start_end(); // вывести все элементы списка с head
	N.show_end_start(); // вывести все элементы списка с tail

	system("pause");
	return 0;
}

