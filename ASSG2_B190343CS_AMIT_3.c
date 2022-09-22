#include <stdio.h>
#include <stdlib.h>

int *arr;
int fsearch(int start, int end, int p)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == p && (mid == 0 || arr[mid - 1] < p))
        {
            return mid;
        }
        else if (arr[mid] < p)
        {
            return fsearch(mid + 1, end, p);
        }
        else
        {
            return fsearch(start, mid - 1, p);
        }
    }
    return -1;
}

int main()
{
    int n, m, p;
    scanf("%d", &n);
    scanf("%d", &m);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p);
        printf("%d\n", fsearch(0, n - 1, p));
    }
    free(arr);
    return 0;
}