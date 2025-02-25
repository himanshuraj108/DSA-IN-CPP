#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{

    set<int> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        s.insert(ele);
    }

    // This is the for each loop
    for (auto x : s)
    {
        cout << x << " ";
    }
}
