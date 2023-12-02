#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank

{
    char CID[50];
    char name[50];
    char address[50];
    char desiganation[50];
    int salary;
} c[2];

void input_details()
{
    FILE *ptr;
    ptr = fopen("bank.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        printf("Enter customer ID: ");
        gets(c[i].CID);
        fflush(stdin);
        printf("\n");

        printf("Enter the name of customer: ");
        gets(c[i].name);
        fflush(stdin);
        printf("\n");

        printf("Enter the address of customer: ");
        gets(c[i].address);
        fflush(stdin);
        printf("\n");

        printf("Enter the designation of customer: ");
        gets(c[i].desiganation);
        fflush(stdin);
        printf("\n");

        printf("Enter the salary of customer: ");
        scanf("%d", c[i].salary);
        fflush(stdin);
        printf("\n");

        fprintf(ptr, "CID: %s\n NAME: %s\n Address: %s\n Designation: %s\n SALARY: %d\n\n", c[i].CID, c[i].name, c[i].address, c[i].desiganation, c[i].salary);
    }

    fclose(ptr);
}

int avg_salary()
{
    FILE *fp;
    fp = fopen("bank.txt", "r");
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s%s%s%s%d", &c[i].CID, &c[i].name, &c[i].address, &c[i].desiganation, &c[i].salary);
        sum += c[i].salary;
    }
    printf("Average salary of the customers are: %d", sum / 5);
    fclose(fp);
}

void search_customer()
{
    char name[50];
    printf("ENter the name of the customer whose details you want to search: ");
    gets(name);
    fflush(stdin);
    FILE *fp;
    fp = fopen("bank.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", c->name);
        if (strcmp(name, c->name) == 0)
        {
            fscanf(fp, "%d%s%s%d", &c->CID, c->address, c->desiganation, &c->salary);

            printf("Customer ID: %d\n Name: %s\n Address: %s\n Designation: %s\n Salary: %d\n\n", c->CID, c->name, c->address, c->desiganation, c->salary);
        }
    }
    fclose(fp);
}
int main()
{
    input_details();
    avg_salary();
    search_customer();
}