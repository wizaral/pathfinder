#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

//using namespace std;

class infStack  // ����� ������������ (�����������) ����
{
public:
    infStack()  //�����������: ��� �������� ��������� ��������� �� ������ ������
    {
        size = 0;                    //������ � ������ ������
        capacity = 10;               //������ ������� ����� �������� ����� ������������ ������
        array = new char[capacity];  //��������� ������ �� ������ ������
    }

    ~infStack()  //����������: ���������� ��� ���������� ������ ���������
    {
        delete[] array;  //������� ������ � ������� �������� ����
        std::cout << std::endl
                  << "���� ��������� ������." << std::endl
                  << std::endl;
    }

    int getSize();  //������� ���������� ���������� ��������� � ������ ������
    void push();    //��������� ������� � ������ �����
    void pop();     //������� ������� � ������ �����
    void peek();    //���������� ������ �������

    void print();  //�������� � ������� ����
    void print_push();
    void print_pop();

private:
    int capacity;  //������ ������� ����� �������� ����� ������������ ������
    int size;      //������ � ������ ������
    char* array;   //��������� �� ������, � ������� ����� ��������� ����
};

int getInt() {
    while (true)  //������ ����
    {
        char* line = new char[20];  //�������� ������ ��� ������ �� 19 ��������

        int d;
        char c;

        if (line)  //���� �� �������� ������
        {
            fflush(stdin);           //������ ����� �����, ����� �� ��������� �����
            fgets(line, 20, stdin);  //����������� ����� � ����������
            fflush(stdin);           //����� ������

            if (sscanf(line, "%i %c", &d, &c) == 1)  //���� ���� ������� ������ ���� ������������� �����
            {
                delete[] line;  //������� ������
                return d;       //��������� ������ �������, ��������� ���������� ��������
            }

            delete[] line;
        }

        std::cout << "���������: ";
    }
}

char getChar() {
    while (true)  //������ ����
    {
        char* line = new char[20];  //�������� ������ ��� ������ �� 19 ��������

        char c1, c2;

        if (line)  //���� �� �������� ������
        {
            fflush(stdin);           //������ ����� �����, ����� �� ��������� �����
            fgets(line, 20, stdin);  //����������� ����� � ����������
            fflush(stdin);           //����� ������

            if (sscanf(line, "%c %c", &c1, &c2) == 1)  //���� ���� ������� ������ ���� ������������� �����
            {
                delete[] line;  //������� ������
                return c1;      //��������� ������ �������, ��������� ���������� ��������
            }

            delete[] line;
        }

        std::cout << "���������: ";
    }
}

int infStack::getSize() {
    return size;
}

void infStack::print() {
    if (!size) {
        std::cout << std::endl
                  << "������ ����." << std::endl;
        return;  //����� �� �������
    }

    system("cls");
    std::cout << "\t\t |" << std::endl
              << "\t\t V" << std::endl;
    for (int i = size - 1; i >= 0; i--)  //������� �������� � �������� ������� (��� ����)
        std::cout << "\t\t " << array[i] << std::endl;
}

void infStack::print_push() {
    if (!size) {
        std::cout << std::endl
                  << "������ ����." << std::endl;
        return;  //����� �� �������
    }

    for (int k = 10; k >= 0; k--) {
        system("cls");
        std::cout << "\t\t |" << std::endl
                  << "\t\t V" << std::endl
                  << "\t\t ";
        for (int j = k; j > 0; j--)
            std::cout << " ";

        std::cout << array[size - 1] << std::endl;

        for (int i = size - 2; i >= 0; i--)  //������� �������� � �������� ������� (��� ����)
            std::cout << "\t\t " << array[i] << std::endl;

        Sleep(10 * k);
    }
}

void infStack::print_pop() {
    if (!size) {
        std::cout << std::endl
                  << "������ ����." << std::endl;
        return;  //����� �� �������
    }

    for (int k = 0; k <= 10; k++) {
        system("cls");
        std::cout << "\t\t |" << std::endl
                  << "\t\t V" << std::endl
                  << "\t\t ";
        for (int j = k; j > 0; j--)
            std::cout << " ";

        std::cout << array[size - 1] << std::endl;

        for (int i = size - 2; i >= 0; i--)  //������� �������� � �������� ������� (��� ����)
            std::cout << "\t\t " << array[i] << std::endl;

        Sleep(10 * k);
    }
}

void infStack::push() {
    if (size == capacity)  //���� ���������� ��������� ���������� � ���������� �������� ������������ ������
    {
        int tmp_capacity = capacity * 1.5;  //����������� ������ � ������� ����

        char* tmp = new char[tmp_capacity];  //�������� ������ �������� �������
        if (tmp)                             //���� �� ��������
            throw std::out_of_range("���������� �������� ������.");

        for (int i = 0; i < capacity; i++)  //�������� �������� �� ������� �������, �������� �������
            tmp[i] = array[i];

        delete[] array;  //������� ������ ������
        array = tmp;
        capacity = tmp_capacity;  //������������ ����������
    }

    std::cout << std::endl
              << "������� �������: ";
    array[size] = getChar();
    size++;
}

void infStack::pop() {
    if (!size)  //���� ���� ���� (size == 0)
    {
        std::cout << std::endl
                  << "!������ ����" << std::endl
                  << std::endl;
        return;
    }

    size--;

    if ((double)capacity / (double)size > 3 && capacity > 30)  //������������ ������, �������� �
    {
        int tmp_capacity = capacity / 3 + 1;  //��������� ���������� ���������
        char* tmp = new char[tmp_capacity];   //�������� ������� ���������� ������
        if (!tmp)                             //���� ������ ��� ���������
            throw std::out_of_range("���������� �������� ������.");

        for (int i = 0; i < tmp_capacity; i++)  //�������� ��������
            tmp[i] = array[i];

        delete[] array;
        array = tmp;
        capacity = tmp_capacity;
    }
}

void infStack::peek() {
    if (!size) {
        std::cout << std::endl
                  << "������ ����!" << std::endl
                  << std::endl;
        return;
    }

    std::cout << "������� �������: " << array[size - 1] << std::endl;
}

//=========================================================================

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251 & cls");

    char end;
    int amount1, amount2;
    infStack* stack = new infStack();

    while (true) {
        do {
            std::cout << "������� ���������� ��������� ��� ���������� � ����: ";
            amount1 = getInt();
        } while (amount1 < 0);

        for (int i = 0; i < amount1; i++) {
            stack->push();
            stack->print_push();
        }

        do {
            std::cout << std::endl
                      << "������� ���������� ��������� ��� ��������: ";
            amount2 = getInt();

            if (amount2 > stack->getSize())
                std::cout << "�������� ���������� ������, ��� � �����!" << std::endl;
        } while (amount2 < 0 || amount2 > stack->getSize());

        for (int i = 0; i < amount2; i++) {
            stack->print_pop();
            stack->pop();
        }
        system("cls");
        stack->print();

        std::cout << std::endl
                  << std::endl
                  << "��� ������ �� ��������� ������� 0, ��� ������ ������ ��� �����������: ";
        end = getChar();
        if (end == '0')
            break;
        std::cout << std::endl;
    }

    delete stack;
    system("pause");
    return 0;
}
