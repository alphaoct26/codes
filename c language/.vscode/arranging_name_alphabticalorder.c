// arranging name in alphabetical order
#include <stdio.h>
#include <string.h>
int main()
{
    char str[];                                                                                                                           
    char *p;
    printf("enter the 4 name and result will be  in  alphabetical  order ");
    scanf("%s", str);
    int i, j;
    for (i = 0; i < !0; i++)
    {
        for (j = i + 1; j < !0; j++)
        {
            if ((strcmp(str[i], str[j])) > 0)
            {
                p = str[i];
                str[i] = str[j];
                str[j] = p;
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        printf("%s\t\t", str[i]);
    }
    return 0;
}