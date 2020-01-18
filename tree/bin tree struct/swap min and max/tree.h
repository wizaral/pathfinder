#ifndef tree_h
#define tree_h

typedef struct Node //��������� �������� ������
{
    int item, level;                    //�������� � ������� ����
    struct Node *left, *right, *parent; //��������� �� ������ �������, ������� ������� � ������ ������
} Node;

typedef struct Tree //��������� ��������� ������
{
    int size;   //���-�� ��������� � ������
    Node *root; //��������� �� ������ ������
} Tree;

Tree *create_tree();      //������� ������ ������
void delete_tree(Tree *); //������� �� ������ � ����������

Node *create_node(Node *, int); //������� ������� ������
void delete_node(Node *);       //������� ���� ������� ������

Node *min_value(Node *); //���������� ������� � ������
Node *max_value(Node *); //��������

void insert_element(Tree *, int);    //��������� ������� � ������
void delete_element(Tree *, Node *); //�������� ������� �� ������

Node *search_node(Node *, int); //���� ������� � ������ � ������ ���������
void delete_item(Tree *);       //����������� �����, ������� ����� ������� � �������

void print_tree(Tree *);   //������� �� ������
void add_elements(Tree *); //��������� �������� �� �����

void pre_order(Node *);  //������ �����
void in_order(Node *);   //������������
void post_order(Node *); //��������

void swap_min_max(Tree *);  //������ ��� ���� �������
void print_min_max(Tree *); //�������� ��� ����

void add_item(Tree *);    //����������� ����� ��� ���������� � ���������
void search_item(Tree *); //���������� ����� ��� ������ � ����
void empty_tree(Tree *);  //������� ������

#endif
