#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tree_node
{
    char value;
    struct tree_node *left, *right;
};
struct tree
{
    struct tree_node *root;
};
struct tree_node *create_tree_node(char data)
{
    struct tree_node *temp = (struct tree_node *)malloc(sizeof(struct tree_node));
    temp->left = temp->right = NULL;
    temp->value = data;
    return temp;
};
struct stack_node
{
    struct tree_node *data;
    struct stack_node *next;
};
struct stack
{
    struct stack_node *top;
};
struct stack_node *create_stack_node(struct tree_node *k)
{
    struct stack_node *temp = (struct stack_node *)malloc(sizeof(struct stack_node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
int stack_empty(struct stack *s)
{
    return (s->top == NULL);
}
void push(struct stack *s, struct tree_node *k)
{
    struct stack_node *temp = create_stack_node(k);
    temp->next = s->top;
    s->top = temp;
}
void pop(struct stack *s)
{
    struct stack_node *temp = s->top;
    s->top = s->top->next;
    temp->next = NULL;
    free(temp);
}

struct tree_node *constructree(char e[])
{
    struct stack s;
    struct tree_node *t;
    int n = strlen(e);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i] >= 'a' && e[i] <= 'z')
        {
            t = create_tree_node(e[i]);
            push(&s, t);
        }
        else
        {
            t = create_tree_node(e[i]);
            t->right = s.top->data;
            pop(&s);
            t->left = s.top->data;
            pop(&s);
            push(&s, t);
        }
    }
    t = s.top->data;
    pop(&s);
    return t;
}
void inorder(struct tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c", root->value);
        inorder(root->right);
    }
}
void preorder(struct tree_node *root)
{
    if (root != NULL)
    {
        printf("%c", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct tree_node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->value);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char input[1000];
    struct tree t;
    char ch;
    scanf("%c", &ch);
    while (ch != 't')
    {
        switch (ch)
        {
        case 'e':
            scanf("%s", input);
            t.root = constructree(input);
            break;

        case 'i':
            inorder(t.root);
            printf("\n");
            break;
        case 'p':
            preorder(t.root);
            printf("\n");
            break;
        case 's':
            postorder(t.root);
            printf("\n");
            break;
        }
        scanf("%c", &ch);
    }
    return 0;
}