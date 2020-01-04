#ifndef tree_h
#define tree_h

struct Node {
    int value;    
    Node *left;   
    Node *right;  
    Node *parent; 
};

struct Tree {
    int count; 
    Node *root;
};

Node *create_node(Node *, int);
void delete_node(Node *);      

Tree *create_tree();     
void delete_tree(Tree *);

void insert_item(Tree *, int);
void delete_item(Tree *, Node *);
void delete_item(Tree *, int);

Node *get_min(Node *);    
Node *get_max(Node *);    
Node *search(Node *, int);

int get_height(Node *);
int leaf_amount(Node *);
bool compare(Node *, Node *);

void preorder_print(Node *);
void inorder_print(Node *);
void postorder_print(Node *);
void print(Tree *, int);

#endif
