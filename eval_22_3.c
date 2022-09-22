#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct record
{
    char name[100];
    float cgpa;
    struct record *next;
};
struct list
{
    struct record *head;
};
struct record *create_record(char name[], float cgpa)
{
    struct record *temp = (struct record *)malloc(sizeof(struct record));
    temp->cgpa = cgpa;
    strcpy(temp->name, name);
    temp->next = NULL;
    return temp;
}
void list_insert_tail(struct list *L, struct record *temp)
{

    if (L->head == NULL)
    {
        L->head = temp;
    }
    else
    {
        struct record *t = L->head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

void combine(struct list *L1, struct list *L2)
{
    if (L1->head == NULL)
    {
        L1->head = L2->head;
        return;
    }
    if (L2->head == NULL)
        return;
    while (L2->head != NULL)
    {
        struct record *j = L2->head;
        L2->head = L2->head->next;
        struct record *i = L1->head;
        struct record *prev;
        while (i != NULL)
        {
            if (i->cgpa > j->cgpa && fabs(i->cgpa - j->cgpa) > 0.001)
            {
                break;
            }
            prev = i;
            i = i->next;
        }
        j->next = NULL;
        if (i == NULL)
        {
            prev->next = j;
        }
        else if (i == L1->head)
        {
            j->next = L1->head;
            L1->head = j;
        }
        else
        {
            j->next = i;
            prev->next = j;
        }
    }
}
int main()
{

    int n1, n2;
    scanf("%d %d", &n1, &n2);
    struct list *L1 = (struct list *)malloc(sizeof(struct list));
    struct list *L2 = (struct list *)malloc(sizeof(struct list));
    L1->head = NULL;
    L2->head = NULL;
    for (int i = 0; i < n1; i++)
    {
        char name[100];
        float cgpa;
        scanf("%s", name);
        scanf("%f", &cgpa);
        list_insert_tail(L1, create_record(name, cgpa));
    }
    for (int i = 0; i < n2; i++)
    {
        char name[100];
        float cgpa;
        scanf("%s", name);
        scanf("%f", &cgpa);
        list_insert_tail(L2, create_record(name, cgpa));
    }
    combine(L1, L2);

    struct record *ptr = L1->head;
    while (ptr != NULL)
    {
        printf("%s %0.2f\n", ptr->name, ptr->cgpa);
        ptr = ptr->next;
    }
    return 0;
}