#include <bits/stdc++.h>
using namespace std;

void dfs_helper(vector<int> adj[], int V, int u, int p, int time[], int low[], bool visited[], int &timer);

void find_bridges(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    int time[V] = {0}, low[V] = {0};
    int timer = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            dfs_helper(adj, V, i, -1, time, low, visited, timer);
        }
    }
}

void dfs_helper(vector<int> adj[], int V, int u, int p, int time[], int low[], bool visited[], int &timer)
{
    timer++;
    time[u] = low[u] = timer;
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] == p)
            continue;

        if (visited[adj[u][i]] == false)
        {
            dfs_helper(adj, V, adj[u][i], u, time, low, visited, timer);
            low[u] = min(low[u], low[adj[u][i]]);
            if (low[adj[u][i]] > time[u])
                cout << u << " " << adj[u][i] << endl;
        }
        else
        {
            low[u] = min(low[u], time[adj[u][i]]);
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
    // addEdge(adj, 1, 3);

    find_bridges(adj, V);

    return 0;
}