#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x, y) ((x > y) ? x : y)
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char A[10000], B[10000];
    scanf("%[^\n]", A);
    scanf(" %[^\n]", B);
    //  printf("%d\n", strlen(A));
    // printf("%d\n", MAX(0, (int)(strlen(A) - strlen(B))));
    int flag = -1;
    for (int i = 0; i <= MAX(0, (int)(strlen(A) - strlen(B))); i++)
    {
        int j = 0;
        for (; j < strlen(B); j++)
        {
            if (A[i + j] != B[j])
            {
                break;
            }
        }
        if (j == strlen(B))
        {
            flag = 1;
            printf("%d\n", i);
        }
    }

    if (flag == -1)
        printf("-1\n");
}