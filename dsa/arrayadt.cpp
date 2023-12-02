// – (1) Add an element to an array,
//(2) Delete an element from an array,
// (3)Find length of an array,//
// (4)Merge two arrays into a third array.
// Ensure that on initialization length of array is zero.
#include <iostream>
using namespace std;

int main()
{
    int csize;

    cout << "enter the size of array";
    cin >> csize;
    int arr[csize];
    for (int i = 0; i < csize; i++)
    {
        cin >> arr[i];
    }

    int ind = csize, val; // ind=index value of element
    cout << "enter the element ";
    cin >> val;
    arr[ind] = val;
    csize++;

    for (int i = 0; i < csize; i++)
    {
        cout << arr[i];
    }

    return 0;
}