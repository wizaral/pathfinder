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
	fixedStackReserv *reserv = new fixedStackReserv(sz);
	
	for(int i = 0; i < sz; i++)
	{
		stack->push(reserv);
		stack->getMin(reserv);
	}
	
	stack->print();
	
	for(int i = 0; i < sz; i++)
	{
		stack->pop(reserv);
		stack->getMin(reserv);
	}
	
	delete stack;
	delete reserv;
	system("pause");
	return 0;
}
