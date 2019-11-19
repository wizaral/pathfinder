#ifndef tree_h
#define tree_h

//это одно звено дерева. оно состоит из множества таких. дальше "нода"
struct Node
{
	int value;		//хранимое значение
	Node *left;		//левый потомок
	Node *right;	//правый потомок
	Node *parent;	//предок узла
};

//а это структура, в которой удобно хранить указатель на корень
//и количество элементов в дереве. дальше "основание"
struct Tree
{
	int count;		//кол-во
	Node *root;		//указатель на корень
};

Node *create_node(Node*, int);		//создает ноду с int значением
void delete_node(Node*);			//рекурсивно удаляет потомков и себя

Tree *create_tree();				//создает основание
void delete_tree(Tree*);			//удаляет всё дерево с основанием

void insert_item(Tree*, int);		//вставка элемента в дерево
void delete_item(Tree*, Node*);		//удаление ноды из дерева
void delete_item(Tree*, int);		//позволяет удалить ноду из дерева, зная её значение

Node *get_min(Node*);				//возвращает минимальное значение в ветке
Node *get_max(Node*);				//возвращает максимальное значение в ветке
Node *search(Node*, int);			//ищет ноду с заданым значением

int get_height(Node*);				//возвращает высоту дерева
int leaf_amount(Node*);				//возвращает кол-во листьев в дереве
bool compare(Node*, Node*);			//сравнивает два дерева (изоморфизм)

void preorder_print(Node*);			//прямой обход + печать
void inorder_print(Node*);			//симметричный + печать
void postorder_print(Node*);		//обратный + печать
void print(Tree*, int);				//обертка для печати дерева

#endif
