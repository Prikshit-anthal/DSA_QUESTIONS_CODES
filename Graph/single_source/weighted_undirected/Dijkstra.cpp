// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here

        // min heap priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;

        vector<int> dist(V, 1e9);

        p_q.push({0, S});
        dist[S] = 0;

        while (!p_q.empty())
        {
            auto item = p_q.top();
            p_q.pop();

            for (auto itr : adj[item.second])
            {
                // cout<<dist[itr[0]]<<" "<<itr[1]<<endl;
                if (itr[1] + dist[item.second] < dist[itr[0]])
                {
                    dist[itr[0]] = itr[1] + dist[item.second];
                    p_q.push({itr[1], itr[0]});
                }
            }
        }

        return dist;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends