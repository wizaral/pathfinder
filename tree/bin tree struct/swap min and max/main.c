#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251 & cls"); //������� ����
    char choice;

    Tree *tree = create_tree(); //������� ������
    add_elements(tree);         //��������� ����������

    if (tree->root) //���� ������� ���������
        printf("������ ������� ������� �� �����.\n");

    do {
        printf("\n������� ����� ��������.\n1 - ������ ������.\n");
        printf("2 - ���������� ��������.\n3 - �������� ��������.\n");
        printf("4 - ����� ��������.\n5 - ������ min � max.\n");
        printf("6 - �������� ������.\n7 - ����� �� ���������.\n�������: ");

        fflush(stdin);        //�������� ����� ����� �������
        scanf("%c", &choice); //��������� ����� � ������

        switch (choice) //� ����������� �� ������ ����������� ������ ����
        {
        case '1':
            print_tree(tree); //��������
            break;            //����� ����� � ������ �����, � �� ����� ��������� ��������� �����
        case '2':
            add_item(tree); //���������
            break;
        case '3':
            delete_item(tree); //�������
            break;
        case '4':
            search_item(tree); //����
            break;
        case '5':
            printf("\n����� �������:\n");
            print_min_max(tree); //�������� min max
            swap_min_max(tree);  //������ �������

            printf("\n����� ������:\n");
            print_min_max(tree);
            break;
        case '6':
            delete_tree(tree); //������� �� ������
            printf("������ ������� �������.\n\n");
            break;
        default: //���� ������ ��� ���-�� �� ��
            printf("������������ ����.\n");
        }
    } while (choice != '6');

    system("pause");
    return 0;
}
