#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "lib.h"

//=========================================================================

int Queue::getSize()
{
	return size;
}

void Queue::print()
{
	if(size)
	{
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
				cout << array[i] << ", ";
			
			for(int i = 0; i <= pointer2; i++)
			{
				cout << array[i];
				if(i != pointer2)
					cout << ", ";
			}
		}
	}
	else
		cout << "!Пустая очередь!";
	cout << endl << endl;
}

void Queue::enQueue()
{
	cout << "Введите элемент: ";
	int anElement = getInt();
	
	if(size)
	{
		if(size < capacity)	//Если хватает размера
		{
			if(pointer2 + 1 == capacity)	//Переход в начало
			{
				pointer2 = 0;
				array[pointer2] = anElement;
				size++;
			}
			else
			{
				pointer2++;
				array[pointer2] = anElement;
				size++;
			}
		}
		else if(size == capacity)	//Если не хватает места
		{
			int tmp_capacity = 1.5 * capacity;
			int *tmp = new int[tmp_capacity];
			if(!tmp)
	            throw out_of_range("Невозможно выделить память.");
	        
			if(pointer2 < pointer1)	//Если очередь завернута в начало
			{
				for(int i = 0; i < capacity - pointer1; i++)
					tmp[i] = array[pointer1 + i];
				for(int i = 0; i <= pointer2; i++)
					tmp[i + capacity - pointer1] = array[i];
			}
			else
			{
				for(int i = 0; i < capacity; i++)
					tmp[i] = array[i];
			}
			delete []array;
			array = tmp;
			capacity = tmp_capacity;
			
			pointer2++;
			array[pointer2] = anElement;
			size++;
		}
	}
	else	//Если пустая очередь
	{
		array[pointer2] = anElement;
		size++;
	}
}

void Queue::deQueue()
{
	if(size)
	{
		if(pointer1 + 1 == capacity)
		{
			pointer1 = 0;
			size--;
		}
		else
		{
			pointer1++;
			size--;
		}
		
		if((double)capacity / (double)size > 3 && capacity > 30)
		{
			int tmp_capacity = capacity / 3 + 1;
			int *tmp = new int[tmp_capacity];
			if(!tmp)
	            throw out_of_range("Невозможно выделить память.");
			
			if(pointer2 < pointer1)
			{
				for(int i = pointer1; i < capacity; i++)
					tmp[i - pointer1] = array[i];
				for(int i = 0; i <= pointer2; i++)
					tmp[i + capacity - pointer1] = array[i];
				pointer1 = 0;
				pointer2 = size - 1;
			}
			else
			{
				for(int i = pointer1; i <= pointer2; i++)
					tmp[i - pointer1] = array[i];
				pointer1 = 0;
				pointer2 = size - 1;
			}
			
			delete []array;
			array = tmp;
			capacity = tmp_capacity;
		}
	}
	else
		cout << "Пустая очередь!" << endl << endl;
}

int getInt()
{
	while(true)
	{
		char *line = new char[20];
		fflush(stdin);
		fgets(line, 20, stdin);
		
		if(line)
		{
			int d;
			char c;
			
			if((sscanf(line, "%i %c", &d, &c) == 1) && d < INT_MAX)
			{
				delete []line;
				return d;
			}
			delete []line;
		}
		cout << "Повторите: ";
	}
}
