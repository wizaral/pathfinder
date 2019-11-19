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
		cout << endl << "������ ����." << endl;
		return;			//����� �� �������
	}
	
	system("cls");
	cout << "\t\t |" << endl << "\t\t V" << endl;
	for(int i = size - 1; i >= 0; i--)	//������� �������� � �������� ������� (��� ����)
		cout << "\t\t " << array[i] << endl;
}

void infStack::print_push()
{
	if(!size)
	{
		cout << endl << "������ ����." << endl;
		return;			//����� �� �������
	}
	
	for(int k = 10; k >= 0; k--)
	{
		system("cls");
		cout << "\t\t |" << endl << "\t\t V" << endl << "\t\t ";
		for(int j = k; j > 0; j--)
			cout << " ";
			
		cout << array[size - 1] << endl;
		
		for(int i = size - 2; i >= 0; i--)	//������� �������� � �������� ������� (��� ����)
			cout << "\t\t " << array[i] << endl;
		
		Sleep(100);
	}
}

void infStack::print_pop()
{
	if(!size)
	{
		cout << endl << "������ ����." << endl;
		return;			//����� �� �������
	}
	
	for(int k = 0; k <= 10; k++)
	{
		system("cls");
		cout << "\t\t |" << endl << "\t\t V" << endl << "\t\t ";
		for(int j = k; j > 0; j--)
			cout << " ";
			
		cout << array[size - 1] << endl;
		
		for(int i = size - 2; i >= 0; i--)	//������� �������� � �������� ������� (��� ����)
			cout << "\t\t " << array[i] << endl;
		
		Sleep(100);
	}
}

void infStack::push()
{
	if(size == capacity)	//���� ���������� ��������� ���������� � ���������� �������� ������������ ������
	{
		int tmp_capacity = capacity * 1.5;	//����������� ������ � ������� ����
		
		char *tmp = new char[tmp_capacity];	//�������� ������ �������� �������
		if(!tmp)							//���� �� ��������
            throw out_of_range("���������� �������� ������.");
        
        for(int i = 0; i < capacity; i++)	//�������� �������� �� ������� �������, �������� �������
        	tmp[i] = array[i];
        
        delete []array;						//������� ������ ������
		array = tmp;
		capacity = tmp_capacity;			//������������ ����������
	}
	
	cout << endl << "������� �������: ";
	array[size] = getChar();
	size++;
}

void infStack::pop()
{
	if(!size)								//���� ���� ���� (size == 0)
	{
		cout << endl << "!������ ����" << endl << endl;
		return;
	}
	
	size--;
	
	if((double)capacity / (double)size > 3 && capacity > 30)	//������������ ������, �������� �
	{
		int tmp_capacity = capacity / 3 + 1;	//��������� ���������� ���������
		char *tmp = new char[tmp_capacity];		//�������� ������� ���������� ������
		if(!tmp)								//���� ������ ��� ���������
            throw out_of_range("���������� �������� ������.");
        
        for(int i = 0; i < tmp_capacity; i++)	//�������� ��������
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
		cout << endl << "������ ����!" << endl << endl;
		return;
	}
	
	cout << "������� �������: " << array[size-1] << endl;
}

//=========================================================================

int getInt()
{
	while(true)		//������ ����
	{
		char *line = new char[20];	//�������� ������ ��� ������ �� 19 ��������
		
		int d;
		char c;
		
		if(line)	//���� �� �������� ������
		{
			fflush(stdin);				//������ ����� �����, ����� �� ��������� �����
			fgets(line, 20, stdin);		//����������� ����� � ����������
			fflush(stdin);				//����� ������
			
			if(sscanf(line, "%i %c", &d, &c) == 1)	//���� ���� ������� ������ ���� ������������� �����
			{
				delete []line;		//������� ������
				return d;		//��������� ������ �������, ��������� ���������� ��������
			}
			
			delete []line;
		}
		
		cout << "���������: ";
	}
}

char getChar()
{
	while(true)		//������ ����
	{
		char *line = new char[20];	//�������� ������ ��� ������ �� 19 ��������
		
		char c1, c2;
		
		if(line)	//���� �� �������� ������
		{
			fflush(stdin);				//������ ����� �����, ����� �� ��������� �����
			fgets(line, 20, stdin);		//����������� ����� � ����������
			fflush(stdin);				//����� ������
			
			if(sscanf(line, "%c %c", &c1, &c2) == 1)	//���� ���� ������� ������ ���� ������������� �����
			{
				delete []line;		//������� ������
				return c1;		//��������� ������ �������, ��������� ���������� ��������
			}
			
			delete []line;
		}
		
		cout << "���������: ";
	}
}
