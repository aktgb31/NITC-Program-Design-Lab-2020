#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *tail, *head;
};
struct node *create_node(int k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
int queue_empty(struct queue *q)
{
    return (q->head == NULL);
}
void enqueue(struct queue *q, int k)
{
    struct node *temp = create_node(k);
    if (q->head == NULL)
    {
        q->head = q->tail = temp;
    }
    else
    {
        q->tail->next = temp;
        q->tail = temp;
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
        struct node *temp = q->head;
        q->head = q->head->next;
        int t = temp->data;
        temp->next = NULL;
        if (q->head == NULL)
            q->tail = NULL;
        free(temp);
        return t;
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->tail = q->head = NULL;
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
    free(q);
    return 0;
}