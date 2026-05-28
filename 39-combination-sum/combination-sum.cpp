class Solution {
public:

    //https://chatgpt.com/share/6a185a4b-a818-8322-ae89-475a3c631019
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0,i=0;
        vector<int>ds; vector<vector<int>>ans;
        return prii(i,ds,sum,candidates,target,ans);
    }
    vector<vector<int>> prii(int i,vector<int>&ds,int sum,vector<int>& arr,int target,vector<vector<int>>&ans)
    {
        //base condition
        if(sum==target)
        {
            ans.push_back(ds);
            return ans;
        }
        if(i==arr.size() || sum>target)
        return ans;

        //core
        //take same element 
        ds.push_back(arr[i]);
        prii(i,ds,sum+arr[i],arr,target,ans);
        //not take current element take next element
        ds.pop_back();//next element will be pushed in next child func so dont worry abt that
        prii(i+1,ds,sum,arr,target,ans);
        return ans;
    }
};