#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "tree.h"

int main()
{
	system("chcp 1251 & cls");
	tree *the_tree = create_tree();
	
	if(the_tree)
	{
		add_elements(the_tree);
		print_tree(the_tree);
		my_task(the_tree);
	}
	
	destroy_tree(the_tree);
	
	system("pause");
	return 0;
}
