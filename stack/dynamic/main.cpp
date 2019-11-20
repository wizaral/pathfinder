#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251 & cls");
	
	int amount1, amount2;
	infStack *stack = new infStack();
	
	while(true)
	{
		do{
			cout << "������� ���������� ��������� ��� ���������� � ����: ";
			amount1 = getInt();
		}while(amount1 < 0);
		
		for(int i = 0; i < amount1; i++)
			stack->push();
		
		stack->print();
		
		do{
			cout << "������� ���������� ��������� ��� ��������: ";
			amount2 = getInt();
			
			if(amount2 > stack->getSize())
				cout << "�������� ���������� ������, ��� � �����!" << endl;
		}while(amount2 < 0 || amount2 > stack->getSize());
		
		for(int i = 0; i < amount2; i++)
			stack->pop();
		
		stack->print();
		
		cout << "��� ������ �� ��������� ������� 0, ��� ����� ������ �������� ��� �����������: ";
		amount1 = getInt();
		if(amount1 == 0)
			break;
		cout << endl;
	}
	
	delete stack;
	system("pause");
	return 0;
}
