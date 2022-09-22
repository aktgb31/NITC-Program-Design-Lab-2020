#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int m, h;
struct data
{
    char B_No[100];
    float R_time;
};
struct metadata
{
    struct data *heap;
    int size;
};
swap(struct data *a, struct data *b)
{
    struct data temp;
    strcpy(temp.B_No, a->B_No);
    temp.R_time = a->R_time;
    strcpy(a->B_No, b->B_No);
    a->R_time = b->R_time;
    strcpy(b->B_No, temp.B_No);
    b->R_time = temp.R_time;
}
void max_heapify(struct metadata *H, int index)
{
    int ch[h + 1];

    while (10)
    {
        for (int i = 1; i <= h; i++)
            ch[i] = ((h * index + i) < H->size) ? (h * index + i) : -1;

        int mc = -1, mc_index;
        for (int i = 1; i <= h; i++)
        {
            if (ch[i] != -1 &&
                H->heap[ch[i]].R_time > mc)
            {
                mc_index = ch[i];
                mc = H->heap[ch[i]].R_time;
            }
        }
        if (fabs(mc - (-1)) < 0.001)
            break;

        if (H->heap[index].R_time < H->heap[mc_index].R_time)
            swap(&H->heap[index], &H->heap[mc_index]);

        index = mc_index;
    }
}

void heap_sort(struct metadata h)
{
    build_max_heap(H);
}
void merge(struct metadata *counters)
{
}
void main()
{
    scanf("%d%d", &m, &h);
    struct metadata *counters;
    counters = (struct metadata *)malloc(sizeof(struct metadata) * m);
    for (int i = 0; i < m; i++)
    {
        int n;
        scanf("%d", &n);
        counters[i].size = n;
        counters[i].heap = (struct data *)malloc(sizeof(struct data) * n);
        for (int j = 0; j < n; j++)
        {
            scanf(" %s %f", counters[i].heap[j].B_No, &counters[i].heap[j].R_time);
        }
    }
    for (int i = 0; i < m; i++)
    {
        heap_sort(counters[i]);
    }
    merge(counters);
}