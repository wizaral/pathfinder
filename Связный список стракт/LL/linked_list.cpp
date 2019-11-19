#include <cstdlib>
#include <iostream>
#include "linked_list.h"

using namespace std;

Node *get_preelement(LinkedList *list, int number)
{
	if(number > list->size - 1 || number < 0)
		return nullptr;
	if(list && list->head && list->tail)
	{
		int i = 0;
		Node *tmp = list->head;
		while(i++ < (number - 1) && tmp->next)
			tmp = tmp->next;

		return tmp;
	}
	return nullptr;
}

void create_first(LinkedList *list)
{
	if(list)
	{
		Node *node = nullptr;
		node = new Node(list->head);
		if(node)
		{
			list->head = node;
			if(!list->tail)
				list->tail = node;
			list->size++;
		}
	}
}

void create_last(LinkedList *list)
{
	if(list && list->head && list->tail)
	{
		Node *node = nullptr;
		node = new Node(nullptr);
		if(node)
		{
			list->tail->next = node;
			list->tail = node;
			list->size++;
		}
	}
	else if(list)
		create_first(list);
}

void print(Node *node)
{
	if(node)
	{
		cout << "Имя: " << node->fname << ' ' << node->sname
		     << ' ' << node->patronymic << endl
		     << "Год рождения: " << node->yob << endl
		     << "Курс: " << node->course << endl
		     << "Группа: " << node->group << endl
		     << "Зачетная книжка: " << node->book << endl
		     << "Оценки: " << endl;
		for(int i = 0; i < 5; i++)
			cout << "Предмет " << i + 1 << ": " << node->results[i] << endl;
	}
}

void print(LinkedList *list)
{
	cout << endl;
	if(list && list->head && list->tail)
	{
		Node *node = list->head;
		while(node)
		{
			print(node);
			if(node->next)
				cout << endl;
			node = node->next;
		}
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

void delete_element(LinkedList *list, int number)
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
