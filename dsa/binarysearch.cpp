#include <iostream>
using namespace std;

void binarysearch(int arr[], int n, int sr)
{
    int s = 0;
    int e = n - 1;
    int mid;

    while (s <= e)
        for (int i = 0; i < n; i++)
        {
            mid = (s + e) / 2;
            if (arr[mid] == sr)
            {
                cout << "value :" << arr[mid] << endl;
                cout << "index:" << mid << endl;
                return;
            }

            if (arr[mid] < sr)
            {
                s = mid + 1;
            }
            else
            {
                s = mid - 1;
            }
        }
}

int main()
{
    int n, sr;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "enter the num you want to enter\n";
    cin >> sr;
    binarysearch(arr, n, sr);

    return 0;
}