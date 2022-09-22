#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *a, int n)
{
    int ccount = 0;
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && (++ccount) && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return ccount;
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int *a, n;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int ccount = insertion_sort(a, n);
    print(a, n);
    printf("\n%d\n", ccount);
    free(a);
    return 0;
}
