#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define true 1

typedef struct element {
    int value, level;
    struct element *left;
    struct element *right;
    struct element *parent;
} node;

typedef struct a_tree {
    int count;
    int level;
    node *root;
} tree;

typedef struct a_queue {
    node *save_node;
    struct a_queue *next;
} queue;

void push(queue **head, node *a_node);
node *pop(queue **head);

tree *create_tree();
void destroy_tree(tree *a_tree);

node *create_node(node *a_parent, int a_value);
void destroy_node(node *a_node);

node *min_value(node *a_node);
node *max_value(node *a_node);

void insert_element(tree *a_tree, int a_value);
void delete_element(tree *a_tree, node *a_node);

void print_tree(tree *a_tree);
void preorder_print(node *a_node);
void inorder_print(node *a_node);
void postorder_print(node *a_node);
void levelorder_print(tree *a_tree);

void add_elements(tree *a_tree);
void PUNKT_4(tree *a_tree);
void levelorder(int level, node *a_node, int *min);

int main() {
    system("chcp 1251 & cls");
    tree *the_tree = create_tree();

    if (the_tree) {
        add_elements(the_tree);
        print_tree(the_tree);
        PUNKT_4(the_tree);
    }

    destroy_tree(the_tree);

    system("pause");
    return 0;
}

void push(queue **head, node *a_node) {
    if (a_node) {
        queue *a_part = (queue *)malloc(sizeof(queue));
        if (a_part) {
            a_part->save_node = a_node;
            a_part->next = NULL;

            if (*head) {
                queue *tmp = (*head);
                while (tmp->next)
                    tmp = tmp->next;

                tmp->next = a_part;
            } else
                (*head) = a_part;
        } else {
            printf("������ �������� �������!\n");
            return;
        }
    }
}

node *pop(queue **head) {
    if (*head) {
        queue *tmp = (*head);
        (*head) = (*head)->next;

        return tmp->save_node;
    } else
        return NULL;
}

tree *create_tree() {
    tree *a_tree = (tree *)malloc(sizeof(tree));
    if (!a_tree) {
        printf("������ �������� �����!\n");
        exit(1);
    }

    a_tree->count = 0;
    a_tree->level = 0;
    a_tree->root = NULL;
    return a_tree;
}

node *create_node(node *a_parent, int a_value) {
    node *a_node = (node *)malloc(sizeof(node));
    if (a_node) {
        a_node->parent = a_parent;
        a_node->left = NULL;
        a_node->right = NULL;
        a_node->value = a_value;

        if (!a_parent)
            a_node->level = 0;
        else
            a_node->level = a_parent->level + 1;

        return a_node;
    } else {
        printf("������ ��� �������� ��������!\n");
        return NULL;
    }
}

void destroy_node(node *a_node) {
    if (a_node) {
        destroy_node(a_node->left);
        destroy_node(a_node->right);
        free(a_node);
    }
}

void destroy_tree(tree *a_tree) {
    if (a_tree) {
        destroy_node(a_tree->root);
        free(a_tree);
    }
}

node *min_value(node *a_node) {
    if (a_node->left) {
        while (a_node->left)
            a_node = a_node->left;
        return a_node;
    }
    return NULL;
}

node *max_value(node *a_node) {
    if (a_node->right) {
        while (a_node->right)
            a_node = a_node->right;
        return a_node;
    }
    return NULL;
}

void insert_element(tree *a_tree, int a_value) {
    if (a_tree) {
        if (!a_tree->root) {
            node *a_node = create_node(a_tree->root, a_value);
            if (a_node) {
                a_tree->root = a_node;
                a_tree->count++;

                if (a_tree->level < a_node->level)
                    a_tree->level = a_node->level;
            } else {
                printf("������ ��� ���������� ��������!\n");
                return;
            }
        } else {
            node *a_fast = a_tree->root;
            node *a_low = NULL;

            while (true) {
                a_low = a_fast;

                if (a_value == a_fast->value) {
                    printf("����� ������� ��� ��� ��������.\n");
                    break;
                } else if (a_value < a_fast->value) {
                    a_fast = a_fast->left;
                    if (!a_fast) {
                        node *a_node = create_node(a_low, a_value);
                        a_low->left = a_node;
                        a_tree->count++;

                        if (a_tree->level < a_node->level)
                            a_tree->level = a_node->level;
                        break;
                    }
                } else {
                    a_fast = a_fast->right;
                    if (!a_fast) {
                        node *a_node = create_node(a_low, a_value);
                        a_low->right = a_node;
                        a_tree->count++;

                        if (a_tree->level < a_node->level)
                            a_tree->level = a_node->level;
                        break;
                    }
                }
            }
        }
    } else
        printf("������!\n");
}

void delete_element(tree *a_tree, node *a_node) {
    if (a_tree && a_node) {
        if (a_node->left && a_node->right) {
            node *a_max = max_value(a_node->left);
            a_node->value = a_max->value;
            delete_element(a_tree, a_max);
            return;
        } else if (a_node->parent) {
            if (a_node->left) {
                if (a_node == a_node->parent->left)
                    a_node->parent->left = a_node->left;
                else
                    a_node->parent->right = a_node->left;
            } else if (a_node->right) {
                if (a_node == a_node->parent->right)
                    a_node->parent->right = a_node->right;
                else
                    a_node->parent->left = a_node->right;
            } else {
                if (a_node == a_node->parent->left)
                    a_node->parent->left = NULL;
                else
                    a_node->parent->right = NULL;
            }
        } else if (a_tree->root == a_node) {
            if (a_node->left) {
                node *a_max = max_value(a_node->left);
                a_tree->root->value = a_max->value;
                delete_element(a_tree, a_max);
                return;
            } else if (a_node->right) {
                node *a_max = max_value(a_node->right);
                a_tree->root->value = a_max->value;
                delete_element(a_tree, a_max);
                return;
            } else {
                a_tree->root = NULL;
            }
        }
        free(a_node);
        a_tree->count--;
    }
}

void preorder_print(node *a_node) {
    if (a_node) {
        printf("%i ", a_node->value);
        preorder_print(a_node->left);
        preorder_print(a_node->right);
    }
}

void inorder_print(node *a_node) {
    if (a_node) {
        inorder_print(a_node->left);
        printf("%i ", a_node->value);
        inorder_print(a_node->right);
    }
}

void postorder_print(node *a_node) {
    if (a_node) {
        postorder_print(a_node->left);
        postorder_print(a_node->right);
        printf("%i ", a_node->value);
    }
}

void levelorder_print(tree *a_tree) {
    if (a_tree) {
        int count = a_tree->count;
        queue *head = NULL;
        node *tmp = NULL;
        push(&head, a_tree->root);

        while (count--) {
            tmp = pop(&head);
            push(&head, tmp->left);
            push(&head, tmp->right);
            printf("%i ", tmp->value);
        }
    }
}

void print_tree(tree *a_tree) {
    if (a_tree) {
        int print_type;

        do {
            printf("������� ��� ������ ������.\n1 - ������.\n2 - ");
            printf("������������.\n3 - ��������.\n4 - �� �������.\n�������: ");
            scanf("%i", &print_type);
        } while (print_type < 1 || print_type > 4);

        printf("\n���������� ���������: %i\n", a_tree->count);
        printf("�������� �������:  %i\n", a_tree->root->value);

        if (a_tree->root) {
            printf("�������� ������: \n");

            switch (print_type) {
            case 1:
                preorder_print(a_tree->root);
                printf("\n");
                break;
            case 2:
                inorder_print(a_tree->root);
                printf("\n");
                break;
            case 3:
                postorder_print(a_tree->root);
                printf("\n");
                break;
            case 4:
                levelorder_print(a_tree);
                printf("\n");
                break;
            default:
                printf("������������ ���.\n");
            }
        }
    }
}

void add_elements(tree *a_tree) {
    FILE *file = fopen("data.txt", "r");

    if (a_tree && file) {
        int tmp;
        while (fscanf(file, "%i", &tmp) != EOF)
            insert_element(a_tree, tmp);

        fclose(file);
    }
}

void levelorder(int level, node *a_node, int *min) {
    if (a_node) {
        if (a_node->level == level - 1) {
            if (*min > a_node->value)
                *min = a_node->value;
        } else if (a_node->level < level - 1) {
            levelorder(level, a_node->left, min);
            levelorder(level, a_node->right, min);
        }
    }
}

void PUNKT_4(tree *a_tree) {
    if (a_tree) {
        int result = INT_MAX;
        printf("\n������������ ������� ������: %i\n", a_tree->level);

        levelorder(a_tree->level, a_tree->root, &result);
        printf("���������� ������� �� ������������� ������: %i\n\n", result);
    }
}
