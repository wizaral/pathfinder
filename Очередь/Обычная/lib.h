#ifndef lib_h
#define lib_h

using namespace std;

class Queue
{
    public:
    	Queue()
		{
			cout << "Не тот конструктор)" << endl;
		}
    	
    	Queue(int aCapacity)
		{
			size = 0;
        	pointer1 = 0;
        	pointer2 = 0;
			capacity = aCapacity;
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
        int size;
        int pointer1;
        int pointer2;
        int capacity;
        int *array;
};                                       

int getInt();

#endif
