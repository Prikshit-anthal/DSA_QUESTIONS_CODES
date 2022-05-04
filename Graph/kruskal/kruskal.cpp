#include <bits/stdc++.h>
using namespace std;

// disjoint set

class Solution
{
    vector<int> parent, rank;

public:
    void makeSet(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i), rank.push_back(0);
    }

    int findParent(int v)
    {
        if (v == parent[v])
            return v;

        // compression done here
        return parent[v] = findParent(parent[v]);
    }

    void _union(int u, int v)
    {
        // imp parents find pehle then jodo
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (rank[uParent] > rank[vParent])
        {
            parent[vParent] = uParent;
        }
        else if (rank[vParent] > rank[uParent])
        {
            parent[uParent] = v;
        }
        else
        {
            parent[vParent] = uParent;
            rank[uParent]++; // rank increased here
        }
    }
};

struct node
{
    int w, u, v;
};

bool comp(struct node u, struct node v)
{
    return u.w < v.w;
}

// kruskal
void kruskal(vector<pair<int, int>> adj[], int V)
{
    vector<node> edges;
    Solution obj;
    obj.makeSet(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            struct node temp = {adj[i][j].second, i, adj[i][j].first};
            edges.push_back(temp);
        }
    }

    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < edges.size(); i++)
    {

        if (obj.findParent(edges[i].u) != obj.findParent(edges[i].v))
        {
            obj._union(edges[i].u, edges[i].v);
            cout << "Edge taken " << edges[i].u << " " << edges[i].v << " " << edges[i].w << endl;
        }
    }
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
int main()
{
    int V = 4;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 0, 2, 7);
    addEdge(adj, 1, 3, 6);

    kruskal(adj, V);

    return 0;
}