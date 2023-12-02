#include <iostream>
using namespace std;

// min and max val<<<<<
int min(int arr1[], int n)
{
    int max = arr1[0];
    int min = arr1[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr1[i])
        {
            max = arr1[i];
        }
        if (min > arr1[0])
        {
            min = arr1[0];
        }
    }
    cout << min << "";
    cout << "\t";
    cout << max << "";
    cout << "\n";
}

// sum of array<<<<<

int sum(int arr1[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i];
    }
    cout << sum << "\npresent in index"
         << "\t";
}
// linear search elments in array <<<<
bool linearsearch(int arr1[], int n, int searchnum)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] == searchnum)
        {
            cout << i << "\n";
        }
        cout << "\n";
    }
    return 0;
}
// reverse an array <<<<
int revese(int arr1[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        swap(arr1[s], arr1[e]);
        s++;
        e--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << "\n";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr1[n];
    int searchnum;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    min(arr1, n);
    sum(arr1, n);
    cout << "\n";

    cout << "num you want to search"
         << "\n";
    cin >> searchnum;
    linearsearch(arr1, n, searchnum);
    revese(arr1, n);

    return 0;
}