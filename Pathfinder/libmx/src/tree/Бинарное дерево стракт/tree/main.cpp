#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

//эта функция нужна для заполнения деревьев объектами
bool parse_trees(Tree *tree1, Tree *tree2)
{
	if(tree1 && tree2)	//сокращенная запись if(tree1 != NULL && tree2 != NULL)
	{
		FILE *file1 = fopen("data1.txt", "r");	//открыли файл для чтения "r"
		FILE *file2 = fopen("data2.txt", "r");

		if(file1 && file2)	//проверили указатели на файлы. если файл не открылся, то указатель NULL
		{
			int tmp;
			//в теле цикла происходит считывание из файла в переменную одного числа
			//fscanf() имеет ряд возвращаемых значений
			//Конкретно EOF (это константа и её значение стандартизировано) означает конец файла
			//так вот пока у нас не конец файла, то будет продолжаться считывание

			while(fscanf(file1, "%i", &tmp) != EOF)
				insert_item(tree1, tmp);
			while(fscanf(file2, "%i", &tmp) != EOF)
				insert_item(tree2, tmp);

			fclose(file1);	//файлы больше не нужны
			fclose(file2);	//закрываем
			return true;	//возвращаем положительный результат
		}
	}
	return false;	//вернем false если файлы не открылись
}

int main()
{
	system("chcp 1251 & cls");	//русский язык в консоли windows

	Tree *t1 = create_tree(), *t2 = create_tree();	//декларируем указатели и создаем дерево на каждый
	if(parse_trees(t1, t2))	//в теле if() прописана функция, которая возвращает true/false как результат работы
	{
		print(t1, 2);	//печатаем дерево симметричным обходом
		print(t2, 2);	//и второе

		//опять же в теле if() функция, которая возвращает результат работы
		if(compare(t1->root, t2->root))		//if(compare(...) != NULL)
			cout << "Деревья одинаковые" << endl;
		else
			cout << "Деревья не одинаковые" << endl;

		cout << "Высота первого дерева: " << get_height(t1->root) << endl;
		cout << "Высота второго дерева: " << get_height(t2->root) << endl;

		cout << "Количество листьев первого дерева: " << leaf_amount(t1->root) << endl;
		cout << "Количество листьев второго дерева: " << leaf_amount(t2->root) << endl;
	}

	delete_tree(t1);	//удаляем деревья
	delete_tree(t2);

	system("pause");	//чтобы не закрывалась консоль в конце работы
	return 0;
}
