class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

for (auto &e : edges) {
    int u = e[0];
    int v = e[1];

    adj[u].push_back(v);
    adj[v].push_back(u);   // because graph is undirected
}

  vector<int>visited(n,0);
  if(source==destination) return true;
  dfs(source,adj,visited);
  if(visited[destination]!=1) return false;
  return true;
    }

    void dfs(int source,vector<vector<int>>&adj,vector<int>& visited)
    {
        visited[source]=1;

        for(auto i:adj[source])
        {
            if(!visited[i])
            {
                
                dfs(i,adj,visited);
            }
        }
    }
};