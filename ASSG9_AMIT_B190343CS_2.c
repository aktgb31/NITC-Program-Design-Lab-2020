#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int model_number, price;
    char model_name[50];
    struct node *left, *right, *p;
};
struct Binary_Search_Tree
{
    struct node *root;
};
struct node *createnode(int model_number, int price, char model_name[])
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->price = price;
    temp->model_number = model_number;
    strcpy(temp->model_name, model_name);
    temp->left = temp->right = temp->p = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d %s %d\n", root->model_number, root->model_name, root->price);
        inorder(root->right);
    }
}

void insert(struct Binary_Search_Tree *T, int model_number, int price, char model_name[])
{
    struct node *prev, *curr, *temp;
    prev = NULL;
    curr = T->root;
    while (curr != NULL)
    {
        prev = curr;
        if (model_number < curr->model_number)
            curr = curr->left;
        else
            curr = curr->right;
    }
    temp = createnode(model_number, prev, model_name);
    if (prev == NULL)
        T->root = temp;
    else
    {
        if (model_number < prev->model_number)
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

struct node *search(struct node *T, int model_name)
{
    if (T == NULL)
        return NULL;
    if (model_name == T->model_name)
        return T;
    if (model_name < T->model_name)
        return search(T->left, model_name);
    else
        return search(T->right, model_name);
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

struct node *delete (struct Binary_Search_Tree *T, struct node *x)
{
    if (x == NULL)
        return NULL;
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
    return x;
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
            char name[50];
            int n;
            scanf("%d%s%n", &k, name, &n);
            insert(&T, k, name, n);
        }
        break;
        case 'd':
        {
            int k;
            scanf("%d", &k);
            struct node *temp = delete (&T, search(T.root, k) ;
            if(temp==NULL)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d %s %d\n", temp->model_number, temp->model_name, temp->price);
        
            }
        }
        break;
        case 'i':
        {
            inorder(T.root);
            printf("\n");
        }
        break;
        case 'm':
        {
            postorder(T.root);
            printf("\n");
        }
        break;
        case 's':
        {
            int k;
            scanf("%d", &k);
            struct node *temp = search(T.root, k);
            if (temp != NULL)
                printf("%d %s %d\n", temp->model_number, temp->model_name, temp->price);
            else
                printf("-1\n");
        }
        break;
        }
    }
    return 0;
}