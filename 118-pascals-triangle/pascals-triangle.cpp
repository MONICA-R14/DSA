class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
       
        if(n>=1)
        ans.push_back({1});
        if(n>=2)
         ans.push_back({1,1});

         for(int i=2;i<n;i++)
         {
             vector<int>path;
             path.push_back(1);
            for(int j=1;j<i;j++)
            {
               int x=ans[i-1][j]+ans[i-1][j-1];
                path.push_back(x);
            }
            path.push_back(1);
            ans.push_back(path);
         }
    return ans;
    }
};