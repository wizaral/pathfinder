#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

struct Node
{
	Node(Node *next)
	{
		cout << endl;
		this->next = next;
		cout << "Введите год рождения: ";
		cin >> this->yob;
		cout << "Введите имя: ";
		cin >> this->fname;
		cout << "Введите фамилию: ";
		cin >> this->sname;
		cout << "Введите отчество: ";
		cin >> this->patronymic;
		cout << "Введите курс: ";
		cin >> this->course;
		cout << "Введите номер группы: ";
		cin >> this->group;
		cout << "Введите номер зачетки: ";
		cin >> this->book;

		this->results = new int[5];
		for(int i = 0; i < 5; i++)
		{
			cout << "Введите оценку [" << i + 1 << "]: ";
			cin >> this->results[i];
		}
	}

	Node(const Node &u)
	{
		this->yob = u.yob;
		this->book = u.book;
		this->group = u.group;
		this->fname = u.fname;
		this->sname = u.sname;
		this->course = u.course;
		this->patronymic = u.patronymic;

		for(int i = 0; i < 5; i++)
			this->results[i] = u.results[i];
	}

	~Node()
	{
		delete []this->results;
	}

	int yob;	//year of birth
	int book;
	int group;
	int course;

	string fname;
	string sname;
	string patronymic;

	int *results;
	Node *next;
};

struct LinkedList
{
	LinkedList()
	{
		this->size = 0;
		this->head = this->tail = nullptr;
	}

	LinkedList(const LinkedList &u)
	{
		this->size = 0;
		this->head = this->tail = nullptr;
		Node *to_add = u.head;

		while(to_add)
		{
			if(this->head && this->tail)
			{
				Node *node = nullptr;
				node = new Node(*to_add);
				node->next = nullptr;

				if(node)
				{
					this->tail->next = node;
					this->tail = node;
					this->size++;
				}
			}
			else
			{
				Node *node = nullptr;
				node = new Node(*to_add);
				node->next = this->head;

				if(node)
				{
					this->head = this->tail = node;
					this->size++;
				}
			}
			to_add = to_add->next;
		}
	}

	~LinkedList()
	{
		if(this->head && this->tail)
		{
			Node *last = nullptr;
			while(this->head->next)
			{
				last = this->head;
				this->head = this->head->next;
				delete last;
				this->size--;
			}
			delete this->head;

			this->head = this->tail = nullptr;
			this->size--;
		}
	}

	int size;
	Node *head, *tail;
};

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

int main()
{
	system("chcp 1251 & cls");
	LinkedList* list = new LinkedList();
	char choice;

	do
	{
		cout << "Сделайте выбор:" << endl
		     << "1 - Добавить информацию о студенте в начало списка." << endl
		     << "2 - Добавить информацию о студенте в конец  списка." << endl
		     << "3 - Удалить информацию о  первом   студенте." << endl
		     << "4 - Удалить информацию о последнем студенте." << endl
		     << "5 - Удалить информацию о студенте по номеру." << endl
		     << "6 - Напечатать информацию о всех студентах." << endl
		     << "7 - Очистить список." << endl
		     << "8 - Закончить работу." << endl
		     << "Введите: ";
		cin >> choice;

		switch(choice)
		{
			case '1':
				create_first(list);
				break;
			case '2':
				create_last(list);
				break;
			case '3':
				delete_first(list);
				break;
			case '4':
				delete_last(list);
				break;
			case '5':
				if(list->size)
				{
					int number;
					cout << endl << "Введите номер студента для удаления: ";
					cin >> number;
					delete_element(list, number);
				}
				else
					cout << endl;
				break;
			case '6':
				print(list);
				break;
			case '7':
			case '8':
				if(list->size)
					cout << endl << "Список удалён" << endl;
				delete_list(list);
				break;
			default:
				cout << endl << "Неправильный ввод!" << endl;
		}
		cout << endl;
	}
	while(choice != '8');

	delete list;
	system("pause");
	return 0;
}
