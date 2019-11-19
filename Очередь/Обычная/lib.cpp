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
	if(pointer1 <= pointer2)
	{
		for(int i = pointer1; i <= pointer2; i++)
		{
			cout << array[i];
			if(i != pointer2)
				cout << ", ";
		}
	}
	else if(pointer2 < pointer1)
	{
		for(int i = pointer1; i < capacity; i++)
		{
			cout << array[i] << ", ";
		}
		
		for(int i = 0; i <= pointer2; i++)
		{
			cout << array[i];
			if(i != pointer2)
				cout << ", ";
		}
	}
	else
		cout << "WTF!!! How did u do this, maaan!";
	
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
	
	if(!size)
	{
		array[pointer2] = anElement;
		size++;
	}
	else if(pointer1 <= pointer2)
	{
		if(pointer2+1 == capacity)
		{
			pointer2 = 0;
			array[pointer2] = anElement;
			size++;
			cout << "В начало!" << endl;
		}
		else
		{
			pointer2++;
			array[pointer2] = anElement;
			size++;
		}
	}
	else if(pointer2 < pointer1)
	{
		pointer2++;
		array[pointer2] = anElement;
		size++;
	}
	else
		cout << "WTF!!! How did u do this, maaan!" << endl;
}

void Queue::deQueue()
{
	if(!size)
	{
		cout << "Пустая очередь!" << endl;
		return;
	}
	
	if(pointer1+1 == capacity)
	{
		cout << "Удалён элемент: " << array[pointer1] << endl;
		pointer1 = 0;
		size--;
		cout << "!В начало" << endl;
	}
	else
	{
		cout << "Удалён элемент: " << array[pointer1] << endl;
		pointer1++;
		size--;
	}
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
