class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //https://youtu.be/SsVvyV6PHBw?si=NCcf2CqBsq7BBgCe
        //above link concept plus note grey note , left page 1061
        //ref concept here and for defn ref solution , plus grey note,chat
        //https://chatgpt.com/share/6a2cea9d-e04c-83e8-b8e0-a2a982ef0955

        int n=s1.length();  //both s1,s2 have same length so no problem
        vector<vector<int>>adj(26);

        for(int i=0;i<n;i++)
        {
            int u=s1[i] -'a';
            int v=s2[i]-'a';

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string res="";
       // why visited arr is inside loop?
       //https://chatgpt.com/share/6a2ceaf5-ee94-83ee-b092-89980d8690f8
        for(char c:baseStr)
        {
            int a=c-'a';
            vector<int> visited(26,0);
            int min=dfs(a,adj,visited);
            res+=min+'a';
        }
        return res;
    }

    int dfs(int i,vector<vector<int>>& adj,vector<int>&visited)
    {
        visited[i]=1;
        int mini=i;

        for(auto it:adj[i])
        {
            if(!visited[it])
            {
                 mini=min(mini,dfs(it,adj,visited));
            }
        }
        return mini;
    }
};