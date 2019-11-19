#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define true 1			//заменяет в коде все "true" на "1"

Tree *create_tree()
{
	Tree *tree = NULL;
	while(!tree)		//пока не выделится память
		tree = (Tree *)malloc(sizeof(Tree));	//выделяет память

	tree->size = 0;		//задает параметры дерева
	tree->root = NULL;
	return tree;		//возвращает указатель на него
}

void delete_tree(Tree *tree)
{
	if(tree)	//проверка на NULL укаатель (дальше в коде будет постоянно)
	{
		delete_node(tree->root);	//удаляет элементы дерева рекурсивно
		free(tree);					//только потом удаляет саму основу дерева
	}
}

Node *create_node(Node *parent, int item)
{
	Node *node = NULL;	//ну ты понял. тут как и выше с памятью
	while(!node)
		node = (Node *)malloc(sizeof(Node));

	node->parent = parent;	//и параметры тоже
	node->left = node->right = NULL;
	node->item = item;

	if(!parent)		//если мы создаем корень дерева (у него нет предка)
		node->level = 0;	//он на 0 уровне
	else			//а если нет
		node->level = parent->level + 1;	//то он на уровень ниже (больше), чем его предок

	return node;	//вернули созданную ноду
}

void delete_node(Node *node)
{
	if(node)	//если нода не NULL
	{
		delete_node(node->left);	//рекурсивно удаляем её левую часть
		delete_node(node->right);	//и правую
		free(node);					//потом себя
	}
}

Node *min_value(Node *node)
{
	if(node && node->left)
		while(node->left)		//пока есть элемент слева
			node = node->left;	//шагаем влево (слева всегда меньше)
	return node;				//вернули указатель на ноду
}

Node *max_value(Node *node)
{
	if(node && node->right)		//тут так же но наоборот
		while(node->right)
			node = node->right;
	return node;
}

void insert_element(Tree *tree, int item)
{
	if(tree)
	{
		if(!tree->root)				//если в дереве нет корня, то создаем его
		{
			Node *node = NULL;	//тут понятно
			while(!node)
				node = create_node(tree->root, item);	//по факту передаем (NULL, число)

			tree->root = node;	//обозначили у дерева корень
			tree->size++;		//размер + 1
		}
		else	//если корень есть
		{
			Node *fast = tree->root;	//делаем два указателя
			Node *low = NULL;			//которыми шагаем по дереву

			while(true)		//вечный цикл (дальше будут точки выхода)
			{
				low = fast;	//"медленный" указатель равен "быстрому"

				if(item == fast->item)	//если такой элемент уже есть, то кикаемся из цикла
					break;
				else if(item < fast->item)	//если элемент меньше ноды
				{
					fast = fast->left;	//быстрый идет на шаг влево
					if(!fast)	//и теперь он слева, а если он NULL то место пустое и мы сюда вставляем наше число
					{
						Node *node = NULL;	//создаем ноду с нашим числом
						while(!node)
							node = create_node(low, item);

						low->left = node;	//поскольку у нас есть медленный (на шаг позади), то ему делаем левого "быстрым"
						tree->size++;		//то есть воткнули наше число в дерево и апнули размер
						break;				//и вышли из цикла
					}
				}
				else		//если больше, то зеркальные телодвижения для правого
				{
					fast = fast->right;
					if(!fast)
					{
						Node *node = NULL;
						while(!node)
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

void delete_element(Tree *tree, Node *node)
{
	if(tree && node)
	{
		if(node->left && node->right)		//если у удаляемой ноды есть оба потомка
		{
			Node *max = max_value(node->left);	//находим максимум _после неё_
			node->item = max->item;				//меняем значение у удаляемой ноды на найденное
			delete_element(tree, max);			//и удаляем ту ноду, значение которой взяли
			return;								//вышли из функции
		}
		else if(node->parent)	//если у удаляемой ноды есть предок (нода не корень (без предка))
		{
			if(node->left)		//если у неё только левый потомок
			{
				if(node == node->parent->left)			//если удаляемая нода у предка является левым потомоком
					node->parent->left = node->left;	//делаем у предка удаляемой ноды левым потомком левого потомка удаляемой ноды
				else									//если не левая, значит правая
					node->parent->right = node->left;	//делаем у предка удаляемой ноды правым потомком левого потомка удаляемой ноды
			}
			else if(node->right)	//если у удаляемой ноды только правый потомок (дальше зеркально к предыдущему блоку)
			{
				if(node == node->parent->right)
					node->parent->right = node->right;
				else
					node->parent->left = node->right;
			}
			else		//если у ноды нет потомоков
			{
				if(node == node->parent->left)	//если она левая у предка
					node->parent->left = NULL;	//делаем у предка левого NULL
				else							//зеркально:
					node->parent->right = NULL;
			}
		}
		else if(tree->root == node)	//если удаляем корень, но у него только один потомок, то делаем как с нодой с двумя потомками
		{
			if(node->left)
			{
				Node *max = max_value(node->left);
				tree->root->item = max->item;
				delete_element(tree, max);
				return;
			}
			else if(node->right)
			{
				Node *max = max_value(node->right);
				tree->root->item = max->item;
				delete_element(tree, max);
				return;
			}
			else
				tree->root = NULL;
		}
		free(node);		//если у нас выполнялся блок else if(node->parent), то надо удалить ноду
		tree->size--;	//и минуснуть размер
	}
}

Node *search_node(Node *node, int item)		//рекурсивный поиск
{
	if(node)	//если нода не NULL
	{
		if(item < node->item)	//если искомое значение меньше значения в ноде
			return search_node(node->left, item);	//перевызываем поиск для левого потомка

		else if(item > node->item)	//а если больше
			return search_node(node->right, item);	//то для правого

		return node;	//если предыдущие if() не были выполнены, то мы нашли наше значение и нужно его вернуть
	}
	return NULL;	//если ноды нет, то не нашли и вернули NULL
}

void delete_item(Tree *tree)
{
	if(tree)
	{
		int item;
		printf("Введите число для удаления: ");

		scanf("%i", &item);		//считываем число с клавиатуры
		Node *to_delete = search_node(tree->root, item);	//находим ноду с таким значением

		if(to_delete)		//если нашли
			delete_element(tree, to_delete);	//вызываем для него удаление
	}
}

void print_tree(Tree *tree)
{
	if(tree)
	{
		int print_type;

		do
		{
			printf("\nВведите тип вывода дерева.\n1 - Прямой.\n2 - ");
			printf("Симметричный.\n3 - Обратный.\nВведите: ");
			scanf("%i", &print_type);
		}
		while(print_type < 1 || print_type > 3);	//просим ввести число, пока не будет введено число от 1 до 3

		printf("\nКоличество элементов: %i\n", tree->size);		//печатаем кол-во элементов в дереве
		
		if(!tree->root)
			printf("Элементы отсутствуют.\n");
		else
		{
			printf("Корневой элемент:  %i\n", tree->root->item);	//и значение корня
			printf("Бинарное дерево: \n");

			switch(print_type)		//в зависимости от типа вывода дерева
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
					printf("Неправильный тип.\n");
			}
		}
	}
}

void add_elements(Tree *tree)
{
	FILE *file = fopen("data.txt", "r");	//открываем файл для чтения

	if(tree && file)	//если есть дерево и открыли файл
	{
		int tmp;
		while(fscanf(file, "%i", &tmp) != EOF)	//считываем из файла числа, пока не дойдем до конца
			insert_element(tree, tmp);			//вставляем элемент

		fclose(file);	//не забываем закрыть файл
	}
}

void pre_order(Node *node)
{
	if(node)
	{
		//printf("[%i][%i] ", node->item, node->level);
		printf("%i ", node->item);
		pre_order(node->left);
		pre_order(node->right);
	}
}

void in_order(Node *node)
{
	if(node)
	{
		in_order(node->left);
		//printf("[%i][%i] ", node->item, node->level);
		printf("%i ", node->item);
		in_order(node->right);
	}
}

void post_order(Node *node)
{
	if(node)
	{
		post_order(node->left);
		post_order(node->right);
		//printf("[%i][%i] ", node->item, node->level);
		printf("%i ", node->item);
	}
}

void swap_min_max(Tree *tree)
{
	if(tree)
	{
		Node *min = min_value(tree->root);	//находим минимум
		Node *max = max_value(tree->root);	//максимум

		int tmp = min->item;	//запоминаем минимум
		min->item = max->item;	//в минимум пишем максимум
		max->item = tmp;		//в максимум запомненный минимум
	}
}

void print_min_max(Tree *tree)
{
	if(tree)
	{
		Node *min = min_value(tree->root);
		Node *max = max_value(tree->root);
		printf("Минимум\nЗначение: %i\nУровень: %i\n", min->item, min->level);
		printf("Максимум\nЗначение: %i\nУровень: %i\n", max->item, max->level);
	}
}

void add_item(Tree *tree)
{
	if(tree)
	{
		int item;
		printf("Введите число для добавления: ");	//просим элемент
		scanf("%i", &item);							//считываем из консоли
		insert_element(tree, item);					//вставляем в дерево
	}
}

void search_item(Tree *tree)
{
	if(tree)
	{
		int item;
		printf("Введите число для поиска: ");
		scanf("%i", &item);
		
		if(search_node(tree->root, item))	//если нашли
			printf("Найдено!\n");
		else								//иначе
			printf("Не найденою\n");
	}
}
