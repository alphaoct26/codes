#include <stdio.h>
int count_of_posnum(int arr[10])
{
    int pos_num = 0, i;
    for (i = 0; i <= 10; i++)
    {
        if (arr[i] > 0)
        {
            pos_num++;
        }
    }
}
int count_of_nevnum(int arr[10])
{
    int nev_num = 0, i;
    for (i = 0; i <= 10; i++)
    {
        if (arr[i] < 0)
        {
            nev_num++;
        }
    }
}

int main()
{
    int arr[10] = {21, -3, 4, -5, 6, 7, 34, -4323, -23, 27};
    count_of_posnum;
            
    printf("the positive num in array : %d", count_of_nevnum(int arr));

    return 0;
}