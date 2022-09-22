#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// infix to postfix
struct node
{
    char data;
    struct node *next;
};
struct stack_p
{
    struct node *top;
};
struct node *create_node(char k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

void push_s(struct stack_p *s, char k)
{
    struct node *temp = create_node(k);
    temp->next = s->top;
    s->top = temp;
}
void pop_s(struct stack_p *s)
{
    struct node *temp = s->top;
    s->top = s->top->next;
    temp->next = NULL;
    free(temp);
}
int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
char *infixtopostfix(char e[])
{
    struct stack_p s;
    push_s(&s, 'E');
    int n = strlen(e);
    char *ans = (char *)malloc(sizeof(char) * (n + 1));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i] >= 'a' && e[i] <= 'z')
            ans[j++] = e[i];
        else if (e[i] == '(')
            push_s(&s, e[i]);
        else if (e[i] == ')')
        {
            while (s.top->data != 'E' && s.top->data != '(')
            {
                char c = s.top->data;
                pop_s(&s);
                ans[j++] = c;
            }
            if (s.top->data == '(')
            {
                pop_s(&s);
            }
        }
        else
        {
            while (s.top->data != 'E' && precedence(e[i]) <= precedence(s.top->data))
            {
                char c = s.top->data;
                pop_s(&s);
                ans[j++] = c;
            }
            push_s(&s, e[i]);
        }
    }
    while (s.top->data != 'E')
    {
        char c = s.top->data;
        pop_s(&s);
        ans[j++] = c;
    }
    ans[j++] = '\0';
    return ans;
}

// postfix to expression tree

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
struct tree_node *construcassignmenttree(char s[])
{
    char t[strlen(s) - 2];
    for (int i = 2; s[i] != ';'; i++)
        t[i - 2] = s[i];
    t[strlen(s) - 3] = '\0';
    // printf("%s\n", t);
    char *p = infixtopostfix(t);
    //  printf("%s\n", p);
    struct tree_node *root, *t1, *t2;
    root = constructree(p);
    t1 = create_tree_node(s[0]);
    t2 = create_tree_node(s[1]);
    t2->right = root;
    t2->left = t1;
    root = t2;
    return root;
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
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char input[1000];
    while (scanf("%[^\n] ", input) > 0)
    {
        struct tree t;
        t.root = construcassignmenttree(input);
        inorder(t.root);
        printf("\n");
    }
    return 0;
}