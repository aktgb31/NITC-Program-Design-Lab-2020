#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000
/*

I have considered starting index of heap as 1.
so i used 0 th index to store the size of the heap.

*/
void MIN_HEAPIFY(int *A, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int smallest = i;
    if (l <= A[0] && A[l] < A[i])
    {
        smallest = l;
    }
    if (r <= A[0] && A[r] < A[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        int temp = A[smallest];
        A[smallest] = A[i];
        A[i] = temp;
        MIN_HEAPIFY(A, smallest);
    }
}

void CHANGE_TOKEN_NUMBER(int *Q, int k, int x)
{
}
void INSERT_PATIENT(int *Q, int k)
{
    Q[0] += 1;
    int i = Q[0];
    Q[i] = INF;
    Q[i] = k;
    while (i > 1 && Q[i / 2] > Q[i])
    {
        int temp = Q[i / 2];
        Q[i / 2] = Q[i];
        Q[i] = temp;
        i = i / 2;
    }
}
void GET_NEXT_PATIENT(int *Q)
{
    if (Q[0] < 1)
        printf("%d\n", -1);
    else
        printf("%d\n", Q[1]);
}
void EXTRACT_NEXT_PATIENT(int *Q)
{
    if (Q[0] < 1)
        printf("%d\n", -1);
    else
    {
        printf("%d\n", Q[1]);
        Q[1] = Q[Q[0]];
        Q[0]--;
        MIN_HEAPIFY(Q, 1);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char choice;
    int *Q = (int *)malloc(sizeof(int) * 1000001);
    Q[0] = 0;
    while (scanf("%c", &choice) && choice != 's')
    {
        switch (choice)
        {
        case 'i':
        {
            int k;
            scanf("%d", &k);
            INSERT_PATIENT(Q, k);
        }
        break;
        case 'm':
        {
            GET_NEXT_PATIENT(Q);
        }
        break;
        case 'e':
        {
            EXTRACT_NEXT_PATIENT(Q);
        }
        break;
        case 'd':
        {
            int k, x;
            scanf("%d %d", &k, &x);
            CHANGE_TOKEN_NUMBER(Q, k, x);
        }
        break;
        default:
            break;
        }
    }
    free(Q);
}