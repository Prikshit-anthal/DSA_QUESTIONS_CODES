#include <bits/stdc++.h>
using namespace std;

void dfs_helper(vector<int> adj[], int V, int u, int p, int time[], int low[], bool visited[], int &timer, vector<bool> &articulation);

vector<bool> find_articulation(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    vector<bool> articulation(V,false);
    int time[V] = {0}, low[V] = {0};
    int timer = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            dfs_helper(adj, V, i, -1, time, low, visited, timer, articulation);
        }
    }
    return articulation;
}

void dfs_helper(vector<int> adj[], int V, int u, int p, int time[], int low[], bool visited[], int &timer, vector<bool>&articulation)
{
    timer++;
    time[u] = low[u] = timer;
    visited[u] = true;
    int child = 0;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] == p)
            continue;

        if (visited[adj[u][i]] == false)
        {
            child++;
            dfs_helper(adj, V, adj[u][i], u, time, low, visited, timer,articulation);
            low[u] = min(low[u], low[adj[u][i]]);
            if (low[adj[u][i]] >= time[u] && p!=-1)
                articulation[u]=true;
        }
        else
        {
            low[u] = min(low[u], time[adj[u][i]]);
        }

    }
    if (p == -1 && child > 1)
        articulation[u] = true;
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

    vector<bool> articulation = find_articulation(adj, V);
    for(auto itr:articulation)
    cout<<itr<<endl;
    return 0;
}