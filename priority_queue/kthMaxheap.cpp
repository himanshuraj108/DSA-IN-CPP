#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // kth smallest element
    int k = 3;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }

    cout << pq.top();
}