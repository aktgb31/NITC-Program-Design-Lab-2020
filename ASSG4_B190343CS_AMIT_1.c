#include <stdio.h>
#include <stdlib.h>

void partition(int *A, int p, int *q, int r)
{
    *q = p - 1;
    int x = A[r];
    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            (*q)++;
            int temp = A[*q];
            A[*q] = A[j];
            A[j] = temp;
        }
    }
    (*q)++;
    int temp = A[*q];
    A[*q] = A[r];
    A[r] = temp;
}
long long quick_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int q;
        partition(A, p, &q, r);
        long long x = quick_sort(A, p, q - 1);
        long long y = quick_sort(A, q + 1, r);
        return ((long long)r - (long long)p + x + y);
    }
    return 0;
}
void print(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int *A;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
    }
    //print(A, n);
    long long count = quick_sort(A, 0, n - 1);
    print(A, n);
    printf("%lld\n", count);
    free(A);
    return 0;
}
