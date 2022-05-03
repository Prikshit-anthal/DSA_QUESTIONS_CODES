#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        bool visited[V] = {false};
        queue<int> q;
        vector<int> bfs;

        // for all nodes if even in different components
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                // bfs.push_back(i);
                q.push(i);
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    visited[curr] = true;

                    for (int j = 0; j < adj[curr].size(); j++)
                    {
                        if (visited[adj[curr][j]] == false)
                        {
                            q.push(adj[curr][j]);
                            visited[adj[curr][j]] = true;
                        }
                    }

                    // q.push_back();
                    bfs.push_back(curr);
                }
            }
        }

        return bfs;
    }
};

int main()
{

    return 0;
}