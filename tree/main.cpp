#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

bool parse_trees(Tree *tree1, Tree *tree2)
{
	if(tree1 && tree2)
	{
		FILE *file1 = fopen("data1.txt", "r");
		FILE *file2 = fopen("data2.txt", "r");

		if(file1 && file2)
		{
			int tmp;

			while(fscanf(file1, "%i", &tmp) != EOF)
				insert_item(tree1, tmp);
			while(fscanf(file2, "%i", &tmp) != EOF)
				insert_item(tree2, tmp);

			fclose(file1);
			fclose(file2);
			return true;
		}
	}
	return false;
}

int main()
{
	system("chcp 1251 & cls");

	Tree *t1 = create_tree(), *t2 = create_tree();
	if(parse_trees(t1, t2))
	{
		print(t1, 2);
		print(t2, 2);

		if(compare(t1->root, t2->root))
			cout << "Деревья одинаковые" << endl;
		else
			cout << "Деревья не одинаковые" << endl;

		cout << "Высота первого дерева: " << get_height(t1->root) << endl;
		cout << "Высота второго дерева: " << get_height(t2->root) << endl;

		cout << "Количество листьев первого дерева: " << leaf_amount(t1->root) << endl;
		cout << "Количество листьев второго дерева: " << leaf_amount(t2->root) << endl;
	}

	delete_tree(t1);
	delete_tree(t2);

	system("pause");
	return 0;
}
