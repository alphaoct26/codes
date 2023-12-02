#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                // int b = arr[parent];
                // arr[parent] = arr[index];
                // arr[index] = b;
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout << "Heap elements: ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "Heap is Empty" << endl;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftidx = 2 * i;
            int rightidx = 2 * i + 1;

            if (leftidx < size && arr[i] < arr[leftidx])
            {
                swap(arr[i], arr[leftidx]);
                i = leftidx;
            }
            else if (rightidx < size && arr[i] < arr[rightidx])
            {
                swap(arr[i], arr[rightidx]);
                i = rightidx;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[i] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[i] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapsort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

void printheap(int arr[], int size)
{
    cout << "Heapified Array: ";
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    heap h;
    h.insert(20);
    h.insert(33);
    h.insert(22);
    h.insert(77);
    h.insert(46);
    h.insert(12);
    h.print();

    h.deletefromheap();
    h.print();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
    printheap(arr, size);

    heapsort(arr, size);
    printheap(arr, size);

    return 0;
}
