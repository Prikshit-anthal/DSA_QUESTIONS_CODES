#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int i, int V, vector<int> &stack, bool visited[], vector<pair<int, int>> adj[]);
    vector<int> topoSort(int V, vector<pair<int, int>> adj[])
{
    // code here dfs
    vector<int> stack;
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfsHelper(i, V, stack, visited, adj);
            stack.push_back(i);
        }
        //   cout<<"Outer loop"<<endl;
    }

    vector<int> stack1;

    for (int i = 0; i < stack.size(); i++)
    {
        stack1.push_back(stack[stack.size() - i - 1]);

        // cout << stack[i] << " ";
    }
    return stack1;

	}

	///see vector not passed by reference

	void dfsHelper(int i,int V,vector<int> & stack,bool visited[], vector<pair<int,int>> adj[])
	{
	    for(int j=0;j<adj[i].size();j++)
	    {
	      //  cout<<" djk"<<adj[i].size()<<i;
	        if(visited[adj[i][j].first]==false)
	       {
               visited[adj[i][j].first] = true;
               dfsHelper(adj[i][j].first, V, stack, visited, adj);
               //cout<<"Push "<<adj[i][j]<<" ";
               stack.push_back(adj[i][j].first);
           }
	    }

	}

// o(v+e)
void MODIFIED_TopoSort(vector<pair<int,int>> adj[], int V, int s, int dist[])
{
    //call topop sorty
    vector<int> topo=topoSort(V,adj);
    dist[s]=0;
    for(auto itr:topo)
    {
        if(dist[itr]!=INT_MAX)
        {
            for(auto ittr:adj[itr])
            {
                if(ittr.second+dist[itr]<dist[ittr.first])
                {
                    dist[ittr.first] = ittr.second + dist[itr];
                }
            }
        }
    }

}

void addEdge(vector<pair<int,int>> adj[], int u, int v,int w)
{
    adj[u].push_back({v,w});
}

int main()
{
    int V = 4;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1,2);
    addEdge(adj, 1, 2,3);
    addEdge(adj, 2, 3,5);
    addEdge(adj, 0, 2,7);
    addEdge(adj, 1, 3,6);
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    MODIFIED_TopoSort(adj, V, 0, dist);

    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}

// O/P: 0 1 1 2