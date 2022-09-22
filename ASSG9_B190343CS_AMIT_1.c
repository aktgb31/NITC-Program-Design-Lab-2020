#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right, *p;
};
struct Binary_Search_Tree
{
    struct node *root;
};
struct node *createnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = temp->p = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
void insert(struct Binary_Search_Tree *T, int key)
{
    struct node *prev, *curr, *temp;
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
    temp = createnode(key);
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
struct node *search(struct node *T, int key)
{
    if (T == NULL)
        return NULL;
    if (key == T->key)
        return T;
    if (key < T->key)
        return search(T->left, key);
    else
        return search(T->right, key);
}
struct node *tree_minimum(struct node *T)
{
    struct node *temp = T;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

void transplant(struct Binary_Search_Tree *T, struct node *x, struct node *y)
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

int delete (struct Binary_Search_Tree *T, struct node *x)
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
        struct node *y = tree_minimum(x->right);
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
int main()
{
    struct Binary_Search_Tree T;
    T.root = NULL;
    char ch;
    while (scanf("%c", &ch) && ch != 'e')
    {
        switch (ch)
        {
        case 'a':
        {
            int k;
            scanf("%d", &k);
            insert(&T, k);
        }
        break;
        case 'd':
        {
            int k;
            scanf("%d", &k);
            printf("%d\n", delete (&T, search(T.root, k)));
        }
        break;
        case 'i':
        {
            inorder(T.root);
            printf("\n");
        }
        break;
        case 'p':
        {
            preorder(T.root);
            printf("\n");
        }
        break;
        case 't':
        {
            postorder(T.root);
            printf("\n");
        }
        break;
        case 's':
        {
            int k;
            scanf("%d", &k);
            if (search(T.root, k) != NULL)
                printf("1\n");
            else
                printf("-1\n");
        }
        break;
        }
    }
    return 0;
}