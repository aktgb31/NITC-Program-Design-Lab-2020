#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

struct node *combine1(struct node *T1, int k, struct node *T2)
{
    struct node *temp = createnode(k);
    temp->left = T1;
    temp->right = T2;
    if (T1 != NULL)
        T1->p = temp;
    if (T2 != NULL)
        T2->p = temp;
    T1 = NULL;
    T2 = NULL;
    return temp;
}

struct node *combine2(struct Binary_Search_Tree *T1, struct Binary_Search_Tree *T2)
{
    if (T1->root != NULL)
    {
        struct node *temp = T1->root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        struct node *newnode = combine1(temp->left, temp->key, T2->root);
        //inorder(newnode);
        if (temp->p != NULL)
        {
            temp->p->right = newnode;
            newnode->p = temp->p;
        }
        else
        {
            T1->root = newnode;
        }
        temp = newnode;
        struct node *ans = T1->root;
        T1->root = NULL;
        return ans;
    }
    else
    {
        struct node *ans = T2->root;
        T2->root = NULL;
        return ans;
    }
}
int main()
{

    struct Binary_Search_Tree T1, T2;
    T1.root = NULL;
    T2.root = NULL;
    char t1[1000];
    char t2[1000];
    int j = 0;
    char c;
    while (scanf("%c", &c) && c != '\n')
    {
        t1[j++] = c;
    }
    t1[j] = '\0';
    if (isdigit(t1[0]))
    {
        for (int i = 0; t1[i] != '\0'; i++)
        {
            if (t1[i] == ' ')
                continue;
            int num = 0;
            while (isdigit(t1[i]))
            {
                num = num * 10 + (t1[i] - '0');
                i++;
            }
            i--;
            insert(&T1, num);
        }
    }
    j = 0;
    while (scanf("%c", &c) && c != '\n')
    {
        t2[j++] = c;
    }
    t2[j] = '\0';
    //printf("%d", strlen(t2));
    if (isdigit(t2[0]))
    {
        for (int i = 0; t2[i] != '\0'; i++)
        {
            if (t2[i] == ' ')
                continue;
            int num = 0;
            while (isdigit(t2[i]))
            {
                num = num * 10 + (t2[i] - '0');
                i++;
            }
            i--;
            insert(&T2, num);
        }
    }
    struct Binary_Search_Tree ans;
    ans.root = combine2(&T1, &T2);
    inorder(ans.root);
    return 0;
}