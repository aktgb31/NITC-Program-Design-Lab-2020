#include <stdio.h>
#include <stdlib.h>

struct HEAP
{
    int *A;
    int size;
};
int MAX_HEAPIFY(struct HEAP *heap, int i)
{
    int count = 0;
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    if (l <= heap->size && ++count && heap->A[l] > heap->A[i])
    {
        largest = l;
    }
    if (r <= heap->size && ++count && heap->A[r] > heap->A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = heap->A[largest];
        heap->A[largest] = heap->A[i];
        heap->A[i] = temp;
        count += MAX_HEAPIFY(heap, largest);
    }
    return count;
}

int BUILD_MAX_HEAP(struct HEAP *heap)
{
    int count = 0;
    for (int i = heap->size / 2; i > 0; i--)
    {
        count += MAX_HEAPIFY(heap, i);
    }
    return count;
}
int HEAP_SORT(struct HEAP heap)
{
    int count = BUILD_MAX_HEAP(&heap);
    for (int i = heap.size; i > 1; i--)
    {
        int temp = heap.A[1];
        heap.A[1] = heap.A[i];
        heap.A[i] = temp;
        heap.size--;
        count += MAX_HEAPIFY(&heap, 1);
    }
    return count;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    struct HEAP heap;
    scanf("%d", &heap.size);
    heap.A = (int *)malloc(sizeof(int) * (heap.size + 1));
    for (int i = 1; i <= heap.size; i++)
    {
        scanf("%d", heap.A + i);
    }
    int count = HEAP_SORT(heap);
    for (int i = 1; i <= heap.size; i++)
    {
        printf("%d ", heap.A[i]);
    }
    printf("\n%d\n", count);
    free(heap.A);
    return 0;
}