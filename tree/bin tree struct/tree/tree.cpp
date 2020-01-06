#include "tree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Node *create_node(Node *parent, int value) {
    Node *node = new Node; //�������� ������
    if (node)              //���� ������ ����������, �� ��������� != NULL
    {
        node->parent = parent; //��������� ��������
        node->left = nullptr;  //������ ���
        node->right = nullptr; //������� ����
        node->value = value;   //�������� ���������
        return node;           //� ������� ��������� �� ������� ����
    } else                     //� ���� �� ��������, �� ������ ����
    {
        cout << "������ ��� �������� ��������!" << endl;
        return nullptr; //nullptr ���� �����, ��� � NULL
    }
}

void delete_node(Node *node) {
    if (node) //���� ���� ����������
    {
        delete_node(node->left);  //���������� �������� ����� �����
        delete_node(node->right); //����� � ������ �� �����
        delete node;              //� ������ ����� ������� ����
    }
}

//===============================================================

Tree *create_tree() {
    Tree *tree = new Tree; //�� �� �����
    if (tree) {
        tree->count = 0;      //���� ��� ������
        tree->root = nullptr; //� ����� ���
        return tree;          //�������
    }
    cout << "������ �������� �����!" << endl;
    exit(12345); //��� ��������� ������ � ������ 12345
                 //����� ����� �����, ��� �� ���
                 //� main() � �� ������ ������� return 12345;
                 //�� � ��������� ������� ��� �������� ���
}

void delete_tree(Tree *tree) {
    if (tree) //��������� ���������
    {
        delete_node(tree->root); //�������� ����������� �������� ������
        delete tree;             //� ������ ����� ��� ������ ������� ������
    }
}

void insert_item(Tree *tree, int value) {
    if (tree) {
        //���� � ��� tree->root == NULL �� ������ ������
        //� ����� ������� �������� �������
        if (!tree->root) {
            //��� ����� � ���, ��� � ��� tree->root == NULL
            //� ���� ���������� ��� ��� �������� ��� crt_nd()
            //��� ���������� ��������, �� ���������� ������ �������� �����
            //��� � ����� ��� ������

            Node *node = create_node(tree->root, value);
            if (node) {
                tree->root = node; //������ ������� ������ �����
                tree->count++;     //� ����������� ������
            } else {
                cout << "������ ��� ���������� ��������!" << endl;
                return; //�����
            }
        }

        //� ������, ���� � ��� ��� ���� ������
        //���������� ����� ������� ���������
        else {
            Node *fast = tree->root; //���������, ������� "�� ��� �������"
            Node *slow = nullptr;    //��� ��� ��� ��������� ������

            while (true) //������ ����, � �������� ������ ���� �����
            {
                slow = fast; //������������ ���������� ��������

                if (value == fast->value) //� ������, ���� ����� ��� ���� � ������, �� ������� ���� �� �����
                {
                    cout << "����� ������� ��� ��� ��������." << endl;
                    break;
                } else if (value < fast->value) //���� ����� ������
                {
                    fast = fast->left; //������ ��������� fast ��������� � ������ ����� ������ ������ �������

                    //� ���� left �� ���� ������ ��� NULL, �� �� ����� ����� ��� �������
                    if (!fast) {
                        //������� ����, ������� ������� ������ slow
                        Node *node = create_node(slow, value);

                        slow->left = node; //� ������������ ������ ������ �������
                        tree->count++;     //�� �������� ������ ������
                        break;             //� ��� � ����� �� �����
                    }
                } else //���� ������
                {
                    //��� ���� �����, �� ��� �������
                    fast = fast->right;
                    if (!fast) {
                        Node *node = create_node(slow, value);
                        slow->right = node;
                        tree->count++;
                        break;
                    }
                }
            }
        }
    }
}

//===============================================================

void delete_item(Tree *tree, Node *node) //����� ���****�� ������� � ���� ����
{
    //��������� ��������� �� ������ � ���� ��� ��������
    if (tree && node) {
        if (node->left && node->right) //� ������, ���� � ��������� ���� ���� � ����� � ������ �������
        {
            Node *max = get_max(node->left); //������� � ���� � ������ ��� �������� �� ��������� ������
            node->value = max->value;        //��� � ���� ������������ ��� ��� ��������
            delete_item(tree, max);          //������ ��� ��� �������� ����� ������ ��� ����
            //� ���� � ���������� �� ����������
            return; //�� �� �� �������, ��� ��� return ������ ��� � ����� ������� �������� delete node
                    //� �� ��� ������� ����� �������� �������� �������� ���� ����
        }

        //���� ���������� ���������� ��������, ������ � ���� ���� ����� ���� ������
        //�� ������� ��������, ���� �� � �� ������ (����� ������ ���� �������)

        else if (node->parent) {
            if (node->left) //���� ������ ���� � ������ �����
            {
                //��������� ������ � ������� ����� ��������� ���� �� �����, ��
                //������ node->left->parent->left ����� ������ node->left
                //� �� ���� ����� �������� ��������))0)

                //���� ��������������� ��������� ������ ����, �� ����������
                //���� � � ������ ������ �����
                if (node == node->parent->left)
                    //������ � ������ ��������� ���� ����� �������� ������ ������ �������
                    //� ���� ������ � ����� ���� ������� (���� � �����)
                    node->parent->left = node->left;

                //� ���� �� �����, ������ ������
                else
                    node->parent->right = node->left;
            } else if (node->right) //���� ������ ���� � ������ ������
            {
                //��� ����� �� ���, �� "����������" ��� ������ �������

                if (node == node->parent->right)
                    node->parent->right = node->right;
                else
                    node->parent->left = node->right;
            } else //� ���� � ���� ��� �������� (������� ����)
            {
                if (node == node->parent->left)   //� ����������� �� ������ ���������
                    node->parent->left = nullptr; //������ � ������ ��������� NULL
                else
                    node->parent->right = nullptr;
            }
        }

        //���� �� ��� ���� ������� ������, �� �� �������
        //������ �������� ��� �������� ��� � ������ ������
        //� ��� ������� ���� ����, � �������� �������� ��������

        else if (tree->root == node) {
            //�� ������ ������ �� �����, ��� � ���� �������� ���� �������
            //����� �� ��� ������ � ����� ������ if() ���� �������

            if (node->left) {
                Node *tmp = get_max(node->left); //��� �����
                tree->root->value = tmp->value;  //��� "��������������
                delete_item(tree, tmp);          //��� ������ ����
                return;                          //� �����, ������ ��� ������� �������� ����
            } else if (node->right)              //�� �� ���� � �������
            {
                Node *tmp = get_max(node->right);
                tree->root->value = tmp->value;
                delete_item(tree, tmp);
                return;
            } else //� ���� � ��� � ������ ������ ������
            {
                tree->root = nullptr; //������ ������ � ������ ��������� NULL
                                      //� ������� �������� ����
            }
        }
        delete node;   //�������� ����, ���� �� ������������ �������
        tree->count--; //��������� ������
    }
}

void delete_item(Tree *tree, int value) {
    if (tree) //������� ������ �� ������� ������������� � ����� ����������
    {
        Node *node = search(tree->root, value); //����� ���� � ����� ���������
        if (node)                               //���� ����� � ������ ����
            delete_item(tree, node);            //�� �������� ��������, ������� ����
                                                //� ���� ���, �� � ��� � ���
    }
}

Node *search(Node *node, int value) //����������� �����, ���� ����������
{
    if (!node)          //���� � ������� ����� ������ ���������
        return nullptr; //������� NULL � ������

    //���� �������� ����, � ������� ��������� ������, ���� �����
    else if (value < node->value)
        return search(node->left, value); //���������� ��������� ���� �������

    //�������� ������
    else if (value > node->value)
        return search(node->right, value); //���������� (������ ��������)

    //���� �� ������ �� ������, �� �����
    else
        return node; //� �������
}

//===============================================================

int get_height(Node *node) //���� ����������� ����
{
    if (node) {
        int h1 = get_height(node->left);
        int h2 = get_height(node->right);

        //����� ��������� ��������
        return h1 > h2 ? (h1 + 1) : (h2 + 1);

        //��� ����� �����, �� � ���� �������
        /*if(h1 > h2)
			return h1 + 1;
		else
			return h2 + 1;*/
    }
    return 0; //���� ������ �� NULL ���� ������� 0
}

int leaf_amount(Node *node) //� ���� ��
{
    if (!node) //���� ������ �� NULL ���� - ������� 0
        return 0;
    if (!node->left && !node->right) //���� ������ �� ���� - 1
        return 1;

    //���� ���������� ���������� ������
    //����� �� � ����, ������� �� ����
    //����� �������� ������� �� ������� ������� ����
    return leaf_amount(node->left) + leaf_amount(node->right);
}

bool compare(Node *v1, Node *v2) //� ��� ��� ����� �������� ������� � ���� �������
{
    //� ���, ��� �����
    /*
	if(v1 != NULL && v2 != NULL)
	{
		if(v1->value == v2->value)
		{
			if(compare(v1->left, v2->left) == true)	//���� ���� �������� ���
			{
				if(compare(v1->right, v2->right) == true)	//� ���
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if(v1 != NULL || v2 != NULL)
	{
		//���� ���� �� ��� NULL � ������ ��� - ������ ������
		return false;
	}
	else //v1 == NULL && v2 == NULL
	{
		return true;
	}
	*/
    return v1 && v2 ? v1->value == v2->value && compare(v1->left, v2->left) && compare(v1->right, v2->right) : !v1 && !v2;
}

//===============================================================

Node *get_min(Node *node) {
    while (node->left)
        node = node->left; //����������� �����, ������ ��� ����� ������ ������
    return node;
}

Node *get_max(Node *node) {
    while (node->right)
        node = node->right; //��������, �� �� �����
    return node;
}

//===============================================================

//��� �����, ��� ���� � �����, ����� �� ��������

void preorder_print(Node *node) {
    if (node) {
        cout << node->value << ' ';
        preorder_print(node->left);
        preorder_print(node->right);
    }
}

void inorder_print(Node *node) {
    if (node) {
        inorder_print(node->left);
        cout << node->value << ' ';
        inorder_print(node->right);
    }
}

void postorder_print(Node *node) {
    if (node) {
        postorder_print(node->left);
        postorder_print(node->right);
        cout << node->value << ' ';
    }
}

//������ ��� ���� ������ � ������������, ������ ��� ���� �������
void print(Tree *tree, int type) {
    if (tree && tree->root) {
        switch (type) {
        case 1: {
            preorder_print(tree->root);
            cout << endl;
            break;
        }
        case 2: {
            inorder_print(tree->root);
            cout << endl;
            break;
        }
        case 3: {
            postorder_print(tree->root);
            cout << endl;
            break;
        }
        default:
            cout << "������������ ���." << endl;
        }
    }
}
