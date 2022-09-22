#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct record
{
    char name[100];
    float cgpa;
};
void combine(struct record *L1, struct record *L2, int n1, int n2)
{
    int size = n1;
    for (int j = 0; j < n2; j++)
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            if (L2[j].cgpa >= L1[i].cgpa || fabs(L2[j].cgpa - L1[i].cgpa) < 0.0001)
                continue;
            else
                break;
        }
        for (int k = size; k >= i + 1; k--)
        {
            strcpy(L1[k].name, L1[k - 1].name);
            L1[k].cgpa = L1[k - 1].cgpa;
        }
        strcpy(L1[i].name, L2[j].name);
        L1[i].cgpa = L2[j].cgpa;
        size++;
    }
}
int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    struct record *L1 = (struct record *)malloc((n1 + n2) * sizeof(struct record));
    struct record *L2 = (struct record *)malloc(n2 * sizeof(struct record));
    for (int i = 0; i < n1; i++)
    {
        scanf("%s", L1[i].name);
        scanf("%f", &L1[i].cgpa);
    }
    for (int i = 0; i < n2; i++)
    {
        scanf("%s", L2[i].name);
        scanf("%f", &L2[i].cgpa);
    }

    combine(L1, L2, n1, n2);
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%s %0.2f\n", L1[i].name, L1[i].cgpa);
    }
    return 0;
}