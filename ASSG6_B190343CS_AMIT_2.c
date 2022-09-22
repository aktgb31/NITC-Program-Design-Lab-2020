#include <stdlib.h>
#include <stdio.h>

struct node
{
    int key;
    struct node *next, *prev;
};
struct list
{
    struct node *head;
};

struct node *create_node(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
struct node *list_search(struct list *L, int key)
{
    struct node *temp = L->head;
    while (temp != NULL)
    {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}
void list_insert_front(struct list *L, struct node *temp)
{
    if (L->head == NULL)
    {
        L->head = temp;
    }
    else
    {
        temp->next = L->head;
        L->head->prev = temp;
        L->head = temp;
    }
}
void list_insert_tail(struct list *L, struct node *temp)
{

    if (L->head == NULL)
    {
        L->head = temp;
    }
    else
    {
        struct node *t = L->head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
    }
}
void list_insert_after(struct list *L, struct node *x, struct node *y)
{
    if (L->head != NULL && y != NULL)
    {
        x->prev = y;
        y->next->prev = x;
        x->next = y->next;
        y->next = x;
    }
}
void list_insert_before(struct list *L, struct node *x, struct node *y)
{
    if (L->head != NULL && y == L->head)
    {
        x->next = y;
        y->prev = x;
        L->head = x;
    }
    else if (L->head != NULL && y != NULL)
    {
        x->prev = y->prev;
        y->prev->next = x;
        x->next = y;
        y->prev = x;
    }
}

void list_delete(struct list *L, struct node *x)
{
    if (L->head == NULL || x == NULL)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", x->key);
        if (L->head == x)
        {
            L->head = x->next;
        }
        if (x->next != NULL)
        {
            x->next->prev = x->prev;
        }
        if (x->prev != NULL)
        {
            x->prev->next = x->next;
        }
        free(x);
    }
}

void list_delete_initial(struct list *L)
{
    if (L->head == NULL)
    {
        printf("-1\n");
    }
    else
    {
        struct node *temp = L->head;
        if (L->head->next == NULL)
        {
            L->head = NULL;
        }
        else
        {
            L->head = L->head->next;
            L->head->prev = NULL;
        }
        printf("%d\n", temp->key);
        free(temp);
    }
}
void list_delete_last(struct list *L)
{
    if (L->head == NULL)
    {
        printf("-1\n");
    }
    else if (L->head->next == NULL)
    {
        struct node *temp = L->head;
        L->head = NULL;
        printf("%d\n", temp->key);
        free(temp);
    }
    else
    {
        struct node *temp = L->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        struct node *ptr = temp->prev;
        ptr->next = NULL;
        printf("%d\n", temp->key);
        free(temp);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char choice;
    struct list *L = (struct list *)malloc(sizeof(struct list));
    L->head = NULL;
    while (scanf("%c", &choice) && choice != 'e')
    {
        switch (choice)
        {
        case 'f':
        {
            int key;
            scanf("%d", &key);
            list_insert_front(L, create_node(key));
        }
        break;
        case 't':
        {
            int key;
            scanf("%d", &key);
            list_insert_tail(L, create_node(key));
        }
        break;
        case 'a':
        {
            int key1, key2;
            scanf("%d%d", &key1, &key2);
            list_insert_after(L, create_node(key1), list_search(L, key2));
        }
        break;
        case 'b':
        {
            int key1, key2;
            scanf("%d%d", &key1, &key2);
            list_insert_before(L, create_node(key1), list_search(L, key2));
        }
        break;
        case 'd':
        {
            int key;
            scanf("%d", &key);

            list_delete(L, list_search(L, key));
        }
        break;
        case 'i':
        {
            list_delete_initial(L);
        }
        break;
        case 'l':
        {
            list_delete_last(L);
        }
        break;
        case 's':
        {
            int key;
            scanf("%d", &key);
            if (list_search(L, key) != NULL)
            {
                printf("1\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        break;
        }
    }
    return 0;
}