#include <cstdlib>
#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");
	
	int size;
	do{
		cout << "¬ведите размер очереди: ";
		size = getInt();
	}while(size <= 1);
	
	Queue *stack = new Queue(size);
	
	for(int i = 0; i < size; i++)
		stack->enQueue();
	
	stack->print();
	
	for(int i = 0; i < stack->getSize() / 2; i++)
		stack->deQueue();
	
	stack->print();
	
	for(int i = 0; i < stack->getSize() / 2; i++)
		stack->deQueue();
	
	stack->print();
	
	for(int i = 0; i < stack->getSize() / 2; i++)
		stack->enQueue();
	
	stack->print();
	
	for(int i = 0; i < size; i++)
		stack->deQueue();
	
	stack->print();
	
	delete stack;
	system("pause");
	return 0;
}
