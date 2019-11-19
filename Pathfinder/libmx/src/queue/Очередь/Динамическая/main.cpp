#include <cstdlib>
#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	system("chcp 1251 & cls");
	
	int amount;
	Queue *queue = new Queue();
	
	while(true)
	{
		do{
			cout << "”кажите количество элементов дл€ добавлени€ в очередь: ";
			amount = getInt();
		}while(amount < 0);
		
		for(int i = 0; i < amount; i++)
			queue->enQueue();
		queue->print();
		
		if(queue->getSize() > 0)
		{
			do{
				cout << "”кажите количество элементов дл€ удалени€: ";
				amount = getInt();
				
				if(amount > queue->getSize())
					cout << "”казаное количество больше, чем в очереди!" << endl;
			}while(amount < 0 || amount > queue->getSize());
			
			for(int i = 0; i < amount; i++)
				queue->deQueue();
			queue->print();
		}
		else
		{
			cout << "ƒл€ выхода из программы введите 0, или любое другое значение дл€ продолжени€: ";
			amount = getInt();
			if(amount == 0)
				break;
			cout << endl;
		}
	}
	
	delete queue;
	system("pause");
	return 0;
}
