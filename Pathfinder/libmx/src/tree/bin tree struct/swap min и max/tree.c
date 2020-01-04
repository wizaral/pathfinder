#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1 //�������� � ���� ��� "true" �� "1"

Tree *create_tree() {
    Tree *tree = NULL;
    while (!tree)                            //���� �� ��������� ������
        tree = (Tree *)malloc(sizeof(Tree)); //�������� ������

    tree->size = 0; //������ ��������� ������
    tree->root = NULL;
    return tree; //���������� ��������� �� ����
}

void delete_tree(Tree *tree) {
    if (tree) //�������� �� NULL �������� (������ � ���� ����� ���������)
    {
        delete_node(tree->root); //������� �������� ������ ����������
        free(tree);              //������ ����� ������� ���� ������ ������
    }
}

Node *create_node(Node *parent, int item) {
    Node *node = NULL; //�� �� �����. ��� ��� � ���� � �������
    while (!node)
        node = (Node *)malloc(sizeof(Node));

    node->parent = parent; //� ��������� ����
    node->left = node->right = NULL;
    node->item = item;

    if (!parent)                         //���� �� ������� ������ ������ (� ���� ��� ������)
        node->level = 0;                 //�� �� 0 ������
    else                                 //� ���� ���
        node->level = parent->level + 1; //�� �� �� ������� ���� (������), ��� ��� ������

    return node; //������� ��������� ����
}

void delete_node(Node *node) {
    if (node) //���� ���� �� NULL
    {
        delete_node(node->left);  //���������� ������� � ����� �����
        delete_node(node->right); //� ������
        free(node);               //����� ����
    }
}

Node *min_value(Node *node) {
    if (node && node->left)
        while (node->left)     //���� ���� ������� �����
            node = node->left; //������ ����� (����� ������ ������)
    return node;               //������� ��������� �� ����
}

Node *max_value(Node *node) {
    if (node && node->right) //��� ��� �� �� ��������
        while (node->right)
            node = node->right;
    return node;
}

void insert_element(Tree *tree, int item) {
    if (tree) {
        if (!tree->root) //���� � ������ ��� �����, �� ������� ���
        {
            Node *node = NULL; //��� �������
            while (!node)
                node = create_node(tree->root, item); //�� ����� �������� (NULL, �����)

            tree->root = node; //���������� � ������ ������
            tree->size++;      //������ + 1
        } else                 //���� ������ ����
        {
            Node *fast = tree->root; //������ ��� ���������
            Node *low = NULL;        //�������� ������ �� ������

            while (true) //������ ���� (������ ����� ����� ������)
            {
                low = fast; //"���������" ��������� ����� "��������"

                if (item == fast->item) //���� ����� ������� ��� ����, �� �������� �� �����
                    break;
                else if (item < fast->item) //���� ������� ������ ����
                {
                    fast = fast->left; //������� ���� �� ��� �����
                    if (!fast)         //� ������ �� �����, � ���� �� NULL �� ����� ������ � �� ���� ��������� ���� �����
                    {
                        Node *node = NULL; //������� ���� � ����� ������
                        while (!node)
                            node = create_node(low, item);

                        low->left = node; //��������� � ��� ���� ��������� (�� ��� ������), �� ��� ������ ������ "�������"
                        tree->size++;     //�� ���� �������� ���� ����� � ������ � ������ ������
                        break;            //� ����� �� �����
                    }
                } else //���� ������, �� ���������� ������������ ��� �������
                {
                    fast = fast->right;
                    if (!fast) {
                        Node *node = NULL;
                        while (!node)
                            node = create_node(low, item);

                        low->right = node;
                        tree->size++;
                        break;
                    }
                }
            }
        }
    }
}

void delete_element(Tree *tree, Node *node) {
    if (tree && node) {
        if (node->left && node->right) //���� � ��������� ���� ���� ��� �������
        {
            Node *max = max_value(node->left); //������� �������� _����� ��_
            node->item = max->item;            //������ �������� � ��������� ���� �� ���������
            delete_element(tree, max);         //� ������� �� ����, �������� ������� �����
            return;                            //����� �� �������
        } else if (node->parent)               //���� � ��������� ���� ���� ������ (���� �� ������ (��� ������))
        {
            if (node->left) //���� � �� ������ ����� �������
            {
                if (node == node->parent->left)       //���� ��������� ���� � ������ �������� ����� ���������
                    node->parent->left = node->left;  //������ � ������ ��������� ���� ����� �������� ������ ������� ��������� ����
                else                                  //���� �� �����, ������ ������
                    node->parent->right = node->left; //������ � ������ ��������� ���� ������ �������� ������ ������� ��������� ����
            } else if (node->right)                   //���� � ��������� ���� ������ ������ ������� (������ ��������� � ����������� �����)
            {
                if (node == node->parent->right)
                    node->parent->right = node->right;
                else
                    node->parent->left = node->right;
            } else //���� � ���� ��� ���������
            {
                if (node == node->parent->left) //���� ��� ����� � ������
                    node->parent->left = NULL;  //������ � ������ ������ NULL
                else                            //���������:
                    node->parent->right = NULL;
            }
        } else if (tree->root == node) //���� ������� ������, �� � ���� ������ ���� �������, �� ������ ��� � ����� � ����� ���������
        {
            if (node->left) {
                Node *max = max_value(node->left);
                tree->root->item = max->item;
                delete_element(tree, max);
                return;
            } else if (node->right) {
                Node *max = max_value(node->right);
                tree->root->item = max->item;
                delete_element(tree, max);
                return;
            } else
                tree->root = NULL;
        }
        free(node);   //���� � ��� ���������� ���� else if(node->parent), �� ���� ������� ����
        tree->size--; //� ��������� ������
    }
}

Node *search_node(Node *node, int item) //����������� �����
{
    if (node) //���� ���� �� NULL
    {
        if (item < node->item)                    //���� ������� �������� ������ �������� � ����
            return search_node(node->left, item); //������������ ����� ��� ������ �������

        else if (item > node->item)                //� ���� ������
            return search_node(node->right, item); //�� ��� �������

        return node; //���� ���������� if() �� ���� ���������, �� �� ����� ���� �������� � ����� ��� �������
    }
    return NULL; //���� ���� ���, �� �� ����� � ������� NULL
}

void delete_item(Tree *tree) {
    if (tree) {
        int item;
        printf("������� ����� ��� ��������: ");

        scanf("%i", &item);                              //��������� ����� � ����������
        Node *to_delete = search_node(tree->root, item); //������� ���� � ����� ���������

        if (to_delete)                       //���� �����
            delete_element(tree, to_delete); //�������� ��� ���� ��������
    }
}

void print_tree(Tree *tree) {
    if (tree) {
        int print_type;

        do {
            printf("\n������� ��� ������ ������.\n1 - ������.\n2 - ");
            printf("������������.\n3 - ��������.\n�������: ");
            scanf("%i", &print_type);
        } while (print_type < 1 || print_type > 3); //������ ������ �����, ���� �� ����� ������� ����� �� 1 �� 3

        printf("\n���������� ���������: %i\n", tree->size); //�������� ���-�� ��������� � ������

        if (!tree->root)
            printf("�������� �����������.\n");
        else {
            printf("�������� �������:  %i\n", tree->root->item); //� �������� �����
            printf("�������� ������: \n");

            switch (print_type) //� ����������� �� ���� ������ ������
            {
            case 1:
                pre_order(tree->root);
                printf("\n");
                break;
            case 2:
                in_order(tree->root);
                printf("\n");
                break;
            case 3:
                post_order(tree->root);
                printf("\n");
                break;
            default:
                printf("������������ ���.\n");
            }
        }
    }
}

void add_elements(Tree *tree) {
    FILE *file = fopen("data.txt", "r"); //��������� ���� ��� ������

    if (tree && file) //���� ���� ������ � ������� ����
    {
        int tmp;
        while (fscanf(file, "%i", &tmp) != EOF) //��������� �� ����� �����, ���� �� ������ �� �����
            insert_element(tree, tmp);          //��������� �������

        fclose(file); //�� �������� ������� ����
    }
}

void pre_order(Node *node) {
    if (node) {
        //printf("[%i][%i] ", node->item, node->level);
        printf("%i ", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(Node *node) {
    if (node) {
        in_order(node->left);
        //printf("[%i][%i] ", node->item, node->level);
        printf("%i ", node->item);
        in_order(node->right);
    }
}

void post_order(Node *node) {
    if (node) {
        post_order(node->left);
        post_order(node->right);
        //printf("[%i][%i] ", node->item, node->level);
        printf("%i ", node->item);
    }
}

void swap_min_max(Tree *tree) {
    if (tree) {
        Node *min = min_value(tree->root); //������� �������
        Node *max = max_value(tree->root); //��������

        int tmp = min->item;   //���������� �������
        min->item = max->item; //� ������� ����� ��������
        max->item = tmp;       //� �������� ����������� �������
    }
}

void print_min_max(Tree *tree) {
    if (tree) {
        Node *min = min_value(tree->root);
        Node *max = max_value(tree->root);
        printf("�������\n��������: %i\n�������: %i\n", min->item, min->level);
        printf("��������\n��������: %i\n�������: %i\n", max->item, max->level);
    }
}

void add_item(Tree *tree) {
    if (tree) {
        int item;
        printf("������� ����� ��� ����������: "); //������ �������
        scanf("%i", &item);                       //��������� �� �������
        insert_element(tree, item);               //��������� � ������
    }
}

void search_item(Tree *tree) {
    if (tree) {
        int item;
        printf("������� ����� ��� ������: ");
        scanf("%i", &item);

        if (search_node(tree->root, item)) //���� �����
            printf("�������!\n");
        else //�����
            printf("�� ��������\n");
    }
}
