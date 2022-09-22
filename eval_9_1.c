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

struct node *combine1(struct Binary_Search_Tree *T1, int k, struct Binary_Search_Tree *T2)
{
    struct node *temp = createnode(k);
    temp->left = T1->root;
    temp->right = T2->root;
    if (T1->root != NULL)
        T1->root->p = temp;
    if (T2->root != NULL)
        T2->root->p = temp;
    T1->root = NULL;
    T2->root = NULL;
    return temp;
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
    int k;
    scanf("%d", &k);
    //printf("%d", k);
    struct Binary_Search_Tree ans;
    //inorder(T1.root);
    //inorder(T2.root);
    ans.root = combine1(&T1, k, &T2);
    //printf("%d\n", ans.root);
    inorder(ans.root);
    return 0;
}