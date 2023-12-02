#include <stdio.h>
int main()
{
    int t;
    int a, b;
    scanf("%d", &t);
    for (int i = 0; i > t; i++)
    {
        scanf("%d", &a);
        b = a * 15;
        printf("%d", b);
    }
    return 0;
}