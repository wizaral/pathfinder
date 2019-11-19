#include <iostream>
#include <cstdlib>

#include "lib.h"

using namespace std;

//=========================================================================

int infStack::getSize()
{
	return size;
}

void infStack::print()
{
	if(!size)
	{
		cout << endl << "Пустой стек." << endl;
		return;			//выход из функции
	}
	
	system("cls");
	cout << "\t\t |" << endl << "\t\t V" << endl;
	for(int i = size - 1; i >= 0; i--)	//выводит значения в обратном порядке (так надо)
		cout << "\t\t " << array[i] << endl;
}

void infStack::print_push()
{
	if(!size)
	{
		cout << endl << "Пустой стек." << endl;
		return;			//выход из функции
	}
	
	for(int k = 10; k >= 0; k--)
	{
		system("cls");
		cout << "\t\t |" << endl << "\t\t V" << endl << "\t\t ";
		for(int j = k; j > 0; j--)
			cout << " ";
			
		cout << array[size - 1] << endl;
		
		for(int i = size - 2; i >= 0; i--)	//выводит значения в обратном порядке (так надо)
			cout << "\t\t " << array[i] << endl;
		
		Sleep(100);
	}
}

void infStack::print_pop()
{
	if(!size)
	{
		cout << endl << "Пустой стек." << endl;
		return;			//выход из функции
	}
	
	for(int k = 0; k <= 10; k++)
	{
		system("cls");
		cout << "\t\t |" << endl << "\t\t V" << endl << "\t\t ";
		for(int j = k; j > 0; j--)
			cout << " ";
			
		cout << array[size - 1] << endl;
		
		for(int i = size - 2; i >= 0; i--)	//выводит значения в обратном порядке (так надо)
			cout << "\t\t " << array[i] << endl;
		
		Sleep(100);
	}
}

void infStack::push()
{
	if(size == capacity)	//если количество элементов сравнялось с предельным размером перевыделяет память
	{
		int tmp_capacity = capacity * 1.5;	//увеличивает размер в полтора раза
		
		char *tmp = new char[tmp_capacity];	//выделяет память большего размера
		if(!tmp)							//если не выделило
            throw out_of_range("Невозможно выделить память.");
        
        for(int i = 0; i < capacity; i++)	//копирует значения из старого массива, меньшего размера
        	tmp[i] = array[i];
        
        delete []array;						//удаляет старый массив
		array = tmp;
		capacity = tmp_capacity;			//корректирует переменные
	}
	
	cout << endl << "Введите элемент: ";
	array[size] = getChar();
	size++;
}

void infStack::pop()
{
	if(!size)								//если стек пуст (size == 0)
	{
		cout << endl << "!Пустой стек" << endl << endl;
		return;
	}
	
	size--;
	
	if((double)capacity / (double)size > 3 && capacity > 30)	//перевыделяет память, уменьшая её
	{
		int tmp_capacity = capacity / 3 + 1;	//уменьшает количество элементов
		char *tmp = new char[tmp_capacity];		//выделяет меньшее количество памяти
		if(!tmp)								//если ошибка при выделении
            throw out_of_range("Невозможно выделить память.");
        
        for(int i = 0; i < tmp_capacity; i++)	//копирует элементы
        	tmp[i] = array[i];
        
        delete []array;
		array = tmp;
		capacity = tmp_capacity;
	}
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
	while(true)		//вечный цикл
	{
		char *line = new char[20];	//выделяем память для строки на 19 символов
		
		int d;
		char c;
		
		if(line)	//если не возникло ошибок
		{
			fflush(stdin);				//чистим поток ввода, чтобы не захватить мусор
			fgets(line, 20, stdin);		//запрашиваем число с клавиатуры
			fflush(stdin);				//снова чистим
			
			if(sscanf(line, "%i %c", &d, &c) == 1)	//если было введено только одно целочисленное число
			{
				delete []line;		//удаляем строку
				return d;		//завершаем работу функции, возвращая полученное значение
			}
			
			delete []line;
		}
		
		cout << "Повторите: ";
	}
}

char getChar()
{
	while(true)		//вечный цикл
	{
		char *line = new char[20];	//выделяем память для строки на 19 символов
		
		char c1, c2;
		
		if(line)	//если не возникло ошибок
		{
			fflush(stdin);				//чистим поток ввода, чтобы не захватить мусор
			fgets(line, 20, stdin);		//запрашиваем число с клавиатуры
			fflush(stdin);				//снова чистим
			
			if(sscanf(line, "%c %c", &c1, &c2) == 1)	//если было введено только одно целочисленное число
			{
				delete []line;		//удаляем строку
				return c1;		//завершаем работу функции, возвращая полученное значение
			}
			
			delete []line;
		}
		
		cout << "Повторите: ";
	}
}
