class Solution {
public:
    string getPermutation(int n, int k) {
        //https://chatgpt.com/share/6a1bc823-e514-83ab-8c18-1baf0870ea73
        //ref note for understanding
        vector<int>path;
        vector<int>vis(n+1,0);
        string ans;int count=0;
        func(n,path,vis,count,k,ans);
        // func(n,path,vis,0,k,ans); passing 0 will cause error bcz its passed as reference so use variable int count=0; pass count
        return ans;

    }
    void func(int n,vector<int>& path,vector<int>& vis,int& count,int k,string& ans)
    {
        //base case
        if(path.size()==n)
        {
            count++;
            if(count==k)
            {
                for(int i=0;i<path.size();i++)
                {
                   ans += to_string(path[i]);
                }
            }
            return;
        }
        //core

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==1)continue;
            
            vis[i]=1;
            path.push_back(i);
            func(n,path,vis,count,k,ans);
            path.pop_back();

            vis[i]=0;//backtrack
        }

    }
};