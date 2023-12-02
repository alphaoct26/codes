#include <stdio.h>
int main()
{
    int num[] = {1, 23, 34, 4, 56, 67, 7, 7};
    int n, i, count;
    printf("\n enter am element to serach ");
    scanf("%d", &n);
    count = 0;
    for (i = 0; i <= 9; i++)
    {
        if (num[i] == n)
        {
            count++;
            printf("num %d is found %d time in the array", n, count);
        }
        else if (num[i]!=n)

        { count++;
            printf("num %d is found not in the array", n);
        }
    }
    return 0;
}