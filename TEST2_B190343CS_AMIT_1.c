#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct data
{
    char B_No[100];
    float R_time;
};

void read_details(struct data *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %s %f", c[i].B_No, &c[i].R_time);
    }
}

void peak_time(struct data *c, int n)
{
    float ans = 0.00;
    int count = 0;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && fabs(c[i].R_time - c[j].R_time) < 0.00001)
        {
            j++;
        }
        if (count < j - i)
        {
            count = j - i;
            ans = c[i].R_time;
        }
        i = j;
    }
    printf("%0.02f", ans);
}
void display_time(struct data *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %0.2f \n", c[i].B_No, c[i].R_time);
    }
}

float group_g(struct data *c1, struct data *c2, struct data *c3, int n, int kth)
{
    struct data *d = (struct data *)malloc(sizeof(struct data) * 3 * n);
    int i = 0, j = 0, k = 0, z = 0;
    while (i < n && j < n && k < n)
    {
        if (c1[i].R_time <= c2[j].R_time && c1[i].R_time <= c3[k].R_time)
        {
            strcpy(d[z].B_No, c1[i].B_No);
            d[z].R_time = c1[i].R_time;
            i++;
            z++;
        }
        else if (c2[j].R_time <= c3[k].R_time && c2[j].R_time <= c1[i].R_time)
        {
            strcpy(d[z].B_No, c2[j].B_No);
            d[z].R_time = c2[j].R_time;
            j++;
            z++;
        }
        else if (c3[k].R_time <= c1[i].R_time && c3[k].R_time <= c2[j].R_time)
        {
            strcpy(d[z].B_No, c3[k].B_No);
            d[z].R_time = c3[k].R_time;
            k++;
            z++;
        }
    }

    while (j < n && k < n)
    {
        if (c2[j].R_time <= c3[k].R_time)
        {
            strcpy(d[z].B_No, c2[j].B_No);
            d[z].R_time = c2[j].R_time;
            j++;
            z++;
        }
        else
        {
            strcpy(d[z].B_No, c3[k].B_No);
            d[z].R_time = c3[k].R_time;
            k++;
            z++;
        }
    }
    while (j < n && i < n)
    {
        if (c2[j].R_time <= c1[i].R_time)
        {
            strcpy(d[z].B_No, c2[j].B_No);
            d[z].R_time = c2[j].R_time;
            j++;
            z++;
        }
        else
        {
            strcpy(d[z].B_No, c1[i].B_No);
            d[z].R_time = c1[i].R_time;
            i++;
            z++;
        }
    }
    while (i < n && k < n)
    {
        if (c1[i].R_time <= c3[k].R_time)
        {
            strcpy(d[z].B_No, c1[i].B_No);
            d[z].R_time = c1[i].R_time;
            i++;
            z++;
        }
        else
        {
            strcpy(d[z].B_No, c3[k].B_No);
            d[z].R_time = c3[k].R_time;
            k++;
            z++;
        }
    }
    while (i < n)
    {
        strcpy(d[z].B_No, c1[i].B_No);
        d[z].R_time = c1[i].R_time;
        i++;
        z++;
    }
    while (j < n)
    {
        strcpy(d[z].B_No, c2[j].B_No);
        d[z].R_time = c2[j].R_time;
        j++;
        z++;
    }
    while (k < n)
    {
        strcpy(d[z].B_No, c3[k].B_No);
        d[z].R_time = c3[k].R_time;
        k++;
        z++;
    }

    int pos = -1;
    int count = 1;
    for (int p = 1; p < z; p++)
    {

        if (fabs(d[p].R_time - d[p - 1].R_time) > 0.001)
            count++;
        if (count == kth)
            pos = p;
    }
    if (pos == -1)
    {

        return -1;
    }
    display_time(d, pos + 1);
    float ans = d[pos].R_time;
    free(d);
    return (ans);
}
int main()
{

    int n;
    scanf("%d", &n);

    struct data *c1 = (struct data *)malloc(sizeof(struct data) * n);
    struct data *c2 = (struct data *)malloc(sizeof(struct data) * n);
    struct data *c3 = (struct data *)malloc(sizeof(struct data) * n);
    char c;
    scanf(" %c", &c);

    while (c != 't')
    {
        if (c == 'r')
        {
            int m;
            scanf(" %d", &m);
            if (m == 1)
                read_details(c1, n);
            if (m == 2)
                read_details(c2, n);
            if (m == 3)
                read_details(c3, n);
        }
        if (c == 'p')
        {
            int m;
            scanf("%d", &m);
            if (m == 1)
                peak_time(c1, n);
            if (m == 2)
                peak_time(c2, n);
            if (m == 3)
                peak_time(c3, n);
        }
        if (c == 'g')
        {
            int k;
            scanf("%d", &k);
            float ans = group_g(c1, c2, c3, n, k);
            if (fabs(ans - (-1)) < 0.001)
                printf("-1\n");
            else
                printf("%0.2f\n", ans);
        }
        if (c == 'd')
        {
            int m;
            scanf("%d", &m);
            if (m == 1)
                display_time(c1, n);
            if (m == 2)
                display_time(c2, n);
            if (m == 3)
                display_time(c3, n);
        }
        scanf("%c", &c);
    }
    free(c1);
    free(c2);
    free(c3);
    return 0;
}
