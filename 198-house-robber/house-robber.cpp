class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return  f(0,nums,dp);
    }
    int f(int ind,vector<int>& nums,vector<int>& dp)
    {
        int n=nums.size();
        if(ind >= n) return 0;

        if(dp[ind]!=-1) return dp[ind];
        
        int nottake=f(ind+1,nums,dp);
        int take=nums[ind]+f(ind+2,nums,dp); // ind+2 bcz if we rob consecutive houses it will alert police 
        return dp[ind]=max(take,nottake);


    }
};