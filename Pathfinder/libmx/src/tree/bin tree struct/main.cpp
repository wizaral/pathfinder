#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

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

//=========================================================

Tree *createTree() {
    Tree *aTree = new Tree;
    if (!aTree) {
        cout << "������ �������� �����!" << endl;
        exit(1);
    }

    aTree->count = 0;
    aTree->root = NULL;
    return aTree;
}

Node *createNode(Node *aParent, int aValue) {
    Node *aNode = new Node;
    if (aNode) {
        aNode->parent = aParent;
        aNode->left = NULL;
        aNode->right = NULL;
        aNode->value = aValue;
        return aNode;
    } else {
        cout << "������ ��� �������� ��������!" << endl;
        return NULL;
    }
}

void destroyNode(Node *aNode) {
    if (aNode) {
        destroyNode(aNode->left);
        destroyNode(aNode->right);
        delete aNode;
    }
}

void destroyTree(Tree *aTree) {
    if (aTree) {
        destroyNode(aTree->root);
        delete aTree;
    }
}

//=========================================================

Node *minValue(Node *aNode) {
    if (aNode->left) {
        while (aNode->left)
            aNode = aNode->left;
        return aNode;
    }
    return NULL;
}

Node *maxValue(Node *aNode) {
    if (aNode->right) {
        while (aNode->right)
            aNode = aNode->right;
        return aNode;
    }
    return NULL;
}

//=========================================================

void insertElement(Tree *aTree, int aValue) {
    if (aTree) {
        if (!aTree->root) {
            Node *aNode = createNode(aTree->root, aValue); //(NULL, aValue);
            if (aNode) {
                aTree->root = aNode;
                aTree->count++;
            } else {
                cout << "������ ��� ���������� ��������!" << endl;
                return;
            }
        } else {
            Node *aFast = aTree->root;
            Node *aLow = NULL;

            while (true) {
                aLow = aFast;

                if (aValue == aFast->value) {
                    cout << "����� ������� ��� ��� ��������." << endl;
                    break;
                } else if (aValue < aFast->value) {
                    aFast = aFast->left;
                    if (!aFast) //����
                    {
                        Node *aNode = createNode(aLow, aValue);
                        aLow->left = aNode;
                        aTree->count++;
                        break;
                    }
                } else {
                    aFast = aFast->right;
                    if (!aFast) //����
                    {
                        Node *aNode = createNode(aLow, aValue);
                        aLow->right = aNode;
                        aTree->count++;
                        break;
                    }
                }
            }
        }
    } else
        cout << "������!" << endl;
}

void deleteElement(Tree *aTree, Node *aNode) {
    if (aTree && aNode) {
        if (aNode->left && aNode->right) {
            Node *aMax = maxValue(aNode->left);
            aNode->value = aMax->value;
            deleteElement(aTree, aMax);
            return;
        } else if (aNode->parent) {
            if (aNode->left) {
                if (aNode == aNode->parent->left)
                    aNode->parent->left = aNode->left;
                else
                    aNode->parent->right = aNode->left;
            } else if (aNode->right) {
                if (aNode == aNode->parent->right)
                    aNode->parent->right = aNode->right;
                else
                    aNode->parent->left = aNode->right;
            } else //leaf
            {
                if (aNode == aNode->parent->left)
                    aNode->parent->left = NULL;
                else
                    aNode->parent->right = NULL;
            }
        } else if (aTree->root == aNode) {
            if (aNode->left) {
                Node *aMax = maxValue(aNode->left);
                aTree->root->value = aMax->value;
                deleteElement(aTree, aMax);
                return;
            } else if (aNode->right) {
                Node *aMax = maxValue(aNode->right);
                aTree->root->value = aMax->value;
                deleteElement(aTree, aMax);
                return;
            } else //leaf
            {
                aTree->root = NULL;
            }
        }
        free(aNode);
        aTree->count--;
    }
}

//=========================================================

Node *search(Node *aNode, int aValue) {
    if (aNode) {
        if (aValue < aNode->value)
            return search(aNode->left, aValue);

        else if (aValue > aNode->value)
            return search(aNode->right, aValue);

        else
            return aNode;
    } else
        return NULL;
}

void searchSoloNode(Node *aNode, int *anAmount) {
    if (aNode) {
        if (aNode->left && !aNode->right) {
            (*anAmount)++;
            searchSoloNode(aNode->left, anAmount);
        } else if (aNode->right && !aNode->left) {
            (*anAmount)++;
            searchSoloNode(aNode->right, anAmount);
        } else if (aNode->left && aNode->right) {
            searchSoloNode(aNode->left, anAmount);
            searchSoloNode(aNode->right, anAmount);
        }
    }
}

void deleteElement(Tree *aTree, int aValue) {
    if (aTree) {
        Node *toDelete = search(aTree->root, aValue);

        if (toDelete) {
            deleteElement(aTree, toDelete);
            return;
        }
    }
    cout << "������!" << endl;
}

//=========================================================

void preorderPrint(Node *aNode) {
    if (aNode) {
        cout << aNode->value << " ";
        preorderPrint(aNode->left);
        preorderPrint(aNode->right);
    }
}

void inorderPrint(Node *aNode) {
    if (aNode) {
        inorderPrint(aNode->left);
        cout << aNode->value << " ";
        inorderPrint(aNode->right);
    }
}

void postorderPrint(Node *aNode) {
    if (aNode) {
        postorderPrint(aNode->left);
        postorderPrint(aNode->right);
        cout << aNode->value << " ";
    }
}

void print(Tree *aTree, int printType) {
    if (aTree) {
        cout << endl
             << "���������� ���������: " << aTree->count << endl;
        cout << "�������� �������: " << aTree->root->value << endl;

        if (aTree->root) {
            cout << "�������� ������: " << endl;

            switch (printType) {
            case 1:
                preorderPrint(aTree->root);
                cout << endl;
                break;
            case 2:
                inorderPrint(aTree->root);
                cout << endl;
                break;
            case 3:
                postorderPrint(aTree->root);
                cout << endl;
                break;
            case 4:
                levelorderPrint(aTree->root);
                cout << endl;
                break;
            default:
                cout << "������������ ���." << endl;
            }
        }
    }
}

//=========================================================

int main() {
    setlocale(LC_ALL, "");
    Tree *theTree = createTree();

    int printType, amount = 0;
    do {
        cout << "������� ��� ������ ������." << endl
             << "1 - ������." << endl
             << "2 - ������������." << endl
             << "3 - ��������." << endl
             << "�������: ";
        cin >> printType;
    } while (printType < 1 || printType > 3);

    cout << endl
         << "�������� ��������� ������ ..." << endl;

    srand(time(NULL));
    for (int i = 0; i < 15; i++)
        insertElement(theTree, rand());

    print(theTree, printType);

    searchSoloNode(theTree->root, &amount);
    cout << endl
         << "���������� ��������� � ����� ��������: " << amount << endl;

    cout << endl
         << "�������� ��������� �������� ..." << endl
         << endl;

    cout << "���������� ��������: " << theTree->root->value << endl;
    deleteElement(theTree, theTree->root->value);
    cout << "����� ��������: " << theTree->root->value << endl;

    print(theTree, printType);

    cout << endl
         << "�������� �������� �� ��������� 5151 ..." << endl;
    insertElement(theTree, 5151);

    print(theTree, printType);

    cout << endl
         << "�������� ��������� ������ ..." << endl;
    destroyTree(theTree);

    system("pause");
    return 0;
}
