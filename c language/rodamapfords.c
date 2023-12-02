#include <stdio.h>
#include <math.h>
#include <string.h>

#define maxArrsize 100
void Array();
void displayArray(int Csize, int a[]);
void operation(int Csize, int a[]);
void insertEnd(int Csize, int a[]);
void insertPos(int Csize, int a[]);
void deleteEnd(int Csize, int a[]);
void deletepos(int Csize, int a[]);
void findMax(int Csize, int a[]);
void findMin(int Csize, int a[]);
void reverse(int Csize, int a[]);

void reverse(int Csize, int a[]) // reverse of an array
{
    int temp, i;
    for (i = 0; i = Csize / 2; i++)
    {
        temp = a[i];
        a[i] = a[Csize - i - 1];
        a[Csize - i - 1] = temp;
    }
    displayArray(Csize, a);
}

void findMin(int Csize, int a[]) // finidng min val
{
    int min, i;
    min = a[0];
    for (i = 1; i < Csize; i++)
    {
        if (min > a[i])
            min = a[i];
    }
    printf("Minimum element of array is : %d ", min);
    operation(Csize, a);
}

void findMax(int Csize, int a[]) // finding max val
{
    int max, i;
    max = a[0];
    for (i = 1; i < Csize; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    printf("Maximum element of array is : %d ", max);
    operation(Csize, a);
}

void deletepos(int Csize, int a[]) // delecting postion
{
    int pos, i;
    printf("\nEnter the position of element which you want to delete : ");
    scanf("%d", &pos);
    for (i = pos - 1; i < Csize - 1; i++)
    {
        a[i] = a[i + 1];
    }
    Csize--;
    displayArray(Csize, a);
}

void deleteEnd(int Csize, int a[]) // deleting element at end
{
    Csize--;
    displayArray(Csize, a);
}

void insertPos(int Csize, int a[]) // insertingpostion
{
    int i, ind, pos, val; // here pos=position of element in ar
    printf("\nEnter the position of element in the Array :");
    scanf("%d", &pos);
    printf("\nEnter the value of element which you want to insert :");
    scanf("%d", &val);
    for (i = Csize - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = val;
    Csize++;
    displayArray(Csize, a);
}

void insertEnd(int Csize, int a[])
{
    int ind = Csize, val; // ind=index value of element
    printf("\nEnter the element which you want to add :");
    scanf("%d", &val);
    a[ind] = val;
    Csize++;
    displayArray(Csize, a);
}

void operation(int Csize, int a[])
{
start:
    printf("\nOPERATIONS :-");
    printf("\n1.Diplay array");
    printf("\n2.Insert element at end");
    printf("\n3.Insert element at position");
    printf("\n4.Delete element at end");
    printf("\n5.Delete element at position");
    printf("\n6.Find Minimum element");
    printf("\n7.Find Maximum element");
    printf("\n8.Reverse Array");
    printf("\n9.Sort array in ascending order");
    printf("\n10.Sort array in descending order");
    printf("\n11.");
    printf("\nChoose operation which you want to empelement :-");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        displayArray(Csize, a);
        break;
    }
    case 2:
    {
        insertEnd(Csize, a);
        break;
    }
    case 3:
    {
        insertPos(Csize, a);
        break;
    }
    case 4:
    {
        deleteEnd(Csize, a);
        break;
    }
    case 5:
    {
        deletepos(Csize, a);
        break;
    }
    case 6:
    {
        findMin(Csize, a);
        break;
    }
    case 7:
    {
        findMax(Csize, a);
        break;
    }
    case 8:
    {
        reverse(Csize, a); //***********
        break;
    }
    case 9:
    {

        break;
    }
    case 10:
    {

        break;
    }
    case 11:
    {

        break;
    }
    case 12:
    {
    default:
        printf("\nInvalid Input. Try Again");
        goto start;
        break;
    }
    }
}
void displayArray(int Csize, int a[])
{
    int i;
    printf("\nArray elements are :-\n");
    for (i = 0; i < Csize; i++)
    {
        printf("%d ", a[i]);
    }
    operation(Csize, a);
}
void Array()
{
    int i, Csize, a[maxArrsize];
    printf("\nEnter the size of array :");
    scanf("%d", &Csize);
    printf("\nEnter the element of array :-\n");
    for (i = 0; i < Csize; i++)
    {
        printf("Enter %d element :", i + 1);
        scanf("%d", &a[i]);
    }
    displayArray(Csize, a);
}

// insertAtEnd();
int main()
{
    printf("Data Structures/n");
    printf("\n1.Array");
    printf("\n2.Linked List");
    printf("\n3.Stack");
    printf("\n4.Queue");
    printf("\n5.Graph");
    printf("\n6.Tree");
    printf("\nExit");
start:
    printf("\nWhich Data structure you want to use :-");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        Array();
        break;
    }

    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    case 4:
    {
        break;
    }

    case 5:
    {
        break;
    }

    case 6:
    {
        break;
    }

    case 7:
    {
        printf("\nThankyou");
        break;
    }
    default:
    {
        printf("Invalid input\nTry again");
        goto start;
    }
    }
    return 0;
}