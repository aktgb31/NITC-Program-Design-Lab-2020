#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};
struct stack
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
int stack_empty(struct stack *s)
{
    return (s->top == NULL);
}
void push(struct stack *s, char k)
{
    struct node *temp = create_node(k);
    temp->next = s->top;
    s->top = temp;
}
void pop(struct stack *s)
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
    struct stack s;
    push(&s, 'E');
    int n = strlen(e);
    char *ans = (char *)malloc(sizeof(char) * (n + 1));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i] >= 'a' && e[i] <= 'z')
            ans[j++] = e[i];
        else if (e[i] == '(')
            push(&s, e[i]);
        else if (e[i] == ')')
        {
            while (s.top->data != 'E' && s.top->data != '(')
            {
                char c = s.top->data;
                pop(&s);
                ans[j++] = c;
            }
            if (s.top->data == '(')
            {
                pop(&s);
            }
        }
        else
        {
            while (s.top->data != 'E' && precedence(e[i]) <= precedence(s.top->data))
            {
                char c = s.top->data;
                pop(&s);
                ans[j++] = c;
            }
            push(&s, e[i]);
        }
    }
    while (s.top->data != 'E')
    {
        char c = s.top->data;
        pop(&s);
        ans[j++] = c;
    }
    ans[j++] = '\0';
    return ans;
}
int main()
{
    char input[1000];
    scanf("%[^\n]", input);
    printf("%s", infixtopostfix(input));
}