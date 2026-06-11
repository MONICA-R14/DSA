class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //simialr to no of islands
        //here adjacency matrix given , so first find adjaceny list and proceed further
        int v=isConnected.size();
        vector<int>adj[v];
        vector<int>visited(v,0);

        for(int i=0;i<v;i++)
        {
            for(int j=i+1;j<v;j++) //why ref this chat link
            //https://chatgpt.com/s/t_6a2a6a39b8988191b6a3051fbd59665a
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<v;i++)
        {
            
            if(!visited[i])
            {
                dfs(i,adj,visited);
                c++;
            }

        }
        return c;
    }
    void dfs(int i,vector<int>adj[], vector<int>& visited)
    {
        visited[i]=1;
        
        for(auto it:adj[i])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited);
            }
        }
    }


        
};