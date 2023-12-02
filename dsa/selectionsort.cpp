#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{

    for (int i = 0; i <= n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int k = arr[j];
                arr[j] = arr[i];
                arr[i] = k;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionsort(arr, n);
    return 0;
}