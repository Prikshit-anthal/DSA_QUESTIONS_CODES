#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // code here
        // step 1 topop sort
        stack<int> s;
        bool visited[V] = {false};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                topo_dfs(V, adj, i, -1, s, visited);
        }

        // step 2 reverse
        vector<int> rev_adj[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                rev_adj[adj[i][j]].push_back(i);
        }

        

        // step 3 dfs acc to topo
        for (int i = 0; i < V; i++)
            visited[i] = false;

        int count = 0;
        int N = s.size();
         for (int i = 0; i < N; i++)
        {
            int top = s.top();
            s.pop();
            if (!visited[top])
            {
                dfs(V, rev_adj, top, -1, visited);
                // cout << endl;
                count++;
            }
        }
        return count;
    }
    void topo_dfs(int V, vector<int> adj[], int u, int p, stack<int> &s, bool visited[])
    {
        visited[u] = true;
        for (auto itr : adj[u])
        {
            if (itr == p)
                continue;
            if (visited[itr] == false)
            {
                topo_dfs(V, adj, itr, u, s, visited);
            }
        }
        s.push(u);
    }

    void dfs(int V, vector<int> adj[], int u, int p, bool visited[])
    {

        // cout << u << " ";
        visited[u] = true;
        for (auto itr : adj[u])
        {
            if (itr == p)
                continue;
            if (!visited[itr])
                dfs(V, adj, itr, u, visited);
        }
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 3,1);
    addEdge(adj, 2, 0);
    // addEdge(adj, 1, 3);

    Solution obj;
    cout << obj.kosaraju(V, adj) << endl;

    return 0;
}
