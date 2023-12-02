// write a program to extract a string from substring //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char srt[20], substr[20];
    int pos, n;
    int *a, *b;
    a = srt;
    b = substr;

    printf("enter the string :");
    scanf("%s", srt);
    printf("to print specific char \n enter position: \n enter the lenght you want to print:");
    scanf("%d%d", &pos, &n);
    if (pos < 0 || pos > strlen(srt))
    {
        printf("improper positon value ");
        exit(1);
    }

    if (n > strlen(srt))
        n = n - strlen(srt) - 1;
    a = a + pos;
    for (int i = 0; i < n; i++)
    {
        *a = *b;
        a++;
        b++;
    }

    *b = '\0';

    printf("the sub string is :%s\n", substr);
    return 0;
}