#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    char startstring[20] = "A";
    char endstring[20] = "B";
    for (int i = 0; i <= 8; i++)
    {

        strcat(str, endstring);
        strcpy(str, startstring);
        printf("%s\n", str);

        strcat(endstring, str);
        strcpy(startstring, str);
    }
    return 0;
}