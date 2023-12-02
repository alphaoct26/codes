#include <bits/stdc++.h>
using namespace std;
int binary(int arr[], int size, int x)
{

    for (int i = 0; i < size; i++)
    {
        int m, l, r;
        r = size;
        l = 0;
        m = l + (r - 1) / 2;
        if (arr[m] = x)
        {
            return m;
        }
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    int size = 5;
    int x = 4;
    int result = binary(arr, 5, 4);
    if (result == -1)
    {
        cout << "not found ";
    }
    else
    {
        cout << "index is " << result << endl;
    }

    return 0;
}