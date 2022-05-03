#include <bits/stdc++.h>
using namespace std;

// o(v+e)
void MODIFIED_BFS(vector<int> adj[], int V, int s, int dist[])
{
    // seee no external loop here as singlr source shortest distance

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < adj[curr].size(); i++)
        {
            if (dist[adj[curr][i]] > (dist[curr] + 1))
            {
                dist[adj[curr][i]] = dist[curr] + 1;
                q.push(adj[curr][i]);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    MODIFIED_BFS(adj, V, 0, dist);

    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}

// O/P: 0 1 1 2