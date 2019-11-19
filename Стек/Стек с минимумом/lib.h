#ifndef lib_h
#define lib_h

using namespace std;

class fixedStackReserv
{
    public:
    	fixedStackReserv()
		{
			cout << "Не тот конструктор)" << endl;
		}
    	
    	fixedStackReserv(int aCapacity)
		{
			size = 0;
			capacity = aCapacity;
			array = new int[capacity];
		}
		
		~fixedStackReserv()
		{
			delete []array;
		}
		
		void push(int anElement);
		void pop();
		int peek();
		
    private:
        int capacity;
        int size;
        int *array;
};

class fixedStack
{
    public:
    	fixedStack()
		{
			cout << "Не тот конструктор)" << endl;
		}
    	
    	fixedStack(int aCapacity)
		{
			min = INT_MAX;
			size = 0;
			capacity = aCapacity;
			array = new int[capacity];
		}
		
		~fixedStack()
		{
			delete []array;
		}
		
		void push(fixedStackReserv *Res);
		void pop(fixedStackReserv *Res);
		void peek();
		void print();
		void getMin(fixedStackReserv *Res);
		
    private:
        int capacity;
        int size;
        int *array;
        int min;
};                                       

int getInt();

#endif
