#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *A;
    int max_size;
};
int stack_empty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}
int stack_full(struct stack *s)
{
    if (s->top == s->max_size - 1)
        return 1;
    return 0;
}
void push(struct stack *s, int k)
{
    if (!stack_full(s))
    {
        s->top++;
        s->A[s->top] = k;
    }
}
int pop(struct stack *s)
{
    if (stack_empty(s))
    {
        return -1;
    }
    else
    {
        s->top--;
        return s->A[s->top + 1];
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    scanf("%d", &(s->max_size));
    s->A = (int *)malloc(sizeof(int) * s->max_size);
    s->top = -1;
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
    free(s->A);
    free(s);
    return 0;
}