#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x, y) ((x > y) ? x : y)
struct employee
{
    char name[100];
    int salary;
    int work_per_day;
    int cleave;
};
void insert(struct employee record[], int size)
{
    scanf("%[^\n]", record[size - 1].name);
    scanf(" %d", &record[size - 1].salary);
    scanf("%d", &record[size - 1].work_per_day);
    if (record[size - 1].work_per_day == 8)
    {
        record[size - 1].salary += 50;
    }
    else if (record[size - 1].work_per_day == 10)
    {
        record[size - 1].salary += 100;
    }
    else if (record[size - 1].work_per_day > 10)
    {
        record[size - 1].salary += 150;
    }
}
void print_noincrement(struct employee record[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (record[i].work_per_day < 8)
        {
            printf("%s %d\n", record[i].name, record[i].salary);
        }
    }
}
void print_finalsalary(struct employee record[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s %d\n", record[i].name, record[i].salary);
    }
}
void print_workperday(struct employee record[], int size, int t)
{
    for (int i = 0; i < size; i++)
    {
        if (record[i].work_per_day == t)
        {
            printf("%s %d\n", record[i].name, record[i].salary);
        }
    }
}
int computeDeductions(struct employee record[], int size, char name[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(record[i].name, name) == 0)
        {
            return 30000 - (1000 * MAX(0, 5 - record[i].cleave));
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char choice;
    int size = 0;
    struct employee record[10];
    while (scanf("%c", &choice) && choice != 't')
    {
        switch (choice)
        {
        case 'r':
        {
            size++;
            insert(record, size);
        }
        break;
        case 'i':
        {
            print_noincrement(record, size);
        }
        break;
        case 'f':
        {
            print_finalsalary(record, size);
        }
        break;
        case 'w':
        {
            int temp;
            scanf("%d", &temp);
            print_workperday(record, size, temp);
        }
        break;
        default:
            break;
        }
    }
}