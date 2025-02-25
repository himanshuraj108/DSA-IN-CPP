#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int idx = size;
        arr[idx] = val;

        while (idx > 1)
        {
            int parent = idx / 2;

            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }

            else
            {
                return;
            }
        }
    }
    void deleteRoot(int arr[], int &size)
    {
        if (size <= 0)
        {
            return;
        }

        else
        {
            arr[0] = arr[size - 1];
            size--;
            heapify(arr, size, 0);
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, i);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{

    // Heap heap;
    //  int n;
    //  cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     int ele;
    //     cin >> ele;
    //     heap.insert(ele);
    // }

    // cout << "Inserted: ";
    // heap.print();

    // cout << "Deleted: ";
    // heap.deleteHeap();
    // heap.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int m = 5;
    cout << "Heapified: ";
    for (int i = m / 2; i > 0; i--)
    {
        heapify(arr, m, i);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Heap Sorted: ";
    heapSort(arr, m);
    for (int i = 1; i <= m; i++)
    {
        cout << arr[i] << " ";
    }
}
