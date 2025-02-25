#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
vector<bool> visited;

void dfs(int curr)
{
    cout << curr << " ";
    visited[curr] = true;
    for (auto neighbour : graph[curr])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    graph.resize(v);
    visited.resize(v, false);

    while (e--)
    {
        int s, d;
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s); // For an undirected graph
    }

    int startVertex;
    cin >> startVertex;

    for (int i = 0; i < v; i++)
    {
        graph[i].sort(); // Ensures consistent traversal order
    }

    cout << "Depth First Traversal starting from vertex " << startVertex << ":" << endl;
    dfs(startVertex);
    cout << endl;

    return 0;
}
