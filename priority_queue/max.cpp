#include <bits/stdc++.h>
using namespace std;

int main()
{
    // for MAX heap
    priority_queue<int> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        pq.push(ele);
    }

    // for MIN heap

    // priority_queue<int, vector<int>, greater<int>> pqm;

    // pqm.push(10);
    // pqm.push(50);
    // pqm.push(20);

    // cout << pqm.top();
}