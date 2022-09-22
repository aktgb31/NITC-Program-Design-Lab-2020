#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

struct P_QUEUE
{
    int *Q;
    int size;
};

void MIN_HEAPIFY(struct P_QUEUE *q, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int smallest = i;
    if (l <= q->size && q->Q[l] < q->Q[i])
    {
        smallest = l;
    }
    if (r <= q->size && q->Q[r] < q->Q[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        int temp = q->Q[smallest];
        q->Q[smallest] = q->Q[i];
        q->Q[i] = temp;
        MIN_HEAPIFY(q, smallest);
    }
}

void HEAP_DECREASE_KEY(struct P_QUEUE *q, int i, int k)
{
    q->Q[i] = k;
    while (i > 1 && q->Q[i / 2] > q->Q[i])
    {
        int temp = q->Q[i / 2];
        q->Q[i / 2] = q->Q[i];
        q->Q[i] = temp;
        i = i / 2;
    }
}
void MIN_HEAP_INSERT(struct P_QUEUE *q, int k)
{
    q->size += 1;
    q->Q[q->size] = INF;
    HEAP_DECREASE_KEY(q, q->size, k);
}
void HEAP_MINIMUM(struct P_QUEUE *q)
{
    if (q->size < 1)
        printf("%d\n", -1);
    else
        printf("%d\n", q->Q[1]);
}
void HEAP_EXTRACT_MIN(struct P_QUEUE *q)
{
    if (q->size < 1)
        printf("%d\n", -1);
    else
    {
        printf("%d\n", q->Q[1]);
        q->Q[1] = q->Q[q->size];
        q->size--;
        MIN_HEAPIFY(q, 1);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char choice;
    struct P_QUEUE q;
    q.Q = (int *)malloc(sizeof(int) * 1000001);
    q.size = 0;
    while (scanf("%c", &choice) && choice != 's')
    {
        switch (choice)
        {
        case 'i':
        {
            int k;
            scanf("%d", &k);
            MIN_HEAP_INSERT(&q, k);
        }
        break;
        case 'm':
        {
            HEAP_MINIMUM(&q);
        }
        break;
        case 'e':
        {
            HEAP_EXTRACT_MIN(&q);
        }
        break;
        case 'd':
        {
            int i, k;
            scanf("%d %d", &i, &k);
            i++;
            HEAP_DECREASE_KEY(&q, i, k);
        }
        break;
        default:
            break;
        }
    }
    free(q.Q);
    return 0;
}