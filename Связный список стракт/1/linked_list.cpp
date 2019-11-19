#include <cstdlib>
#include <iostream>
#include "linked_list.h"

using namespace std;

Node *create_node(int item, Node *next)
{
	Node *node = nullptr;
	node = new Node;
	if(node)
	{
		node->item = item;
		node->next = next;
	}
	return node;
}

LinkedList *create_list(int item)
{
	LinkedList *list = nullptr;
	list = new LinkedList;
	if(list)
	{
		list->size = 0;
		list->head = list->tail = nullptr;
		create_first(list, item);
	}
	return list;
}

LinkedList *create_list(const LinkedList &u)
{
	LinkedList *list = nullptr;
	list = new LinkedList;
	if(list)
	{
		list->size = 0;
		list->head = list->tail = nullptr;
		Node *to_add = u.head;

		while(to_add)
		{
			if(list->head && list->tail)
			{
				Node *node = nullptr;
				node = create_node(to_add->item, nullptr);

				if(node)
				{
					list->tail->next = node;
					list->tail = node;
					list->size++;
				}
			}
			else
			{
				Node *node = nullptr;
				node = create_node(to_add->item, list->head);

				if(node)
				{
					list->head = list->tail = node;
					list->size++;
				}
			}
			to_add = to_add->next;
		}
	}
	return list;
}

Node *get_preelement(LinkedList *list, Node *node)
{
	if(list && list->head && list->tail)
	{
		Node *tmp = list->head;
		while(tmp->next && tmp->next != node)
			tmp = tmp->next;

		return tmp;
	}
	return nullptr;
}

Node *get_preelement(LinkedList *list, unsigned number)
{
	if(number > list->size - 1)
		return nullptr;
	if(list && list->head && list->tail)
	{
		unsigned i = 0;
		Node *tmp = list->head;
		while(i++ < (number - 1) && tmp->next)
			tmp = tmp->next;

		return tmp;
	}
	return nullptr;
}

void create_first(LinkedList *list, int item)
{
	if(list)
	{
		Node *node = nullptr;
		node = create_node(item, list->head);
		if(node)
		{
			list->head = node;
			if(!list->tail)
				list->tail = node;
			list->size++;
		}
	}
}

void create_last(LinkedList *list, int item)
{
	if(list && list->head && list->tail)
	{
		Node *node = nullptr;
		node = create_node(item, nullptr);
		if(node)
		{
			list->tail->next = node;
			list->tail = node;
			list->size++;
		}
	}
	else if(list)
		create_first(list, item);
}

void print(LinkedList *list)
{
	if(list && list->head && list->tail)
	{
		Node *node = list->head;
		while(node->next)
		{
			cout << node->item << ", ";
			node = node->next;
		}
		cout << node->item << endl;
	}
	else if(list)
		cout << "Пустой список." << endl;
}

void delete_list(LinkedList *list)
{
	if(list && list->head && list->tail)
	{
		Node *last = nullptr;
		while(list->head->next)
		{
			last = list->head;
			list->head = list->head->next;
			delete last;
			list->size--;
		}
		delete list->head;

		list->head = list->tail = nullptr;
		list->size--;
	}
	if(list)
		delete list;
}

void delete_last(LinkedList *list)
{
	if(list && list->head && list->tail)
	{
		if(list->head == list->tail)
		{
			delete list->head;
			list->head = list->tail = nullptr;
			list->size--;
		}
		else
		{
			Node *pre_last = list->head;
			while(pre_last->next->next)
				pre_last = pre_last->next;

			delete list->tail;
			pre_last->next = nullptr;
			list->tail = pre_last;
			list->size--;
		}
	}
}

void delete_first(LinkedList *list)
{
	if(list && list->head && list->tail)
	{
		if(list->head == list->tail)
		{
			delete list->head;
			list->head = list->tail = nullptr;
			list->size--;
		}
		else
		{
			Node *last = list->head;
			list->head = list->head->next;
			delete last;
			list->size--;
		}
	}
}

void delete_element(LinkedList *list, unsigned number)
{
	if(list && list->head && list->tail)
	{
		if(!number)
			delete_first(list);
		else if(number == list->size - 1)
			delete_last(list);
		else
		{
			Node *pre_el = get_preelement(list, number);
			Node *to_del = pre_el->next;

			pre_el->next = to_del->next;
			delete to_del;
			list->size--;
		}
	}
}
