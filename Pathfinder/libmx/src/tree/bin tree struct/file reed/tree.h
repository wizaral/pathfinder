#ifndef tree_h
#define tree_h

typedef struct element {
    int value, level;
    struct element *left;
    struct element *right;
    struct element *parent;
} node;

typedef struct a_tree {
    int count;
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

node *search_node(node *a_node, int a_value);
void delete_element_by_value(tree *a_tree, int a_value);

void print_tree(tree *a_tree);

void preorder_print(node *a_node);
void inorder_print(node *a_node);
void postorder_print(node *a_node);
void levelorder_print(tree *a_tree);

void preorder_print_file(node *a_node, FILE *a_file);
void inorder_print_file(node *a_node, FILE *a_file);
void postorder_print_file(node *a_node, FILE *a_file);
void levelorder_print_file(tree *a_tree, FILE *a_file);

void add_elements(tree *a_tree);
void my_task(tree *a_tree);
long long int levelorder(node *a_node);

#endif
