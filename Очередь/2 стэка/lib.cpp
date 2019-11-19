#include <iostream>
#include <cstdlib>
#include "lib.h"

//=========================================================================

int Queue::getSize()
{
	return size;
}

void Queue::print()
{
	if(!size)
	{
		cout << "!Пустая очередь!" << endl;
		return;
	}
	
	cout << endl << "Очередь: ";
	for(int i = 0; i < size; i++)
	{
		cout << array1[i];
		if(i != size-1)
			cout << ", ";
	}
	cout << endl << endl;
}

void Queue::enQueue()
{
	if(size == capacity)
	{
		cout << "Полная очередь!" << endl;
		return;
	}
	
	cout << "Введите элемент: ";
	int anElement = getInt();
	array1[size] = anElement;
	size++;
	flag = 0;
}

void Queue::deQueue()
{
	if(!size)
	{
		cout << "Пустая очередь!" << endl;
		return;
	}
	if(!flag)
	{
		for(int i = 0; i < size; i++)
		{
			array2[i] = array1[size-1-i];
		}                                 
	}
	
	cout << "Удалён элемент: " << array1[0] << endl;
	
	for(int i = 0; i < size - 1; i++)
		array1[i] = array2[size-2-i];
	
	size--;
	flag = 1;
}

//=========================================================================

int getInt()
{
	while(true)
	{
		char *line = new char[20];
		fflush(stdin);
		fgets(line, 20, stdin);
		fflush(stdin);
		
		if(!line)
			goto pointer;
		
		int d;
		char c;
		
		if((sscanf(line, "%i %c", &d, &c) == 1) && d < INT_MAX)
		{
			delete []line;
			return d;
		}
		
    	pointer:
		delete []line;
		cout << "Повторите: ";
	}
}
