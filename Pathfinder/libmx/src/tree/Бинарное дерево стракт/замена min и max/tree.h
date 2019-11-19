#ifndef tree_h
#define tree_h

typedef struct Node			//структура элемента дерева
{
	int item, level;		//значение и уровень ноды
	struct Node *left, *right, *parent;	//указатель на левого потомка, правого потомка и своего предка
}Node;

typedef struct Tree			//структура основания дерева
{
	int size;		//кол-во элементов в дереве
	Node *root;		//указатель на корень дерева
}Tree;

Tree *create_tree();		//создает основу дерева
void delete_tree(Tree*);	//удаляет всё дерево с элементами

Node *create_node(Node*, int);	//создает элемент дерева
void delete_node(Node*);		//удаляет один элемент дерева

Node *min_value(Node*);		//возвращает минимум в дереве
Node *max_value(Node*);		//максимум

void insert_element(Tree*, int);	//вставляет элемент в дерево
void delete_element(Tree*, Node*);	//вынимает элемент из дерева

Node *search_node(Node*, int);	//ищет элемент в дереве с нужным значением
void delete_item(Tree*);		//запрашивает число, которое нужно удалить и удаляет

void print_tree(Tree*);		//выводит всё дерево
void add_elements(Tree*);	//добавляет элементы из файла

void pre_order(Node*);		//прямой обход
void in_order(Node*);		//симметричный
void post_order(Node*);		//обратный

void swap_min_max(Tree*);	//меняет мин макс местами
void print_min_max(Tree*);	//печатает мин макс

void add_item(Tree*);		//запрашивает число для добавления и добавляет
void search_item(Tree*);	//спрашивает число дял поиска и ищет
void empty_tree(Tree*);		//очищает дерево

#endif
