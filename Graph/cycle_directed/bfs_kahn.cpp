class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        // using bfs kahn's algo

        queue<int> q;
        vector<int> topo;
        int indegree[V] = {0};

        // setting indegrees
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        // finding 0 indegree
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        if (q.empty())
        {
            return true;
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for (int i = 0; i < adj[curr].size(); i++)
            {
                indegree[adj[curr][i]]--;
                if (indegree[adj[curr][i]] == 0)
                {
                    q.push(adj[curr][i]);
                }
            }
        }

        // see if topo size == V means sb toposort aa gye indegree -- waley procedure se
        // i.e. 0 indegree nai hoga jb cycle therefore kush elements nai add honge topo mai

        if (topo.size() != V)
        {
            return true;
        }
        return false;
    }
};