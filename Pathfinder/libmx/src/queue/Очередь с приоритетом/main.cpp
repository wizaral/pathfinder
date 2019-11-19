#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

template <typename T>
class node {
public:
    node(T info, int priority) {
        this->info = info;
        this->priority = priority;
        link = nullptr;
    }
    node(node& u) {
        link = u.link;
        priority = u.priority;
        info = u.info;
    }
    ~node() {
    }

    int priority;
    T info;
    node<T>* link;
};

template <typename T>
class Priority_Queue {
public:
    Priority_Queue() {
        front = NULL;
        size = 0;
    }
    int getSize() {
        return size;
    }

    void push(T item, int priority) {
        node<T>* tmp = new node<T>(item, priority);
        if (!front || priority < front->priority) {
            tmp->link = front;
            front = tmp;
            size++;
        } else {
            node<T>* tmp2 = front;
            while (tmp2->link != nullptr && tmp2->link->priority <= priority)
                tmp2 = tmp2->link;

            tmp2->link = tmp;
            size++;
        }
    }

    void pop() {
        if (front) {
            node<T>* tmp = front;
            cout << "Deleted item is: " << tmp->info << endl << endl;
            front = front->link;
            delete tmp;
            size--;
        } else
            cout << "Queue Underflow" << endl << endl;
    }

    void print() {
        if (front) {
            node<T>* ptr = front;
            cout << "Queue is: " << endl << endl;
            cout << "Priority\t\tItem" << endl;
            while (ptr != NULL) {
                cout << ptr->priority << "\t\t\t" << ptr->info << endl;
                ptr = ptr->link;
            }
            cout << endl;
        } else
            cout << "Queue is empty" << endl << endl;
    }

private:
    node<T>* front;
    int size;
};

int main() {
    int choice, priority, item;
    Priority_Queue<int> pq;
    do {
        cout << "1.Insert" << endl
             << "2.Delete" << endl
             << "3.Display" << endl
             << "4.Size" << endl
             << "5.Quit" << endl << endl
             << "Enter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Input the item value to be added in the queue: ";
                cin >> item;
                cout << "Enter its priority : ";
                cin >> priority;
                pq.push(item, priority);
                break;
            case 2:
                pq.pop();
                break;
            case 3:
                pq.print();
                break;
            case 4:
                cout << "Size: " << pq.getSize() << endl << endl;
                break;
            case 5:
                break;
            default:
                cout << "Wrong choice" << endl;
        }
    } while (choice != 5);

    system("pause");
    return 0;
}
