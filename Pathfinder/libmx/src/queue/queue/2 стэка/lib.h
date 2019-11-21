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
			flag = 0;
			size = 0;
			capacity = aCapacity;
			array1 = new int[capacity];
			array2 = new int[capacity];
		}
		
		~Queue()
		{
			delete []array1;
			delete []array2;
		}
		
		int getSize();
		void enQueue();
		void deQueue();
		void print();
		
    private:
    	bool flag;
        int size;
        int capacity;
        int *array1;
        int *array2;
};                                       

int getInt();

#endif
