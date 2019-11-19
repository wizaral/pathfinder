#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#define true 1

void push(queue **head, node *a_node)
{
	if(a_node)
	{
		queue *a_part = (queue *)malloc(sizeof(queue));
		if(a_part)
		{
			a_part->save_node = a_node;
			a_part->next = NULL;
			
			if(*head)
			{
				queue *tmp = (*head);
				while(tmp->next)
					tmp = tmp->next;
				
				tmp->next = a_part;
			}
			else
				(*head) = a_part;
		}
		else
		{
			printf("Ошибка создания очереди!\n");
			return;
		}
	}
}

node *pop(queue **head)
{
	if(*head)
	{
		queue *tmp = (*head);
		(*head) = (*head)->next;
		
		return tmp->save_node;
	}
	else
		return NULL;
}

tree *create_tree()
{
	tree *a_tree = (tree *)malloc(sizeof(tree));
	if(!a_tree)
	{
		printf("Ошибка создания корня!\n");
		exit(1);
	}
	
	a_tree->count = 0;
	a_tree->root = NULL;
	return a_tree;
}

node *create_node(node *a_parent, int a_value)
{
	node *a_node = (node *)malloc(sizeof(node));
	if(a_node)
	{
		a_node->parent = a_parent;
		a_node->left = NULL;
		a_node->right = NULL;
		a_node->value = a_value;
		
		if(!a_parent)
			a_node->level = 0;
		else
			a_node->level = a_parent->level + 1;
		
		return a_node;
	}
	else
	{
		printf("Ошибка при создании элемента!\n");
		return NULL;
	}
}

void destroy_node(node *a_node)
{
	if(a_node)
	{
		destroy_node(a_node->left);
		destroy_node(a_node->right);
		free(a_node);
	}
}

void destroy_tree(tree *a_tree)
{
	if(a_tree)
	{
		destroy_node(a_tree->root);
		free(a_tree);
	}
}

//=========================================================

node *min_value(node *a_node)
{
	if(a_node->left)
	{
		while(a_node->left)
			a_node = a_node->left;
		return a_node;
	}
	return NULL;
}

node *max_value(node *a_node)
{
	if(a_node->right)
	{
		while(a_node->right)
			a_node = a_node->right;
		return a_node;
	}
	return NULL;
}

//=========================================================

void insert_element(tree *a_tree, int a_value)
{
	if(a_tree)
	{
		if(!a_tree->root)
		{
			node *a_node = create_node(a_tree->root, a_value);	//(NULL, a_value);
			if(a_node)
			{
				a_tree->root = a_node;
				a_tree->count++;
			}
			else
			{
				printf("Ошибка при добавлении элемента!\n");
				return;
			}
		}
		else
		{
			node *a_fast = a_tree->root;
			node *a_low = NULL;
			
			while(true)
			{
				a_low = a_fast;
				
				if(a_value == a_fast->value)
				{
					printf("Такой элемент уже был добавлен.\n");
					break;
				}
				else if(a_value < a_fast->value)
				{
					a_fast = a_fast->left;
					if(!a_fast)						//лист
					{
						node *a_node = create_node(a_low, a_value);
						a_low->left = a_node;
						a_tree->count++;
						break;
					}
				}
				else
				{
					a_fast = a_fast->right;
					if(!a_fast)						//лист
					{
						node *a_node = create_node(a_low, a_value);
						a_low->right = a_node;
						a_tree->count++;
						break;
					}
				}
			}
		}
	}
	else
		printf("Ошибка!\n");
}

void delete_element(tree *a_tree, node *a_node)
{
	if(a_tree && a_node)
	{
		if(a_node->left && a_node->right)
		{
			node *a_max = max_value(a_node->left);
			a_node->value = a_max->value;
			delete_element(a_tree, a_max);
			return;
		}
		else if(a_node->parent)
		{
			if(a_node->left)
			{
				if(a_node == a_node->parent->left)
					a_node->parent->left = a_node->left;
				else
					a_node->parent->right = a_node->left;
			}
			else if(a_node->right)
			{
				if(a_node == a_node->parent->right)
					a_node->parent->right = a_node->right;
				else
					a_node->parent->left = a_node->right;
			}
			else										//leaf
			{
				if(a_node == a_node->parent->left) 
					a_node->parent->left = NULL;
				else
					a_node->parent->right = NULL;
			}
		}
		else if(a_tree->root == a_node)
		{
			if(a_node->left)
			{
				node *a_max = max_value(a_node->left);
				a_tree->root->value = a_max->value;
				delete_element(a_tree, a_max);
				return;
			}
			else if(a_node->right)
			{
				node *a_max = max_value(a_node->right);
				a_tree->root->value = a_max->value;
				delete_element(a_tree, a_max);
				return;
			}
			else										//leaf
			{
				a_tree->root = NULL;
			}
		}
		free(a_node);
		a_tree->count--;
	}
}

//=========================================================

node *search_node(node *a_node, int a_value)
{
	if(a_node)
	{
		if(a_value < a_node->value)
			return search_node(a_node->left, a_value);
		
		else if(a_value > a_node->value)
			return search_node(a_node->right, a_value);
		
		else
			return a_node;
	}
	else
		return NULL;
}

void delete_element_by_value(tree *a_tree, int a_value)
{
	if(a_tree)
	{
		node *to_delete = search_node(a_tree->root, a_value);
		
		if(to_delete)
		{
			delete_element(a_tree, to_delete);
			return;
		}
	}
	printf("Ошибка!\n");
}

//=========================================================

void preorder_print(node *a_node)
{
	if(a_node)
	{
		//printf("[%i][%i] ", a_node->value, a_node->level);
		printf("%i ", a_node->value);
		preorder_print(a_node->left);
		preorder_print(a_node->right);
	}
}

void inorder_print(node *a_node)
{
	if(a_node)
	{
		inorder_print(a_node->left);
		//printf("[%i][%i] ", a_node->value, a_node->level);
		printf("%i ", a_node->value);
		inorder_print(a_node->right);
	}
}

void postorder_print(node *a_node)
{
	if(a_node)
	{
		postorder_print(a_node->left);
		postorder_print(a_node->right);
		//printf("[%i][%i] ", a_node->value, a_node->level);
		printf("%i ", a_node->value);
	}
}

void levelorder_print(tree *a_tree)
{
	if(a_tree)
	{
		int count = a_tree->count;
		queue *head = NULL;
		node *tmp = NULL;
		push(&head, a_tree->root);
		
		while(count--)
		{
			tmp = pop(&head);
			push(&head, tmp->left);
			push(&head, tmp->right);
			//printf("[%i][%i] ", tmp->value, tmp->level);
			printf("%i ", tmp->value);
		}
	}
}

void preorder_print_file(node *a_node, FILE *a_file)
{
	if(a_node)
	{
		//fprintf(a_file, "[%i][%i] ", a_node->value, a_node->level);
		fprintf(a_file, "%i ", a_node->value);
		preorder_print_file(a_node->left, a_file);
		preorder_print_file(a_node->right, a_file);
	}
}

void inorder_print_file(node *a_node, FILE *a_file)
{
	if(a_node)
	{
		inorder_print_file(a_node->left, a_file);
		//fprintf(a_file, "[%i][%i] ", a_node->value, a_node->level);
		fprintf(a_file, "%i ", a_node->value);
		inorder_print_file(a_node->right, a_file);
	}
}

void postorder_print_file(node *a_node, FILE *a_file)
{
	if(a_node)
	{
		postorder_print_file(a_node->left, a_file);
		postorder_print_file(a_node->right, a_file);
		//fprintf(a_file, "[%i][%i] ", a_node->value, a_node->level);
		fprintf(a_file, "%i ", a_node->value);
	}
}

void levelorder_print_file(tree *a_tree, FILE *a_file)
{
	if(a_tree)
	{
		int count = a_tree->count;
		queue *head = NULL;
		node *tmp = NULL;
		push(&head, a_tree->root);
		
		while(count--)
		{
			tmp = pop(&head);
			push(&head, tmp->left);
			push(&head, tmp->right);
			//fprintf(a_file, "[%i][%i] ", tmp->value, tmp->level);
			fprintf(a_file, "%i ", tmp->value);
		}
	}
}

void print_tree(tree *a_tree)
{
	if(a_tree)
	{
		int print_type, file_type;
		do{
			printf("Записывать дерево в файл?\n");
			printf("1 - Да.\n2 - Нет.\nВведите: ");
			scanf("%i", &file_type);
		}while(file_type < 1 || file_type > 2);
		
		do{
			printf("\nВведите тип вывода дерева.\n1 - Прямой.\n2 - ");
			printf("Симметричный.\n3 - Обратный.\n4 - По уровням.\nВведите: ");
			scanf("%i", &print_type);
		}while(print_type < 1 || print_type > 4);
		
		if(file_type == 1)
		{
			FILE *file = fopen("result.txt", "w");
			if(file)
			{
				printf("\nКоличество элементов: %i\n", a_tree->count);
				printf("Корневой элемент: %i\n", a_tree->root->value);
				
				fprintf(file, "Количество элементов: %i\n", a_tree->count);
				fprintf(file, "Корневой элемент: %i\n", a_tree->root->value);
				
				if(a_tree->root)
				{
					printf("Бинарное дерево: \n");
					fprintf(file, "Бинарное дерево: \n");
					
					switch(print_type)
					{
					case 1:
						preorder_print(a_tree->root);
						preorder_print_file(a_tree->root, file);
						printf("\n");
						break;
					case 2:
						inorder_print(a_tree->root);
						inorder_print_file(a_tree->root, file);
						printf("\n");
						break;
					case 3:
						postorder_print(a_tree->root);
						postorder_print_file(a_tree->root, file);
						printf("\n");
						break;
					case 4:
						levelorder_print(a_tree);
						levelorder_print_file(a_tree, file);
						printf("\n");
						break;
					default:
						printf("Неправильный тип.\n");
					}
				}
				fflush(file);
				fclose(file);
			}
		}
		else
		{
			printf("\nКоличество элементов: %i\n", a_tree->count);
			printf("Корневой элемент:  %i\n", a_tree->root->value);
			
			if(a_tree->root)
			{
				printf("Бинарное дерево: \n");
				
				switch(print_type)
				{
				case 1:
					preorder_print(a_tree->root);
					printf("\n");
					break;
				case 2:
					inorder_print(a_tree->root);
					printf("\n");
					break;
				case 3:
					postorder_print(a_tree->root);
					printf("\n");
					break;
				case 4:
					levelorder_print(a_tree);
					printf("\n");
					break;
				default:
					printf("Неправильный тип.\n");
				}
			}
		}
	}
}

//=========================================================

void add_elements(tree *a_tree)
{
	FILE *file = fopen("data.txt", "r");
	
	if(a_tree && file)
	{
		int tmp;
		while(fscanf(file, "%i", &tmp) != EOF)
			insert_element(a_tree, tmp);
		
		fclose(file); 
	}
}

long long int levelorder(node *a_node)
{
	if(a_node)
	{
		if(a_node->level == 3)
			return a_node->value;
		else
			return levelorder(a_node->left) * levelorder(a_node->right);
	}
	else
		return 1;
}

void my_task(tree *a_tree)
{
	if(a_tree)
	{
		long long int result = levelorder(a_tree->root);
		printf("\nПроизведение всех элементов третьего уровня дерева: %lli\n", result);
	}
}
