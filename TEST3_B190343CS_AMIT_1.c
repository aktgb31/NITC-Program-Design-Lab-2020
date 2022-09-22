#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define high 2
#define medium 1
#define low 0

struct pcb
{
    int process_id;
    int priority;
    struct pcb *next;
};
int get_process_id(int p_id[])
{
    for (int i = 1; i <= 1000; i++)
    {
        if (p_id[i] == 0)
            return i;
    }
    return -1;
}
int get_priority(char p[])
{
    if (strcmp(p, "high") == 0)
        return high;
    if (strcmp(p, "medium") == 0)
        return medium;
    if (strcmp(p, "low") == 0)
        return low;
}
struct pcb *create_pcb(int k, int p)
{
    struct pcb *temp = (struct pcb *)malloc(sizeof(struct pcb));
    temp->process_id = k;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}
void list_processes(struct pcb *L)
{
    if (L == NULL)
        printf("-1\n");
    else
    {
        struct pcb *temp = L;
        while (temp != NULL)
        {
            printf("%d ", temp->process_id);
            temp = temp->next;
        }
        printf("\n");
    }
}

void update_state(int k, struct pcb **L1, struct pcb **L2)
{
    struct pcb *temp = *L1;
    struct pcb *prev = NULL;
    while (temp != NULL)
    {
        if (temp->process_id == k)
            break;
        prev = temp;
        temp = temp->next;
    }
    if (temp == *L1)
    {
        (*L1) = (*L1)->next;
        temp->next = NULL;
    }
    else
    {
        prev->next = temp->next;
        temp->next = NULL;
    }

    struct pcb *t = *L2;
    prev = NULL;
    while (t != NULL)
    {
        if (temp->priority > t->priority)
            break;
        prev = t;
        t = t->next;
    }
    if (t == NULL && prev != NULL)
    {
        prev->next = temp;
        temp->next = NULL;
    }
    else if (t == NULL && prev == NULL)
    {
        *L2 = temp;
        temp->next = NULL;
    }
    else
    {
        prev->next = temp;
        temp->next = t;
    }
}

void schedule(struct pcb **p, struct pcb **R)
{
    if (*R == NULL)
    {
        printf("-1\n");
        return;
    }
    struct pcb *i = *R;
    *R = (*R)->next;
    if (*p != NULL)
    {
        struct pcb *temp = *p;
        struct pcb *t = *R;
        struct pcb *prev = NULL;
        while (t != NULL)
        {
            if (temp->priority > t->priority)
                break;
            prev = t;
            t = t->next;
        }
        if (t == NULL && prev != NULL)
        {
            prev->next = temp;
            temp->next = NULL;
        }
        else if (t == NULL && prev == NULL)
        {
            *R = temp;
            temp->next = NULL;
        }
        else
        {
            prev->next = temp;
            temp->next = t;
        }
        *p = NULL;
    }
    *p = i;
    (*p)->next = NULL;
}
int main()
{
    //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p_id[1001];
    for (int i = 0; i < 1001; i++)
    {
        p_id[i] = 0;
    }
    char choice;
    struct pcb *N, *R, *T, *W, *p;
    p = N = R = W = T = NULL;
    while (scanf("%c", &choice) && choice != 'e')
    {
        // printf("choice= %c\n", choice);
        switch (choice)
        {
        case 'c':
        {
            int k = get_process_id(p_id);
            p_id[k] = 1;
            char priority[10];
            scanf(" %s", priority);
            // printf("priority= %s\n", priority);
            struct pcb *temp = create_pcb(k, get_priority(priority));
            //    printf("%d %d\n", temp->process_id, temp->priority);
            if (N == NULL)
            {
                N = temp;
            }
            else
            {
                struct pcb *t = N;
                while (t->next != NULL)
                {
                    t = t->next;
                }
                t->next = temp;
            }
            //  printf("N %d\n", N->process_id);
        }
        break;
        case 'l':
        {
            int i;
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                list_processes(N);
                break;
            case 2:
                list_processes(R);
                break;
            case 3:
                list_processes(W);
                break;
            case 4:
                list_processes(T);
                break;
            default:
                break;
            }
        }
        break;
        case 'u':
        {
            int k;
            char s1[15], s2[15];
            scanf("%d%s%s", &k, s1, s2);
            //printf("%d %s %s", k, s1, s2);
            if (strcmp(s1, "running") == 0 && strcmp(s2, "waiting") == 0)
            {
                struct pcb *temp = p;
                if (W == NULL)
                {
                    W = temp;
                }
                else
                {
                    struct pcb *t = W;
                    while (t->next != NULL)
                    {
                        t = t->next;
                    }
                    t->next = temp;
                }
                p = NULL;
                schedule(&p, &R);
            }
            else if (strcmp(s1, "new") == 0 && strcmp(s2, "ready") == 0)
            {
                update_state(k, &N, &R);
            }
            else if (strcmp(s1, "waiting") == 0 && strcmp(s2, "ready") == 0)
            {
                update_state(k, &W, &R);
            }
        }
        break;
        case 's':
        {
            schedule(&p, &R);
        }
        break;
        case 'e':
        {
            printf("%d\n", p->process_id);
            {
                if (T == NULL)
                {
                    T = p;
                }
                struct pcb *i = T;
                struct pcb *prev;
                while (i != NULL)
                {
                    if (p->process_id > i->process_id)
                    {
                        break;
                    }
                    prev = i;
                    i = i->next;
                }
                if (i == NULL)
                {
                    prev->next = p;
                }
                else if (i == T)
                {
                    p->next = T;
                    T = p;
                }
                else
                {
                    p->next = i;
                    prev->next = p;
                }
            }
            p = NULL;
            schedule(&p, &R);
        }
        }
    }
    return 0;
}