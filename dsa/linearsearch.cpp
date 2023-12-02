#include <iostream>
using namespace std;

void linearsearch(int arr1[], int n, int searchnum)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] == searchnum)
        {
            cout << i << "\t";
            cout << "postion of element";
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "\n";
    int arr1[n];
    int searchnum;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "\n";

    cout << "num you want to search"
         << "\n";
    cin >> searchnum;
    linearsearch(arr1, n, searchnum);

    return 0;
}