#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

void order_arr(int *array, int size)
{
	for(int i = 0; i < size; i++)
		array[i] = i;
}

void shufle1(int *array, int size)
{
	int point;	//позиция в массиве чисел
	bool *mirror_arr = new bool[size];	//массив для проверки уникальности
	for(int j = 0; j < size; j++)		//заполняем нулями
		mirror_arr[j] = 0;
	
	for(int i = 0; i < size; i++)
	{
		point = rand() % size;		//рандомим позицию
		if(!mirror_arr[point])		//если ещё не проходили это место
		{
			array[point] = i;		//приравниванием
			mirror_arr[point] = 1;	//делаем пометку, что прошли
		}
		else	//в случае холостого прохода отнимаем 1
			i--;
	}
	delete []mirror_arr;
}

void shufle2(int *array, int size)
{
	for(int i = 0; i < size; i++)
		array[i] = i;
	
	for(int i = 0; i < size; i++)
		swap(array[i], array[rand() % (size - 1)]);
}

void shufle3(int *array, int size)
{
	order_arr(array, size);
	for(int i = 0; i < size; i++)
		swap(array[0], array[rand() % (size - 1)]);
}

void print(int *array, int size)
{
	for(int i = 0; i < size - 1; i++)
		cout << array[i] << ", ";
	cout << array[size - 1] << endl;
}

void swap(int *v1, int *v2)
{
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

int check_random(int *array, int size)
{
	int result = 0;
	for(int i = 0; i < size; i++)
		if(array[i] == i)
			result++;
	
	return result;
}

int main()
{
	srand(time(NULL));
	int size;
	cout << "Enter size: ";
	cin >> size;
	/*
	int *array1 = new int[size];
	int *array2 = new int[size];
	int *array3 = new int[size];
	shufle1(array1, size);
	shufle2(array2, size);
	shufle3(array3, size);
	
	cout << check_random(array1, size) << endl;
	cout << check_random(array2, size) << endl;
	cout << check_random(array3, size) << endl;
	
	print(array1, size);
	print(array2, size);
	print(array3, size);
	
	delete []array1;
	delete []array2;
	delete []array3;
	*/
	int *arr = new int[size];
	shufle1(arr, size);
	
	FILE *file = fopen("data.txt", "w");
	if(file)
	{
		for(int i = 0; i < size; i++)
			fprintf(file, "%i\n", arr[i]);
	}
	
	fflush(file);
	fclose(file);
	
	
	system("pause");
	return 0;
}
