#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
//using namespace std;

template <class T>
class Node {
public:
    Node(T *, Node *, bool = true);
    Node(const Node &);
    ~Node();

    T *get_item() const;
    Node *get_next() const;
    void set_item(T *);
    void set_next(Node *);

private:
    T *item;
    Node *next;
};

template <class T> class LinkedList;
template <class T> std::ostream &operator << (std::ostream &, const LinkedList<T> &);

template <class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList &);
    LinkedList(T **, const int);
    ~LinkedList();

    int get_size() const;
    Node<T> *get_head() const;
    Node<T> *get_tail() const;

    void create_first(T *);
    void create_last(T *);

    void delete_list();
    void delete_first();
    void delete_last();

    void print();
    friend std::ostream &operator << <>(std::ostream &, const LinkedList<T> &);

    int check_size();
    void search_circle();
    Node<T> *check_last_element();

    void insert_before(T *, const int);
    void insert_after(T *, const int);

    void swap(Node<T> *, Node<T> *);
    void reverse();

    int get_index(Node<T> *) const;
    Node<T> *get_pre_tail() const;
    Node<T> *get_element(const int) const;

    Node<T> *get_pre_element(const int) const;
    Node<T> *get_pre_element(Node<T> *) const;

    void delete_element(const int);
    void add_list(const LinkedList<T> *);
    T **list_to_array();

private:
    int size;
    Node<T> *head;
    Node<T> *tail;
};

//===============================================================

template <class T>
Node<T>::Node(T *item, Node *next, bool flag) : next(next) {
    this->item = flag ? item : new T(*item);
}

template <class T>
Node<T>::Node(const Node &u) {
    this->item = new T(u.item);
    this->next = u.next;
}

template <class T>
Node<T>::~Node() {
    delete this->item;
}

template <class T>
T *Node<T>::get_item() const {
    return this->item;
}

template <class T>
Node<T> *Node<T>::get_next() const {
    return this->next;
}

template <class T>
void Node<T>::set_item(T *item) {
    this->item = item;
}

template <class T>
void Node<T>::set_next(Node<T> *next) {
    this->next = next;
}

//===============================================================

template <class T>
LinkedList<T>::LinkedList() : size(0), head(nullptr), tail(nullptr) {
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &u) : size(0), head(nullptr), tail(nullptr) {
    if(u.head && u.tail) {
        Node<T> *to_add = u.head, *node = nullptr;

        while (node == nullptr)
            node = new Node<T>(to_add->get_item(), this->head, false);

        this->head = node;
        this->tail = node;
        this->size++;
        to_add = to_add->get_next();

        while (to_add) {
            node = nullptr;
            while (node == nullptr)
                node = new Node<T>(to_add->get_item(), nullptr, false);

            this->tail->set_next(node);
            this->tail = node;
            this->size++;
            to_add = to_add->get_next();
        }
    }
}

template <class T>
LinkedList<T>::LinkedList(T **array, const int size) : size(0), head(nullptr), tail(nullptr) {
    if (array && size > 0)
        for (int i = 0; i < size; i++)
            this->create_last(array[i]);
}

template <class T>
LinkedList<T>::~LinkedList() {
    this->delete_list();
}

template <class T>
int LinkedList<T>::get_size() const {
    return this->size;
}

template <class T>
Node<T> *LinkedList<T>::get_head() const {
    return this->head;
}

template <class T>
Node<T> *LinkedList<T>::get_tail() const {
    return this->tail;
}

//================================================================

template <class T>
void LinkedList<T>::create_first(T *item) {
    Node<T> *node = nullptr;
    while (node == nullptr)
        node = new Node<T>(item, this->head);

    this->head = node;
    if (this->tail == nullptr)
        this->tail = node;
    this->size++;
}

template <class T>
void LinkedList<T>::create_last(T *item) {
    if (this->head && this->tail) {
        Node<T> *node = nullptr;
        while (node == nullptr)
            node = new Node<T>(item, nullptr);

        this->tail->set_next(node);
        this->tail = node;
        this->size++;
    }
    else
        this->create_first(item);
}

template <class T>
void LinkedList<T>::delete_list() {
    if (this->head && this->tail) {
        Node<T> *last = nullptr;
        while (this->head->get_next()) {
            last = this->head;
            this->head = this->head->get_next();
            delete last;
            this->size--;
        }
        delete head;

        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
    }
}

template <class T>
void LinkedList<T>::delete_first() {
    if (this->head && this->tail) {
        Node<T> *last = this->head;
        this->head = this->head->get_next();
        this->size--;
        delete last;
    }
}

template <class T>
void LinkedList<T>::delete_last() {
    if (this->head && this->tail) {
        if (this->head == this->tail) {
            delete this->head;
            this->size--;
        }

        Node<T> *pre_last = this->get_pre_tail();
        delete this->tail;

        pre_last->set_next(nullptr);
        this->tail = pre_last;
        this->size--;
    }
}

//================================================================

template <class T>
void LinkedList<T>::print() {
    if (this->head && this->tail) {
        for (Node<T> *node = this->head; node; node = node->get_next())
            std::cout << *(node->get_item());
        std::cout << std::endl;
    }
    else
        std::cout << "Empty list." << std::endl;
}

template <class T>
std::ostream &operator << (std::ostream &stream, const LinkedList<T> &obj) {
    if (obj.head && obj.tail)
        for (Node<T> *node = obj.head; node; node = node->get_next())
            stream << *(node->get_item());
    else
        stream << "Empty list." << std::endl;

    return stream;
}

template <class T>
int LinkedList<T>::check_size() {
    int size = 0;

    if (this->head && this->tail) {
        Node<T> *node = this->head;
        while (node) {
            node = node->get_next();
            size++;
        }
    }
    return size;
}

template <class T>
void LinkedList<T>::search_circle() {
    if (this->head && this->tail) {
        if (this->head == this->tail) {
            this->head->next = this->tail->next = nullptr;
            return;
        }

        Node<T> *slow = this->head;
        Node<T> *fast = this->head->get_next();

        while (slow && fast && slow != fast) {
            slow = slow->get_next();
            fast = fast->get_next();
            fast = fast ? fast->get_next() : fast;
        }

        if (slow && fast) {
            Node<T> *finder = this->head;
            fast = fast->get_next();

            while (finder != fast) {
                finder = finder->get_next();
                fast = fast->get_next();
                slow = slow->get_next();
            }

            slow->set_next(nullptr);
        }
    }
}

//================================================================

template <class T>
void LinkedList<T>::insert_before(T *item, int node) {
    if (node > -1 && node < this->size && this->head && this->tail) {
        if (node == 0)
            this->create_first(item);
        else {
            int i = 0;
            Node<T> *tmp = this->head;

            while (++i < node - 1 && tmp->get_next())
                tmp = tmp->get_next();

            Node<T> *tmp2 = new Node<T>(item, tmp->get_next());
            tmp->set_next(tmp2);
        }
    }
}

template <class T>
void LinkedList<T>::insert_after(T *item, int number) {
    if (number > -1 && number < this->size && this->head && this->tail) {
        if (number == this->size - 1)
            this->create_last(item);
        else {
            int i = 0;
            Node<T> *node = this->head;

            while (i++ < number - 1 && node->get_next())
                node = node->get_next();

            Node<T> *node2 = new Node<T>(item, node->get_next());
            node->set_next(node2);
        }
    }
}

template <class T>
void LinkedList<T>::swap(Node<T> *node1, Node<T> *node2) {
    if (this->head && this->tail) {
        Node<T> *pre1 = nullptr, *pre2 = nullptr, *node = nullptr;

        if (this->head == node1) {
            pre2 = this->get_pre_element(node2);
            pre2->set_next(node1);

            node = node1->get_next();
            node1->set_next(node2->get_next());
            node2->set_next(node);

            this->head = node2;
        }
        else if (this->head == node2) {
            pre1 = this->get_pre_element(node1);
            pre1->set_next(node1);

            node = node1->get_next();
            node1->set_next(node2->get_next());
            node2->set_next(node);

            this->head = node1;
        }
        else {
            pre1 = this->get_pre_element(node1);
            pre2 = this->get_pre_element(node2);

            pre1->set_next(node2);
            pre2->set_next(node1);

            node = node1->get_next();
            node1->set_next(node2->get_next());
            node2->set_next(node);
        }

        if (this->tail == node1)
            this->tail = node2;
        else if (this->tail == node2)
            this->tail = node1;
    }
}

template <class T>
void LinkedList<T>::reverse() {
    Node<T> *prev = nullptr, *next = nullptr, *node = this->head;

    while(node) {
        next = node->get_next();
        node->set_next(prev);
        prev = node;
        node = next;
    }

    node = this->head;
    this->head = this->tail;
    this->tail = node;
}

//================================================================

template <class T>
int LinkedList<T>::get_index(Node<T> *node) const {
    if (this->head && this->tail) {
        if (node == this->head)
            return 0;
        if (node == this->tail)
            return this->size - 1;

        int i = 0;
        Node<T> *tmp = this->head;

        while (tmp != node && tmp) {
            tmp = tmp->get_next();
            i++;
        }
        return i;
    }
    return -1;
}

template <class T>
Node<T> *LinkedList<T>::get_pre_tail() const {
    if (this->head && this->tail) {
        if (this->head == this->tail)
            return this->head;

        Node<T> *node = this->head;
        while (node->get_next()->get_next())
            node = node->get_next();

        return node;
    }
    return nullptr;
}

template <class T>
Node<T> *LinkedList<T>::get_element(int number) const {
    if (number > -1 && number < this->size && this->head && this->tail) {
        if (number == 0)
            return this->head;
        if (number == this->size - 1)
            return this->tail;

        int i = 0;
        Node<T> *node = this->head;

        while (i++ < number && node)
            node = node->get_next();
        return node;
    }
    return nullptr;
}

template <class T>
Node<T> *LinkedList<T>::check_last_element() {
    if (this->head && this->tail) {
        Node<T> *node = this->head;

        while (node->get_next())
            node = node->get_next();
        return node;
    }
    return nullptr;
}

template <class T>
Node<T> *LinkedList<T>::get_pre_element(int number) const {
    if (number > 0 && number < this->size && this->head && this->tail) {
        int i = 0;
        Node<T> *node = this->head;

        while (i++ < (number - 1) && node->get_next())
            node = node->get_next();
        return node;
    }
    return nullptr;
}

template <class T>
Node<T> *LinkedList<T>::get_pre_element(Node<T> *node) const {
    if (this->head && this->tail && node) {
        Node<T> *tmp = this->head;

        while (tmp->get_next() != node && tmp)
            tmp = tmp->get_next();
        return tmp;
    }
    return nullptr;
}

//================================================================

template <class T>
void LinkedList<T>::delete_element(const int number) {
    if (this->head && this->tail) {
        if (number == 0)
            this->delete_first();
        else if (number == this->size - 1)
            this->delete_last();
        else {
            Node<T> *pre_el = get_pre_element(number);
            Node<T> *to_del = pre_el->get_next();

            pre_el->setNext(to_del->get_next());
            this->set_size(this->size - 1);
            delete to_del;
        }
    }
}

template <class T>
void LinkedList<T>::add_list(const LinkedList<T> *list) {
    if (list->get_head() && list->get_tail()) {
        Node<T> *node = list->get_head(), *to_add = nullptr;

        if (this->head == nullptr && this->tail == nullptr) {
            while (to_add == nullptr)
                to_add = new Node<T>(node->get_item(), this->head, false);

            this->head = to_add;
            this->tail = to_add;
            this->size++;
            node = node->get_next();
        }

        while (node) {
            to_add = nullptr;

            while (to_add == nullptr)
                to_add = new Node<T>(node->get_item(), nullptr, false);

            this->tail->set_next(to_add);
            this->tail = to_add;
            this->size++;

            node = node->get_next();
            to_add = nullptr;
        }
    }
}

template <class T>
T **LinkedList<T>::list_to_array() {
    T **array = nullptr;

    if(this->head && this->tail) {
        array = new T*[this->size];
        Node<T> *node = this->head;

        for(int i = 0; node; i++, node = node->get_next())
            array[i] = node->get_item();
    }
    return array;
}

#endif
