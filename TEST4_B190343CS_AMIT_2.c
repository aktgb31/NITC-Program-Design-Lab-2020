#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
    int key;
    struct tree_node *left, *right, *p;
};
struct Binary_Search_Tree
{
    struct tree_node *root;
};
struct list_node
{
    struct tree_node *key;
    struct list_node *next;
};

struct LinkedList
{
    struct list_node *head;
};
struct tree_node *createTreeNode(int item)
{
    struct tree_node *temp = (struct tree_node *)malloc(sizeof(struct tree_node));
    temp->key = item;
    temp->left = temp->right = temp->p = NULL;
    return temp;
}
void treeInsert(struct Binary_Search_Tree *T, int key)
{
    struct tree_node *prev, *curr, *temp;
    prev = NULL;
    curr = T->root;
    while (curr != NULL)
    {
        prev = curr;
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    temp = createTreeNode(key);
    if (prev == NULL)
        T->root = temp;
    else
    {
        if (key < prev->key)
        {
            prev->left = temp;
            temp->p = prev;
        }
        else
        {
            prev->right = temp;
            temp->p = prev;
        }
    }
}

struct tree_node *treeSearch(struct tree_node *T, int key)
{
    if (T == NULL)
        return NULL;
    if (key == T->key)
        return T;
    if (key < T->key)
        return treeSearch(T->left, key);
    else
        return treeSearch(T->right, key);
}
struct list_node *listSearch(struct LinkedList *L, struct tree_node *k)
{
    struct list_node *temp = L->head;
    while (temp != NULL)
    {
        if (temp->key == k)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}
void listDelete(struct LinkedList *C, struct list_node *x)
{
    struct list_node *temp = C->head;
    struct list_node *temp2 = C->head;
    while (temp != NULL)
    {
        if (temp == x)
        {
            break;
        }
        temp2 = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    else
    {
        if (temp == C->head)
        {
            C->head = temp->next;
        }
        else
        {
            temp2->next = temp->next;
        }
        free(temp);
    }
}

struct tree_node *tree_minimum(struct tree_node *T)
{
    struct tree_node *temp = T;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

void transplant(struct Binary_Search_Tree *T, struct tree_node *x, struct tree_node *y)
{
    if (x->p == NULL)
        T->root = y;
    else
    {
        if (x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
    }
    if (y != NULL)
        y->p = x->p;
}

int treeDelete(struct Binary_Search_Tree *T, struct tree_node *x)
{
    if (x == NULL)
        return -1;
    if (x->left == NULL)
    {
        transplant(T, x, x->right);
    }
    else if (x->right == NULL)
    {
        transplant(T, x, x->left);
    }
    else
    {
        struct tree_node *y = tree_minimum(x->right);
        if (y->p != x)
        {
            transplant(T, y, y->right);
            y->right = x->right;
            x->right->p = y;
        }
        transplant(T, x, y);
        y->left = x->left;
        x->left->p = y;
    }
    return x->key;
}
void inorder(struct tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
//Main functions asked in the question

void InsertSet(struct LinkedList *C, struct Binary_Search_Tree *S)
{
    struct list_node *x = (struct list_node *)malloc(sizeof(struct list_node));
    x->key = S->root;
    x->next = C->head;
    C->head = x;
}

struct tree_node *FindSet(struct LinkedList *C, int k)
{
    struct list_node *temp = C->head;
    while (temp != NULL)
    {
        struct tree_node *a = treeSearch(temp->key, k);
        if (a != NULL)
        {
            printf("%d\n", temp->key->key);
            return temp->key;
        }
        temp = temp->next;
    }
    printf("-1\n");
    return NULL;
}

void DeleteSet(struct LinkedList *C, int k)
{
    struct tree_node *a = FindSet(C, k);
    listDelete(C, listSearch(C, a));
}

void MergeSets(struct LinkedList *C, int k1, int k2)
{
    struct tree_node *a1 = FindSet(C, k1);
    struct tree_node *a2 = FindSet(C, k2);
    struct Binary_Search_Tree T2, T1;
    T1.root = a1;
    T2.root = a2;
    while (T2.root != NULL)
    {
        int k = treeDelete(&T2, T2.root);
        treeInsert(&T1, k);
    }
    listDelete(C, NULL);
}

void PrintCollection(struct LinkedList *C)
{
    struct list_node *temp = C->head;
    while (temp != NULL)
    {
        inorder(temp->key);
        printf("\n");
        temp = temp->next;
    }
}
int main()
{
    struct LinkedList C;
    C.head = NULL;

    char ch;
    while (scanf("%c", &ch) && ch != 'e')
    {
        switch (ch)
        {
        case 'i':
        {
            int k;
            scanf("%d", &k);
            struct Binary_Search_Tree S;
            S.root = NULL;
            while (k--)
            {
                int x;
                scanf("%d", &x);
                treeInsert(&S, x);
            }
            InsertSet(&C, &S);
        }
        break;
        case 'd':
        {
            int k;
            scanf("%d", &k);
            DeleteSet(&C, k);
        }
        break;
        case 'f':
        {
            int k;
            scanf("%d", &k);
            struct tree_node *a = FindSet(&C, k);
        }
        break;
        case 'm':
        {
            int k1;
            scanf("%d", &k1);
            int k2;
            scanf("%d", &k2);
            MergeSets(&C, k1, k2);
        }
        break;
        case 'p':
        {
            PrintCollection(&C);
        }
        break;
        }
    }
    return 0;
}