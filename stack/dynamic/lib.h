#ifndef lib_h
#define lib_h

using namespace std;

class infStack {
public:
    infStack() {
        size = 0;
        capacity = 10;
        array = new int[capacity];
    }

    ~infStack() {
        delete[] array;
    }

    int getSize();
    void push();
    void pop();
    void peek();
    void print();

private:
    int capacity;
    int size;
    int* array;
};

int getInt();

#endif
