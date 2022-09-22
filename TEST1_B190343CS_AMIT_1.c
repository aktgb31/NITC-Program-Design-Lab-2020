#include <stdio.h>
#include <stdlib.h>

void find_position(int *a, int *b, int n, int e)
{
    int *t = (int *)malloc(sizeof(int) * n);
    int *c = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        t[i] = b[i];
    }
    for (int i = 1; i < n; i++)
    {
        int key = t[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key)
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        int key = t[i];
        int start = 0, end = n - 1, p = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (b[mid] == key)
            {
                p = mid;
                break;
            }
            else if (b[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        c[p] = a[i];
        if (c[p] == e)
            pos = p;
    }

    printf("%d\n", pos + 1);
    for (int i = 0; i < n; i++)
    {
        if (t[i] < b[pos])
            printf("%d %d\n", a[i], t[i]);
    }
    printf("%d %d\n", c[pos], b[pos]);
    for (int i = 0; i < n; i++)
    {
        if (t[i] > b[pos])
            printf("%d %d\n", a[i], t[i]);
    }
    free(t);
}
void read(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        scanf("%d", b + i);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int *a, *b, n, e, pos;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);
    read(a, b, n);
    scanf("%d", &e);
    find_position(a, b, n, e);
    free(a);
    free(b);
    return 0;
}