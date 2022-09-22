#include <stdio.h>
#include <stdlib.h>

int find_highest(int *a, int *b, int n, int k)
{
    if (k == 0)
    {
        return a[n];
    }
    int c = -1;
    int d = -1;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > c)
        {
            d = i;
            c = b[i];
        }
    }
    int temp;
    temp = b[n - 1];
    b[n - 1] = c;
    b[d] = temp;
    temp = a[n - 1];
    a[n - 1] = a[d];
    a[d] = temp;
    // printf("%d %d %d\n", a[n - 1], b[n - 1], k);
    return find_highest(a, b, n - 1, k - 1);
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
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int *a, *b, n, k;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);
    read(a, b, n);
    scanf("%d", &k);
    printf("%d\n", find_highest(a, b, n, k));
    free(a);
    free(b);
    return 0;
}