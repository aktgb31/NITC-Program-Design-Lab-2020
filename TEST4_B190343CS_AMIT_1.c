#include <stdio.h>
#include <stdlib.h>

struct record
{
    int acc_no;
    char cust_name[100];
    float balance;
};

void read_and_store(struct record *C, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %f", &C[i].acc_no, C[i].cust_name, &C[i].balance);
    }
}
void sort_records(struct record *C, int n)
{
    for (int i = 1; i < n; i++)
    {
        struct record key = C[i];
        int j = i - 1;
        while (j >= 0 && C[j].acc_no > key.acc_no)
        {
            C[j + 1] = C[j];
            j--;
        }
        C[j + 1] = key;
    }
}
void search_record(struct record *C, int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (C[i].acc_no == a)
        {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}
void display(struct record *C, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %0.2f\n", C[i].acc_no, C[i].cust_name, C[i].balance);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    struct record *C;
    int n;
    char ch;
    while (scanf("%c", &ch) && ch != 'e')
    {
        switch (ch)
        {
        case 'r':
        {
            scanf("%d", &n);
            C = (struct record *)malloc(sizeof(struct record) * n);
            read_and_store(C, n);
        }
        break;
        case 's':
        {
            sort_records(C, n);
        }
        break;
        case 'f':
        {
            int a;
            scanf("%d", &a);
            search_record(C, n, a);
        }
        break;
        case 'd':
        {
            display(C, n);
        }
        default:
            break;
        }
    }
}