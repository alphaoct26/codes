#include <stdio.h>
#include <string.h>
int main()
{
    char *str[] = {
        "i want to tell you something ",
        " yeah , whats that ",
        " i love you ",
        "i think i am falling your presence makes me ... means i cant explain but i have strong felling for you"
    } ;
    char str1[50];
    char *p;
    printf("enter the word you want to search ");
    scanf("%s", str1);
    p = "\0";

    for (int i = 0; i < 4; i++)
    {
        p = strstr(str[i], str1);// strstr function use for searching one string on string 
        if (p !="\0")
        {
            printf("%s found in [the dialogue]", str1);
            return 0;
        }
    }
    printf("%s not found in sring", str1);

    return 0;
}