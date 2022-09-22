#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", arr + i);
    }
    int s;
    scanf(" %d", &s);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            found = 1;
            printf("%d ", i);
        }
    }
    if (found == 0)
    {
        printf("-1");
    }
    printf("\n");
    free(arr);
    return 0;
}