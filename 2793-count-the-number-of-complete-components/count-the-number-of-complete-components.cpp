class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        vector<int>visited(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int nodes=0;int edges=0; //for particular component
                dfs(i,adj,visited,nodes,edges);
                edges=edges/2; //bcz 0--1 means for 0 , edge=1 , then for 1 edge=1
                //so totally for 0--1 no of edges=2 , so edge=edges/2, --> edge=1
                 if(edges==nodes*(nodes-1)/2)
                  count++;
            }
        }
        return count;   
    }

    void dfs(int i,vector<int>adj[],vector<int>& visited , int& nodes ,int& edges)
    {
        visited[i]=1;
        nodes++;

        for(auto it:adj[i])
        {
             edges++; //even already visited naalum , it will be counted as an edge for ith node right , so place it above if condition
            if(!visited[it])
            {
                dfs(it,adj,visited,nodes,edges);
            }
        }
    }
};