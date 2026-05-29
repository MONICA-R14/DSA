class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
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
        while(i+1 < arr.size() && arr[i]==arr[i+1])
        { 
            i++;
        }

        solve(i+1,arr,ds,ans);
    }
};