#include <bits/stdc++.h>
using namespace std;

bool bipartite_bfs(int V, vector<int> adj[])
{
    // Code here
    int visited[V] = {0}; // 0->not visited yet  1->color1  2-> color 2
    queue<int> q;

    // for all nodes if even in different components
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            // bfs.push_back(i);
            q.push(i);
            visited[i] = 1;//initial color=1 for each individual component
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (int j = 0; j < adj[curr].size(); j++)
                {
                    if (visited[adj[curr][j]] == 0)
                    {
                        q.push(adj[curr][j]);
                        if (visited[curr] == 1) //if parent color=1
                            visited[adj[curr][j]] = 2;
                        else if (visited[curr] == 2)//if parent color=2
                            visited[adj[curr][j]] = 1;
                    }
                    else if (visited[adj[curr][j]] == visited[curr])
                    {
                        return (false);//parent cna child color same return false/break
                    }
                }
            }
        }
    }
    return true;
}

// bool dfs_helper(int v, int V, int color, int p, vector<int> adj[], int visited[]);

// dfs cycle checker
bool dfs_helper(int v, int V, int color, int p, vector<int> adj[], int visited[])
{
    // cout<<v<<" "<<p<<endl;
    if (visited[v] == 0) // not visited ab color do
        visited[v] = color;
    else if (visited[v] != color) // already visited with opp color not desirable
    {
        // cout<<"   "<<v<<" im done  "<<p<<endl;
        return false;
    }
    else
    {
        // it means ki color shi tha toh aage check ki zrurat nai kyunki vo already checked hai
        // to prevent infinigte loop
        return true;
    }

    for (int i = 0; i < adj[v].size(); i++)
    {
        if (adj[v][i] != p)
        {

            bool result = dfs_helper(adj[v][i], V, color == 1 ? 2 : 1, v, adj, visited);
            // cout<<result<<"  res "   <<endl;
            if (result == false)
                return (false);
        }
    }
    return true;
}

bool bipartite_dfs(int V, vector<int> adj[])
{
    int visited[V] = {0}; // same color and visited scheme
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            int color = 1; // color for ech individual component starting

            // sending color mtlb jo bhi child hai unka yehi color hona chaiye
            // agar ulta toh false/break agar 0 toh visit krke yeh color kr do

            bool res = dfs_helper(i, V, color, -1, adj, visited);
            if (res == false)
                return false;
        }
    }
    return true;
}

// dfs finished

int main()
{

    int V = 9, V1 = 3, V2 = 5;
    vector<int> adj[V], adj1[3], adj2[5];
    // one graph bipartite
    adj[0].push_back(1);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(5);

    adj[2].push_back(1);
    adj[2].push_back(3);

    adj[3].push_back(2);
    adj[3].push_back(4);

    adj[4].push_back(3);
    adj[4].push_back(8);

    adj[5].push_back(1);
    adj[5].push_back(6);

    adj[6].push_back(5);
    adj[6].push_back(7);

    adj[7].push_back(6);
    adj[7].push_back(8);

    adj[8].push_back(7);
    adj[8].push_back(4);
    // end

    cout << bipartite_bfs(V, adj) << ' ' << bipartite_dfs(V, adj) << endl;

    // start linear 3 graph bipartite

    adj1[0].push_back(1);

    adj1[1].push_back(0);
    adj1[1].push_back(2);

    adj1[2].push_back(1);

    cout << " " << bipartite_bfs(V1, adj1) << ' ' << bipartite_dfs(V1, adj1) << endl;

    // new graph not bipartite
    adj2[0].push_back(1);
    adj2[0].push_back(2);

    adj2[1].push_back(0);
    adj2[1].push_back(2);
    adj2[1].push_back(3);

    adj2[2].push_back(0);
    adj2[2].push_back(1);
    adj2[2].push_back(4);

    adj2[3].push_back(1);
    adj2[3].push_back(4);

    adj2[4].push_back(3);
    adj2[4].push_back(2);
    // end

    cout << ' ' << bipartite_bfs(V2, adj2) << ' ' << bipartite_dfs(V2, adj2) << endl;

    return 0;
}