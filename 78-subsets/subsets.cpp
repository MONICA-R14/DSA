class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,nums,ds,ans);
        return ans;
    }
    void solve(int i,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(i==arr.size())
        {
            ans.push_back(ds);
            return;
        }

        //take
        ds.push_back(arr[i]);
        solve(i+1,arr,ds,ans);
        //not take
        ds.pop_back();
        solve(i+1,arr,ds,ans);
    }
};