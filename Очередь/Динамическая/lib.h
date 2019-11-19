#ifndef lib_h
#define lib_h

using namespace std;

class Queue
{
    public:
    	Queue()
		{
			size = 0;
        	pointer1 = 0;
        	pointer2 = 0;
			capacity = 10;
			array = new int[capacity];
		}
		
		~Queue()
		{
			delete []array;
		}
		
		int getSize();
		void enQueue();
		void deQueue();
		void print();
		
    private:
        int capacity;
        int size;
        int pointer1;
        int pointer2;
        int *array;
};                                       

int getInt();

#endif
