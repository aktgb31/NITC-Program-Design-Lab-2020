#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
struct node *create_node(int k)
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
void push(struct stack *s, int k)
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

int evaluatepostfix(char e[])
{
    struct stack s;
    int n = strlen(e);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i] == ' ')
            continue;
        else if (isdigit(e[i]))
        {
            int number = 0;
            while (isdigit(e[i]))
            {
                number = number * 10 + (int)(e[i] - '0');
                i++;
            }
            i--;
            push(&s, number);
        }
        else
        {
            int b = s.top->data;
            pop(&s);
            int a = s.top->data;
            pop(&s);
            switch (e[i])
            {
            case '+':
                push(&s, a + b);
                break;
            case '-':
                push(&s, a - b);
                break;
            case '*':
                push(&s, a * b);
                break;
            case '/':
                push(&s, a / b);
                break;
            }
        }
    }
    ans = s.top->data;
    pop(&s);
    return ans;
}
int main()
{
    char input[1000];
    scanf("%[^\n]", input);
    printf("%d", evaluatepostfix(input));
}