#include <iostream>
#include <cstdlib>

#include "lib.h"

//=========================================================================

void fixedStack::print()
{
	if(!size)
	{
		cout << "!������ ����!" << endl;
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

void fixedStack::push()
{
	if(size == capacity)
	{
		cout << "������ ����" << endl;
		return;
	}
	
	cout << "������� �������: ";
	int anElement = getInt();
	array[size] = anElement;
	size++;
	
}

void fixedStack::pop()
{
	if(!size)
	{
		cout << "!������ ����" << endl;
		return;
	}
	size--;
	cout << "����� �������: " << array[size] << endl;
}

void fixedStack::peek()
{
	if(!size)
	{
		cout << "������ ����!" << endl;
		return;
	}
	
	cout << "������� �������: " << array[size-1] << endl;
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
		cout << "���������: ";
	}
}
