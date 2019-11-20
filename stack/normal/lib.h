#ifndef lib_h
#define lib_h

using namespace std;

class fixedStack
{
    public:
    	fixedStack()
		{
			cout << "Не тот конструктор)" << endl;
		}
    	
    	fixedStack(int aCapacity)
		{
			size = 0;
			capacity = aCapacity;
			array = new int[capacity];
		}
		
		~fixedStack()
		{
			delete []array;
		}
		
		void push();
		void pop();
		void peek();
		void print();
		
    private:
        int capacity;
        int size;
        int *array;
};                                       

int getInt();

#endif
