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
	
	Queue *queue = new Queue(size);
	
	for(int i = 0; i < size; i++)
		queue->enQueue();
	queue->print();
	
	for(int i = 0; i < 10; i++)
	{
		queue->deQueue();
		queue->deQueue();
		queue->print();
		
		queue->enQueue();
		queue->enQueue();
		queue->print();
	}
	
	delete queue;
	system("pause");
	return 0;
}
