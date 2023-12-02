#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n)
{
    int high1, high2;
    if (arr[0] > arr[1])
    {
        high1 = arr[0];
        high2 = arr[1];
    }
    else
    {
        high1 = arr[1];
        high2 = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > high1)
        {
            high2 = high1;
            high1 = arr[i];
        }
        else if (arr[i] = high2 && arr[i] != high1)
        {
            high2 = arr[i];
        }
    }
    cout << high1 + high2 << endl;
    return 0;
}
int input(int arr[], int n)
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        input(arr, n);
    }
    sum(arr, n);
    return 0;
}
