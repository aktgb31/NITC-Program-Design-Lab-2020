#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void combine(float *L1, float *L2, int n1, int n2)
{
    int size = n1;
    for (int j = 0; j < n2; j++)
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            if (L2[j] >= L1[i] || fabs(L2[j] - L1[i]) < 0.001)
                continue;
            else
                break;
        }
        for (int k = size; k >= i + 1; k--)
        {
            L1[k] = L1[k - 1];
        }
        L1[i] = L2[j];
        size++;
    }
}
int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    float *L1 = (float *)malloc((n1 + n2) * sizeof(float));
    float *L2 = (float *)malloc(n2 * sizeof(float));
    for (int i = 0; i < n1; i++)
        scanf(" %f", L1 + i);
    for (int i = 0; i < n2; i++)
        scanf(" %f", L2 + i);

    combine(L1, L2, n1, n2);
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%0.2f ", L1[i]);
    }
    return 0;
}