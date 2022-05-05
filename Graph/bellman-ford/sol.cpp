class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here
        int dist[n];
        for (int i = 0; i < n; i++)
            dist[i] = 1e9;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto itr : edges)
            {
                int u = itr[0];
                int v = itr[1];
                int w = itr[2];
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // now check
        for (auto itr : edges)
        {
            int u = itr[0];
            int v = itr[1];
            int w = itr[2];
            if (dist[u] + w < dist[v])
            {
                // cycle
                return 1;
            }
        }

        return 0;
    }
};