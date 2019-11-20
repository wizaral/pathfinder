#include <cstdlib>
#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");
	
	int sz;
	do{
		cout << "¬ведите размер стека: ";
		sz = getInt();
	}while(sz <= 1);
	
	fixedStack *stack = new fixedStack(sz);
	
	for(int i = 0; i < sz; i++)
		stack->push();
	
	stack->print();
	
	for(int i = 0; i < sz; i++)
		stack->pop();
	
	delete stack;
	system("pause");
	return 0;
}
