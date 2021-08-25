// двунаправленный список
#include "class2.h"
#include <iostream>
using namespace std;

int main()
{
	List2<int> N;
	N.add_element(1);
	N.add_element(2);
	N.add_element(3);
	N.add_element(4);

	N.show_start_end();
	N.show_end_start();

	system("pause");
	return 0;
}

