#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

Node *create_node(Node *parent, int value)
{
	Node *node = new Node;	//выделили память
	if(node)	//если память выделилась, то указатель != NULL
	{
		node->parent = parent;	//указываем родителя
		node->left = nullptr;	//левого нет
		node->right = nullptr;	//правого тоже
		node->value = value;	//значение запомнили
		return node;			//и вернули указатель на готовую ноду
	}
	else	//а если не выделили, то печаль беда
	{
		cout << "Ошибка при создании элемента!" << endl;
		return nullptr;	//nullptr тоже самое, что и NULL
	}
}

void delete_node(Node *node)
{
	if(node)	//если нода существует
	{
		delete_node(node->left);	//рекурсивно доходимв левую часть
		delete_node(node->right);	//потом в правую до упора
		delete node;				//и только потом удаляем ноду
	}
}

//===============================================================

Tree *create_tree()
{
	Tree *tree = new Tree;		//ну ты понял
	if(tree)
	{
		tree->count = 0;		//пока что пустое
		tree->root = nullptr;	//и корня нет
		return tree;			//вернули
	}
	cout << "Ошибка создания корня!" << endl;
	exit(12345);	//это заершение работы с числом 12345
	//чтобы точно знать, что за нах
	//в main() я бы просто написал return 12345;
	//но в вызванной функции это делается так
}

void delete_tree(Tree *tree)
{
	if(tree)	//проверяем указатель
	{
		delete_node(tree->root);	//вызываем рекурсивное удаление дерева
		delete tree;				//и только когда оно пустое удаляем основу
	}
}

void insert_item(Tree *tree, int value)
{
	if(tree)
	{
		//если у нас tree->root == NULL то дерево пустое
		//и тогда создаем корневой элемент
		if(!tree->root)
		{
			//тут фокус в том, что у нас tree->root == NULL
			//и если передавать его как параметр для crt_nd()
			//для присвоения родителю, то получается вполне логичная штука
			//что у корня нет предка

			Node *node = create_node(tree->root, value);
			if(node)
			{
				tree->root = node;	//делаем элемент корнем древа
				tree->count++;		//и увеличиваем размер
			}
			else
			{
				cout << "Ошибка при добавлении элемента!" << endl;
				return;												//пизда
			}
		}

		//в случае, если у нас уже есть корень
		//добавление будет немного подругому
		else
		{
			Node *fast = tree->root;	//указатель, который "на шаг впереди"
			Node *slow = nullptr;		//чем вот эта медленная мудила

			while(true)		//вечный цыкл, у которого ДОЛЖЕН быть выход
			{
				slow = fast;	//приравниваем медленному быстрого

				if(value == fast->value)	//в случае, если число уже есть в дереве, то второго быть не может
				{
					cout << "Такой элемент уже был добавлен." << endl;
					break;
				}
				else if(value < fast->value)	//если число меньше
				{
					fast = fast->left;	//сейчас указатель fast изменился и теперь равен своему левому потомку

					//и если left на этот момент был NULL, то мы нашли место для вставки
					if(!fast)
					{
						//создаем ноду, которой предком делаем slow
						Node *node = create_node(slow, value);

						slow->left = node;	//и приравниваем предку левого потомка
						tree->count++;		//не забываем апнуть размер
						break;				//а вот и ВЫХОД из цикла
					}
				}
				else		//если больше
				{
					//тут тоже самое, но для правого
					fast = fast->right;
					if(!fast)
					{
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

void delete_item(Tree *tree, Node *node)		//САМАЯ ЗЛО****АЯ ФУНКЦИЯ В ЭТОЙ ЛАБЕ
{
	//проверяем указатель на дерево и ноду для удаления
	if(tree && node)
	{
		if(node->left && node->right)	//в случае, если у удаляемой ноды есть и левый и правый потомки
		{
			Node *max = get_max(node->left);	//заходим в гугл и читаем про удаление из бинарного дерева
			node->value = max->value;			//ибо я ебал рассказывать как это делается
			delete_item(tree, max);				//потому что тут коментов будет больше чем кода
			//а надо с картинками же показывать
			return;		//но всё же добавлю, что тут return потому что в конце функции прописан delete node
			//а мы уже вызвали новую итерацию удаления строчкой кода выше
		}

		//если заигнорили предыдущую проверку, значит у ноды либо левая либо правая
		//но сначала проверим, есть ли у неё предок (вдруг корень надА удалить)

		else if(node->parent)
		{
			if(node->left)	//если предок есть и только левая
			{
				//поскольку предок и потомок имеют указатели друг на друга, то
				//запись node->left->parent->left равна записи node->left
				//и за счет этого свойства выезжаем))0)

				//если перефразировать следующую строку кода, то получается
				//если я у своего предка левый
				if(node == node->parent->left)
					//делаем у предка удаляемой ноды левым потомком своего левого потомка
					//а себя удалим в конце этой функции (прям в конце)
					node->parent->left = node->left;

				//а если не левый, значит правый
				else
					node->parent->right = node->left;
			}
			else if(node->right)	//если предок есть и только правая
			{
				//тут такой же код, но "зеркальный" для другой стороны

				if(node == node->parent->right)
					node->parent->right = node->right;
				else
					node->parent->left = node->right;
			}
			else	//а если у ноды нет потомков (удаляем лист)
			{
				if(node == node->parent->left)		//в зависимости от своего положения
					node->parent->left = nullptr;	//делаем у предка указатель NULL
				else
					node->parent->right = nullptr;
			}
		}

		//если же нам надо удалить корень, то не паримся
		//просто заменяем ему значение как в первом случае
		//и уже удаляем того лоха, у которого спиздили значение

		else if(tree->root == node)
		{
			//на данный момент мы знаем, что у ноды максимум один потомок
			//иначе бы она попала в самый первый if() этой функции

			if(node->left)
			{
				Node *tmp = get_max(node->left);	//тут нашли
				tree->root->value = tmp->value;		//тут "позаимствовали
				delete_item(tree, tmp);				//тут удалли лоха
				return;					//и вышли, потому что удяляли строчкой выше
			}
			else if(node->right)	//те же яйца в профиль
			{
				Node *tmp = get_max(node->right);
				tree->root->value = tmp->value;
				delete_item(tree, tmp);
				return;
			}
			else	//а если у нас в дереве только корень
			{
				tree->root = nullptr;	//просто делаем в основе указатель NULL
				//и удаляем строчкой ниже
			}
		}
		delete node;	//удаление ноды, если не перевызывали функцию
		tree->count--;	//уменьшили размер
	}
}

void delete_item(Tree *tree, int value)
{
	if(tree)	//чекнули дерево на предмет существования в нашей реальности
	{
		Node *node = search(tree->root, value);	//нашли ноду с таким значением
		if(node)	//если такая в дереве есть
			delete_item(tree, node);	//то вызываем удаление, которое выше
		//а если нет, то и хуй с ним
	}
}

Node *search(Node *node, int value)		//рекурсивная хуила, будь внимателен
{
	if(!node)			//если в функцию попал пустой указатель
		return nullptr;	//вернули NULL и забыли

	//если значение ноды, в которой находимся меньше, идем влево
	else if(value < node->value)
		return search(node->left, value);	//возвращаем результат этой функции

	//наоборот вправо
	else if(value > node->value)
		return search(node->right, value);	//аналогично (АХТУНГ РЕКУРСИЯ)

	//если не больше не меньше, то нашли
	else
		return node;	//и вернули
}

//===============================================================

int get_height(Node *node)	//тоже рекурсивный пидр
{
	if(node)
	{
		int h1 = get_height(node->left);
		int h2 = get_height(node->right);

		//гугли тернарный оператор
		return h1 > h2 ? (h1 + 1) : (h2 + 1);

		//тут такая хреня, но в одну строчку
		/*if(h1 > h2)
			return h1 + 1;
		else
			return h2 + 1;*/
	}
	return 0;	//если попали на NULL ноду вернули 0
}

int leaf_amount(Node* node)	//и даже он
{
	if(!node)		//если попали на NULL ноду - вернули 0
		return 0;
	if(!node->left && !node->right)	//если попали на лист - 1
		return 1;

	//если заигнорили предыдущие строки
	//зачит мы в ноде, которая не лист
	//тогда вызываем функцию на каждого потомка ноды
	return leaf_amount(node->left) + leaf_amount(node->right);
}

bool compare(Node *v1, Node *v2)	//а вот это самая пиздатая функция в одну строчку
{
	//и так, тут такое
	/*
	if(v1 != NULL && v2 != NULL)
	{
		if(v1->value == v2->value)
		{
			if(compare(v1->left, v2->left) == true)	//сама себя вызывает тут
			{
				if(compare(v1->right, v2->right) == true)	//и тут
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
		//типо один из них NULL а второй нет - значит разные
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

Node *get_min(Node *node)
{
	while(node->left)
		node = node->left;	//упарывается влево, потому что слева всегда меньше
	return node;
}

Node *get_max(Node *node)
{
	while(node->right)
		node = node->right;	//наоборот, ну ты понял
	return node;
}

//===============================================================

//это гугли, мне лень и долго, проще на картинке

void preorder_print(Node *node)
{
	if(node)
	{
		cout << node->value << ' ';
		preorder_print(node->left);
		preorder_print(node->right);
	}
}

void inorder_print(Node *node)
{
	if(node)
	{
		inorder_print(node->left);
		cout << node->value << ' ';
		inorder_print(node->right);
	}
}

void postorder_print(Node *node)
{
	if(node)
	{
		postorder_print(node->left);
		postorder_print(node->right);
		cout << node->value << ' ';
	}
}

//вообще она была больше и поинтереснее, просто для лабы обрезал
void print(Tree *tree, int type)
{
	if(tree && tree->root)
	{
		switch(type)
		{
			case 1:
				{
					preorder_print(tree->root);
					cout << endl;
					break;
				}
			case 2:
				{
					inorder_print(tree->root);
					cout << endl;
					break;
				}
			case 3:
				{
					postorder_print(tree->root);
					cout << endl;
					break;
				}
			default:
				cout << "Неправильный тип." << endl;
		}
	}
}
