#include <iostream>
#include <stdexcept>

#include "lib.h"

//=========================================================================

int infStack::getSize()
{
	return size;
}

void infStack::print()
{
	if(!size)
	{
		cout << endl << "!Пустой стек!" << endl << endl;
		return;
	}
	
	cout << endl;
	for(int i = size - 1; i >= 0; i--)
	{
		cout << array[i];
		if(i)
			cout << ", ";
	}
	cout << endl << endl;
}

void infStack::push()
{
	if(size == capacity)
	{
		int tmp_capacity = capacity * 1.5;
		cout << "resize " << capacity << " " << tmp_capacity << endl;
		
		int *tmp = new int[tmp_capacity];
		if(!tmp)
            throw out_of_range("Невозможно выделить память.");
        
        for(int i = 0; i < capacity; i++)
        	tmp[i] = array[i];
        
        delete []array;
		array = tmp;
		capacity = tmp_capacity;
	}
	
	cout << "Введите элемент: ";
	array[size] = getInt();
	size++;
	
	cout << "Размер стека: " << capacity << "  Количество элементов: " << size << endl;
}

void infStack::pop()
{
	if(!size)
	{
		cout << endl << "!Пустой стек" << endl << endl;
		return;
	}
	
	size--;
	cout << "Удалён элемент: " << array[size] << endl;
	
	if((double)capacity / (double)size > 3 && capacity > 30)
	{
		int tmp_capacity = capacity / 3 + 1;
		cout << "resize " << capacity << " " << tmp_capacity << endl;
		int *tmp = new int[tmp_capacity];
		if(!tmp)
            throw out_of_range("Невозможно выделить память.");
        
        for(int i = 0; i < tmp_capacity; i++)
        	tmp[i] = array[i];
        
        delete array;
		array = tmp;
		capacity = tmp_capacity;
	}
	
	cout << "Размер стека: " << capacity << "  Количество элементов: " << size << endl;
}

void infStack::peek()
{
	if(!size)
	{
		cout << endl << "Пустой стек!" << endl << endl;
		return;
	}
	
	cout << "Крайний элемент: " << array[size-1] << endl;
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
