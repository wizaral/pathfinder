#ifndef linked_list_h
#define linked_list_h
#include <cstring>

using namespace std;

struct Node
{
	Node(Node *next)
	{
		cout << endl;
		this->next = next;
		cout << "¬ведите год рождени€: ";
		cin >> this->yob;
		cout << "¬ведите им€: ";
		cin >> this->fname;
		cout << "¬ведите фамилию: ";
		cin >> this->sname;
		cout << "¬ведите отчество: ";
		cin >> this->patronymic;
		cout << "¬ведите курс: ";
		cin >> this->course;
		cout << "¬ведите номер группы: ";
		cin >> this->group;
		cout << "¬ведите номер зачетки: ";
		cin >> this->book;

		this->results = new int[5];
		for(int i = 0; i < 5; i++)
		{
			cout << "¬ведите оценку [" << i + 1 << "]: ";
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

Node *get_preelement(LinkedList*, int);
void create_first(LinkedList*);
void create_last(LinkedList*);
void print(LinkedList*);

void delete_list(LinkedList*);
void delete_last(LinkedList*);
void delete_first(LinkedList*);
void delete_element(LinkedList*, int);

#endif
