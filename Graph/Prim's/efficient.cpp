#include <bits/stdc++.h>
using namespace std;

void prims(vector<pair<int, int>> adj[], int V)
{
    int key_arr[V], parent_arr[V];
    bool MST_added[V];

    for (int i = 0; i < V; i++)
        key_arr[i] = 1e9, parent_arr[i] = -1, MST_added[i] = false;

    key_arr[0] = 0;
    parent_arr[0] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;
    for (int i = 0; i < V; i++)
        p_q.push({key_arr[i], i});

    for (int i = 0; i < V - 1; i++)
    {
        int min = 1e9, v = -1;

        // for (int j = 0; j < V; j++)
        // {
        //     if (MST_added[j] == false && key_arr[j] < min)
        //     {
        //         v = j;
        //         min = key_arr[j];
        //     }
        // }

        auto top = p_q.top();
        p_q.pop();
        v = top.second;
        MST_added[v] = true;

        for (int j = 0; j < adj[v].size(); j++)
        {
            int to_add = adj[v][j].first;

            if (MST_added[to_add] == false && key_arr[to_add] > adj[v][j].second)
            {

                key_arr[to_add] = adj[v][j].second;

                //one more line here
                p_q.push({adj[v][j].second,to_add});
                    parent_arr[to_add] = v;
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << key_arr[i] << " " << parent_arr[i] << " " << MST_added[i] << endl;
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

    prims(adj, V);

    return 0;
}