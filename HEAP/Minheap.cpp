#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    int arr[50];
    int idx;

    MinHeap()
    {
        idx = 1;
    }

    int top()
    {
        return arr[1];
    }

    void push(int x)
    {
        arr[idx] = x;
        int i = idx;
        idx++;

        while (i != 1)
        {
            int parent = i / 2;
            if (arr[i] < arr[parent])
            {
                swap(arr[i], arr[parent]);
            }
            else
                break;
            i = parent;
        }
    }

    int size()
    {
        return idx - 1;
    }

    void pop()
    {
        idx--;
        arr[1] = arr[idx];
        int i = 1;
        while (true)
        {
            int left = 2 * i, right = 2 * i + 1;
            if (left > size()) // SIZE() fun CALLED
                break;

            else if (right > size()) // SIZE() fun CALLED
            {
            }

            else if (arr[left] < arr[right])
            {
                if (arr[i] > arr[left])
                {
                    swap(arr[i], arr[left]);
                    i = left;
                }
                break;
            }

            else
            {
                if (arr[i] > arr[right])
                {
                    swap(arr[i], arr[right]);
                    i = right;
                }
                break;
            }
        }
    }

    void display()
    {
        for (int i = 1; i < idx - 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MinHeap pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        pq.push(ele);
    }
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    pq.pop();
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
}