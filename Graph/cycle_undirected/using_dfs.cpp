class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        // DFS start
        bool visited[V] = {false};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                bool res = dfs_cycle_checker(i, V, -1, adj, visited);
                if (res == true)
                    return true;
            }
        }
        return false;
    }

    // dfs cycle checker
    bool dfs_cycle_checker(int v, int V, int p, vector<int> adj[], bool visited[])
    {
        // cout<<v<<" "<<p<<endl;
        if (visited[v] == true)
        {
            return true;
        }
        visited[v] = true;

        for (int i = 0; i < adj[v].size(); i++)
        {
            if (adj[v][i] != p)
            {
                //  p=v;  and another galti dont change parent loop main p change ho jaata hai same chilrens ke liye
                bool result = dfs_cycle_checker(adj[v][i], V, v, adj, visited);
                //** galti yha return only when true not alwyas
                if (result == true)
                    return (true);
            }
        }
        return false;
    }
    // dfs finished
};