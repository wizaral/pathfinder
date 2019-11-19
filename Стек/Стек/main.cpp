#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <windows.h>

//using namespace std;

class infStack			// класс динамический (бесконечный) стек
{
    public:
    	infStack()		//конструктор: тут задаются начальные параметры на старте работы
		{
			size = 0;	//размер в данный момент
			capacity = 10;		//предел размера после которого будет перевыделена память
			array = new char[capacity];	//выделение памяти на старте работы
		}
		
		~infStack()		//деструктор: вызывается при завершении работы программы
		{
			delete []array;		//удаляет массив в котором хранился стек
			std::cout << std::endl << "Стек полностью удален." << std::endl << std::endl;
		}
		
		int getSize();			//функция возвращает количетсво элементов в данный момент
		void push();			//добавляет элемент в начало стека
		void pop();				//удаляет элемент в начале стека
		void peek();			//показывает первый элемент
		
		void print();			//печатает в консоли стек
		void print_push();
		void print_pop();
		
    private:
        int capacity;			//предел размера после которого будет перевыделена память
        int size;				//размер в данный момент
        char *array;				//указатель на массив, в котором будет храниться стек
};

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
		
		std::cout << "Повторите: ";
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
		
		std::cout << "Повторите: ";
	}
}

int infStack::getSize()
{
	return size;
}

void infStack::print()
{
	if(!size)
	{
		std::cout << std::endl << "Пустой стек." << std::endl;
		return;			//выход из функции
	}
	
	system("cls");
	std::cout << "\t\t |" << std::endl << "\t\t V" << std::endl;
	for(int i = size - 1; i >= 0; i--)	//выводит значения в обратном порядке (так надо)
		std::cout << "\t\t " << array[i] << std::endl;
}

void infStack::print_push()
{
	if(!size)
	{
		std::cout << std::endl << "Пустой стек." << std::endl;
		return;			//выход из функции
	}
	
	for(int k = 10; k >= 0; k--)
	{
		system("cls");
		std::cout << "\t\t |" << std::endl << "\t\t V" << std::endl << "\t\t ";
		for(int j = k; j > 0; j--)
			std::cout << " ";
			
		std::cout << array[size - 1] << std::endl;
		
		for(int i = size - 2; i >= 0; i--)	//выводит значения в обратном порядке (так надо)
			std::cout << "\t\t " << array[i] << std::endl;
		
		Sleep(10*k);
	}
}

void infStack::print_pop()
{
	if(!size)
	{
		std::cout << std::endl << "Пустой стек." << std::endl;
		return;			//выход из функции
	}
	
	for(int k = 0; k <= 10; k++)
	{
		system("cls");
		std::cout << "\t\t |" << std::endl << "\t\t V" << std::endl << "\t\t ";
		for(int j = k; j > 0; j--)
			std::cout << " ";
			
		std::cout << array[size - 1] << std::endl;
		
		for(int i = size - 2; i >= 0; i--)	//выводит значения в обратном порядке (так надо)
			std::cout << "\t\t " << array[i] << std::endl;
		
		Sleep(10*k);
	}
}

void infStack::push()
{
	if(size == capacity)	//если количество элементов сравнялось с предельным размером перевыделяет память
	{
		int tmp_capacity = capacity * 1.5;	//увеличивает размер в полтора раза
		
		char *tmp = new char[tmp_capacity];	//выделяет память большего размера
		if(tmp)							//если не выделило
            throw std::out_of_range("Невозможно выделить память.");
        
        for(int i = 0; i < capacity; i++)	//копирует значения из старого массива, меньшего размера
        	tmp[i] = array[i];
        
        delete []array;						//удаляет старый массив
		array = tmp;
		capacity = tmp_capacity;			//корректирует переменные
	}
	
	std::cout << std::endl << "Введите элемент: ";
	array[size] = getChar();
	size++;
}

void infStack::pop()
{
	if(!size)								//если стек пуст (size == 0)
	{
		std::cout << std::endl << "!Пустой стек" << std::endl << std::endl;
		return;
	}
	
	size--;
	
	if((double)capacity / (double)size > 3 && capacity > 30)	//перевыделяет память, уменьшая её
	{
		int tmp_capacity = capacity / 3 + 1;	//уменьшает количество элементов
		char *tmp = new char[tmp_capacity];		//выделяет меньшее количество памяти
		if(!tmp)								//если ошибка при выделении
            throw std::out_of_range("Невозможно выделить память.");
        
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
		std::cout << std::endl << "Пустой стек!" << std::endl << std::endl;
		return;
	}
	
	std::cout << "Крайний элемент: " << array[size-1] << std::endl;
}

//=========================================================================

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251 & cls");
	
	char end;
	int amount1, amount2;
	infStack *stack = new infStack();
	
	while(true)
	{
		do{
			std::cout << "Укажите количество элементов для добавления в стек: ";
			amount1 = getInt();
		}while(amount1 < 0);
		
		for(int i = 0; i < amount1; i++)
		{
			stack->push();
			stack->print_push();
		}
		
		do{
			std::cout << std::endl << "Укажите количество элементов для удаления: ";
			amount2 = getInt();
			
			if(amount2 > stack->getSize())
				std::cout << "Указаное количество больше, чем в стеке!" << std::endl;
		}while(amount2 < 0 || amount2 > stack->getSize());
		
		for(int i = 0; i < amount2; i++)
		{
			stack->print_pop();
			stack->pop();
		}
		system("cls");
		stack->print();
		
		std::cout << std::endl << std::endl << "Для выхода из программы введите 0, или другой символ для продолжения: ";
		end = getChar();
		if(end == '0')
			break;
		std::cout << std::endl;
	}
	
	delete stack;
	system("pause");
	return 0;
}
