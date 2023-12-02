/* A hospital keeps a file of blood donors in which each record has the format: Name:
20 Columns, Address: 40 Columns, Age: 2 Columns Blood Type: 1 Column (Type
1, 2, 3 or 4). Write a program to read the file and print a list of all blood donors
whose age is below 25 and blood is type 2.*/

#include <stdio.h>
#include <string.h>
struct hospital
{
    char name[10];
    int age[3];
    char blood_type[3];
    char Address[20];
} d;

enter_detail()
{
    FILE *ptr
        ptr = fopen("hospital.txt", "a");
    for (int i = 0; i < 5; i++)
    {
        char name[20], int age[3], char blood_type[3], char Address[20];
        printf("enter your name\n ");
        scanf("%s", b[i].name);
        printf("\nenter your age ");
        scanf("%s", b[i].age);
        printf("enter your blood group \n");
        scanf("%s", b[i].blood_type);
        printf("enter your address");
        scanf("%s", b[i].Address);
        fprint(ptr, "name:%s \n age:%s\n blood type:%s\n address:%s\n", d[i].name, d[i].age, d[i].blood_tpe, d[i].Address);
    }
    fclose(ptr);
}
age_below()
{
    FILE *ptr
        ptr = fopen("hospital.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(ptr, "%s%s%s%s", d[i].name, d[i].age, d[i].blood_type, d[i].Address);

        if (c[i].age < 25)
        {
            printf("\nname:%s \n age:%s\n blood type:%s\n address:%s\n", d[i].name, d[i].age, d[i].blood_type, d[i].Address);
        }
    }
}

int main()
{
    enter_detail();
    age_below();

    return 0;
}
