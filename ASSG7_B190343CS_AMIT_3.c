#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int head, tail;
    int *A;
    int max_size, current_size;
};
int queue_empty(struct queue *q)
{
    if (q->current_size == 0)
        return 1;
    return 0;
}
int queue_full(struct queue *q)
{
    if (q->current_size == q->max_size)
        return 1;
    return 0;
}
void enqueue(struct queue *q, int k)
{
    if (!queue_full(q))
    {
        q->A[q->tail] = k;
        q->tail = (q->tail + 1) % q->max_size;
        q->current_size++;
    }
}
int dequeue(struct queue *q)
{
    if (queue_empty(q))
    {
        return -1;
    }
    else
    {
        int temp = q->A[q->head];
        q->head = (q->head + 1) % q->max_size;
        q->current_size--;
        return temp;
    }
}
int main()
{

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    scanf("%d", &(q->max_size));
    q->A = (int *)malloc(sizeof(int) * q->max_size);
    q->current_size = 0;
    q->head = q->tail = 0;
    char ch;
    while (scanf("%c", &ch) && ch != 't')
    {
        switch (ch)
        {
        case 'i':
        {
            int k;
            scanf("%d", &k);
            enqueue(q, k);
        }
        break;
        case 'd':
        {
            printf("%d\n", dequeue(q));
        }
        break;
        case 'f':
        {
            if (queue_full(q))
            {
                printf("%d\n", -1);
            }
            else
            {
                printf("%d\n", 1);
            }
        }
        break;
        case 'e':
        {
            if (queue_empty(q))
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
    free(q->A);
    free(q);
    return 0;
}