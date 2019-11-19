#ifndef tree_h
#define tree_h

#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:
		Node(T*, Node*, bool = true);
		Node(const Node&);
		~Node();

		T *get_item() const;
		Node *get_next() const;
		void set_item(T*);
		void set_next(Node*);
	private:
		T *item;
		Node *left, *right, *parent;
};

template <class T>
class Tree;

template<class T>
ostream &operator << (ostream&, const Tree<T>&);

template <class T>
class Tree
{
	public:
		Tree();
		Tree(const Tree&);
		Tree(T**, const int);
		~Tree();

		int get_size() const;
		Node<T> *get_head() const;
		Node<T> *get_tail() const;

		void create_first(T*);
		void create_last(T*);

		void delete_list();
		void delete_first();
		void delete_last();

		void print();
		friend ostream &operator << <>(ostream&, const Tree<T>&);

		int check_size();
		void search_circle();
		Node<T> *check_last_element();

		void insert_before(T*, const int);
		void insert_after(T*, const int);

		void swap(Node<T>*, Node<T>*);
		void reverse();

		int get_index(Node<T>*) const;
		Node<T> *get_pre_tail() const;
		Node<T> *get_element(const int) const;

		Node<T> *get_pre_element(const int) const;
		Node<T> *get_pre_element(Node<T>*) const;

		void delete_element(const int);
		void add_list(const Tree<T>*);
		T **list_to_array();

	private:
		int size;
		Node<T> *head;
		Node<T> *tail;
};
