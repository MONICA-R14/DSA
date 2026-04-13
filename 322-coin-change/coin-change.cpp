class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        //refer striver
        vector<vector<int>>dp(n,vector<int>(target+1,0));

        //initialization
        for(int t=0;t<=target;t++)
        {
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else{
            dp[0][t]=1e9;}
        }
        //for loop for changing paras
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=target;t++)
            {
                int nottaken=0+dp[ind-1][t];
                int taken=INT_MAX;

                if(coins[ind]<=t){
                     taken=1+dp[ind][t-coins[ind]];
                }
                dp[ind][t]=min(taken,nottaken);
            }
        }
        int ans=dp[n-1][target]; //last element in dp 2d matrix

        if(ans>=1e9) return -1;

        return ans;
    }
};