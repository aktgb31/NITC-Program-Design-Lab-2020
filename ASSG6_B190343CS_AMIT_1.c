#include <stdio.h>
#include <stdlib.h>

//Structure for each node in linkedlist
struct node
{
    int key;
    struct node *next;
};

//The Linkedlist
struct list
{
    struct node *head;
};

//Create node for the linkedlist
struct node *create_node(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

//Search the list with key
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

//Insert a node in the front of a list
void list_insert_front(struct list *L, struct node *temp)
{
    temp->next = L->head;
    L->head = temp;
}

//Insert a node in the end of a list
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
    }
}

void list_insert_after(struct list *L, struct node *x, struct node *y)
{
    x->next = y->next;
    y->next = x;
}
void list_insert_before(struct list *L, struct node *x, struct node *y)
{
    if (y == L->head)
    {
        list_insert_front(L, x);
        return;
    }
    struct node *temp2, *temp1 = L->head;
    while (temp1 != y)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = x;
    x->next = temp1;
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
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *ptr = temp->next;
        temp->next = NULL;
        printf("%d\n", ptr->key);
        free(ptr);
    }
}
void list_delete(struct list *L, struct node *x)
{
    if (L->head == NULL || x == NULL)
    {
        printf("-1\n");
    }
    else if (x == L->head)
    {
        list_delete_initial(L);
    }
    else if (x->next == NULL)
    {
        list_delete_last(L);
    }
    else
    {
        struct node *ptr, *temp = L->head;

        while (temp != x)
        {
            temp = temp->next;
            ptr = temp;
        }
        ptr->next = x->next;
        free(x);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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