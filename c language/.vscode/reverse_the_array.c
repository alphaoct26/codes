#include <stdio.h>
int main()
{
    int arr1[6], i;
    printf("enter the elments");
    for (i = 0; i <= 6; i++)
    {
        scanf("%d\n", &arr1[i]);
    }
    for (i = 6; i >= 0; i--)
    { 
        printf("%d\n",arr1[i]);
    }
    // for(i=0;j=4;i<=4;i++;j--)
    // printf()

    return 0;
}