#include "linked_list.h"

class Example
{
    public:
        Example(int number) : number(number) {
        }
        ~Example() {
        }

        friend std::ostream &operator << (std::ostream &stream, const Example &obj) {
            stream << obj.number << std::endl;
            return stream;
        }

    private:
        int number;
};

int main() {
    int size = 21;
    Example **arr = new Example*[size];

    for(int i = 0; i < size; i++)
        arr[i] = new Example(i);

    std::cout << "list1" << std::endl;
    LinkedList<Example> *list1 = new LinkedList<Example>(arr, size);
    std::cout << *list1 << std::endl;

    list1->get_tail()->set_next(list1->get_element(10));
    //cout << *list1 << endl;
    list1->search_circle();
    //cout << *list1 << endl;

    list1->swap(list1->get_element(1), list1->get_element(19));
    list1->swap(list1->get_element(0), list1->get_element(20));
    std::cout << *list1 << std::endl;

    LinkedList<Example> *list2 = new LinkedList<Example>(*list1);
    delete list1;

    std::cout << "list2" << std::endl;
    std::cout << *list2 << std::endl;

    std::cout << "head: " << *list2->get_head()->get_item();
    std::cout << "tail: " << *list2->get_tail()->get_item();

    std::cout << "check tail: " << *list2->check_last_element()->get_item();
    std::cout << "list[5]: " << *list2->get_element(5)->get_item();

    std::cout << "index[list[5]]: " << list2->get_index(list2->get_element(5)) << std::endl;
    std::cout << "size of list: " << list2->get_size() << std::endl;

    std::cout << std::endl << *list2 << std::endl;

    LinkedList<Example> *list3 = new LinkedList<Example>(*list2);

    list3->reverse();
    std::cout << *list3 << std::endl;

    list3->add_list(list2);

    Example *ex5 = new Example(55);
    Example *ex9 = new Example(99);

    list3->delete_first();
    list3->create_first(ex5);
    list3->delete_last();
    list3->create_last(ex9);
    std::cout << *list3 << std::endl;

    std::cout << *list3->get_head()->get_item();
    std::cout << *list3->get_tail()->get_item();

    delete list2;
    delete list3;

    return 0;
}