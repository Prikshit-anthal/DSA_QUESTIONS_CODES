

class Solution
{
public:
    // By BFS KAHN's algo

    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> topo;
        bool visited[V] = {false};
        // indergrees here
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        // put zero indegree waley in queue
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // bfs

        while (!q.empty())
        {
            int curr = q.front();
            topo.push_back(curr);
            q.pop();
            for (int j = 0; j < adj[curr].size(); j++)
            {

                indegree[adj[curr][j]]--;
                if (indegree[adj[curr][j]] == 0)
                    q.push(adj[curr][j]);
            }
        }

        //   for(int i=0;i<topo.size();i++)
        //   cout<<topo[i]<<" ";
        return topo;
    }
};