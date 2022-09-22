#include <stdio.h>
#include <stdlib.h>

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
int pop(struct stack *s)
{

    if (stack_empty(s))
    {
        return -1;
    }
    else
    {
        struct node *temp = s->top;
        s->top = s->top->next;
        int t = temp->data;
        temp->next = NULL;
        free(temp);
        return t;
    }
}
int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = NULL;
    char ch;
    while (scanf("%c", &ch) && ch != 't')
    {
        switch (ch)
        {
        case 'i':
        {
            int k;
            scanf("%d", &k);
            push(s, k);
        }
        break;
        case 'd':
        {
            printf("%d\n", pop(s));
        }
        break;
        case 'e':
        {
            if (stack_empty(s))
            {
                printf("%d\n", -1);
            }
            else
            {
                printf("%d\n", 1);
            }
        }
        break;
        default:
            break;
        }
    }
    free(s);
    return 0;
}