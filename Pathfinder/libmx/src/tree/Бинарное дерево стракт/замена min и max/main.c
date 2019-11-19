#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	system("chcp 1251 & cls");	//русский язык
	char choice;

	Tree *tree = create_tree();	//создали дерево
	add_elements(tree);			//заполнили элементами

	if(tree->root)				//если успешно заполнили
		printf("Данные успешно внесены из файла.\n");

	do
	{
		printf("\nВведите номер операции.\n1 - Печать дерева.\n");
		printf("2 - Добавление элемента.\n3 - Удаление элемента.\n");
		printf("4 - Поиск элемента.\n5 - Замена min и max.\n");
		printf("6 - Очистить дерево.\n7 - Выход из программы.\nВведите: ");
		
		fflush(stdin);			//очистили поток ввода консоли
		scanf("%c", &choice);	//запросили выбор у юзверя

		switch(choice)			//в зависимости от выбора выполняется нужный кейс
		{
			case '1':
				print_tree(tree);	//печатаем
				break;		//брэйк нужен в каждом кейсе, а то будет выполнять следующие кейсы
			case '2':
				add_item(tree);		//добавляем
				break;
			case '3':
				delete_item(tree);	//удаляем
				break;
			case '4':
				search_item(tree);	//ищем
				break;
			case '5':
				printf("\nПеред заменой:\n");
				print_min_max(tree);	//печатаем min max
				swap_min_max(tree);		//меняем местами

				printf("\nПосле замены:\n");
				print_min_max(tree);
				break;
			case '6':
				delete_tree(tree);		//удаляем всё дерево
				printf("Дерево успешно удалено.\n\n");
				break;
			default:							//если юзверь ввёл что-то не то
				printf("Неправильный ввод.\n");
		}
	}
	while(choice != '6');

	system("pause");
	return 0;
}
