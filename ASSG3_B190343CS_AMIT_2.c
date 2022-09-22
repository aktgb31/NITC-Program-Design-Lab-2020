#include <stdio.h>
#include <stdlib.h>

int merge(int *a, int p, int q, int r)
{
    int ccount = 0;
    int i = p, j = q + 1, k = 0;
    int *arr = (int *)malloc(sizeof(int) * (r - p + 1));
    for (int l = p; l <= r; l++)
    {
        ++ccount;
        if (i > q)
            arr[k++] = a[j++];
        else if (j > r)
            arr[k++] = a[i++];
        else if (a[i] < a[j])
            arr[k++] = a[i++];
        else
            arr[k++] = a[j++];
    }
    for (int l = 0; l < k; l++)
    {
        a[p++] = arr[l];
    }
    free(arr);
    return ccount;
}
int merge_sort(int *a, int l, int r)
{
    if (l < r)
    {
        int q = (l + r) / 2;
        int x = merge_sort(a, l, q);
        int y = merge_sort(a, q + 1, r);
        int z = merge(a, l, q, r);
        return x + y + z;
    }
    return 0;
}
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int *a, n;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int ccount = 0;
    ccount = merge_sort(a, 0, n - 1);
    print(a, n);
    printf("\n%d\n", ccount);
    free(a);
    return 0;
}
