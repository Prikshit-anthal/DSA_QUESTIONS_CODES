
class Solution
{
public:
    // Function to return list containing vertices in Topological order.

    // By DFS
    // logic : dfs se andr tk jao
    // jaise he jiske saare child khtam usse add krlo
    // repeat

    	vector<int> topoSort(int V, vector<int> adj[])
    	{
    	    // code here dfs
    	    vector<int> stack;
    	    bool visited[V]={false};
    	    for(int i=0;i<V;i++)
    	    {
    	        if(visited[i]==false)
    	        {
    	            visited[i]=true;
    	           dfsHelper(i,V,stack,visited,adj);
    	           stack.push_back(i);
    	        }
    	     //   cout<<"Outer loop"<<endl;
    	    }

    	    vector <int> stack1;

    	    for(int i=0;i<stack.size();i++)
    	 {   stack1.push_back(stack[stack.size()-i-1]);

    	     cout<<stack[i]<<" ";
    	 }
    	    return stack1;

    	}

    	///see vector not passed by reference

    	void dfsHelper(int i,int V,vector<int> & stack,bool visited[], vector<int> adj[])
    	{
    	    for(int j=0;j<adj[i].size();j++)
    	    {
    	      //  cout<<" djk"<<adj[i].size()<<i;
    	        if(visited[adj[i][j]]==false)
    	       {
    	           visited[adj[i][j]]=true;
    	           dfsHelper(adj[i][j],V,stack,visited,adj);
    	           //cout<<"Push "<<adj[i][j]<<" ";
    	           stack.push_back(adj[i][j]);

    	       }
    	    }

    	}
};