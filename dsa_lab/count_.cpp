#include <bits/stdc++.h>
using namespace std;
int findMax(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void count(int a[], int n)
{
    int i, j, *c, max;
    max = findMax(a, n);
    c = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    i = 0, j = 0;
    while (j < max + 1)
    {
        if (c[j] > 0)
        {
            a[i++] = j;
            c[j]--;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int a[] = {11, 32, 35, 79, 33, 92, 42};

    int n = sizeof(a) / sizeof(a[0]);
    count(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}





