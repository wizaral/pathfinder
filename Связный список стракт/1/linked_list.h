#ifndef linked_list_h
#define linked_list_h

struct Node
{
	int item;
	Node *next;
};

struct LinkedList
{
	unsigned size;
	Node *head, *tail;
};

Node *create_node(int, Node*);
LinkedList *create_list(int);
LinkedList *create_list(const LinkedList&);

Node *get_preelement(LinkedList*, Node*);
Node *get_preelement(LinkedList*, unsigned);

void create_first(LinkedList*, int);
void create_last(LinkedList*, int);
void print(LinkedList*);

void delete_list(LinkedList*);
void delete_last(LinkedList*);
void delete_first(LinkedList*);
void delete_element(LinkedList*, unsigned);

#endif
