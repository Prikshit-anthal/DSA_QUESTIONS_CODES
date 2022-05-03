class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        // for bfs
        bool visited[V] = {false};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                queue<pair<int, int>> q;
                q.push({i, -1}); // child,parent
                visited[i] = true;
                int k, p;
                for (k = q.front().first, p = q.front().second; k != -1;)
                {
                    for (int j = 0; j < adj[k].size(); j++)
                    {
                        // cout<<"hi"<<j<<k<<adj[k].size();
                        if (visited[adj[k][j]] == true && adj[k][j] != p)
                        {
                            // cout<<k<<" "<<j<<" "<<adj[k][j];
                            return true;
                        }
                        else if (adj[k][j] != p)
                        {
                            visited[adj[k][j]] = true;
                            q.push({adj[k][j], k});
                        }
                    }
                    q.pop();
                    if (q.empty() == true)
                        k = -1;
                    else
                    {
                        k = q.front().first;
                        p = q.front().second;
                    }
                }
            }
        }
        return false;

        // bfs finished
    }
};