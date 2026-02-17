class Solution {
public:
    int maxProduct(vector<int>& nums) {
       /* int maxi=nums[0];
        int ans=nums[0];
        int mmin=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int x=maxi;
            int y=mmin;
           maxi=max({nums[i],x*nums[i],y*nums[i]});
           mmin=min({nums[i],x*nums[i],y*nums[i]});

           ans=max(ans,maxi);
        }
        return ans;*/
      

        int pre = 1, suff = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++)
         {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            ans = max(ans, max(pre, suff) );
        }

        return ans;
        
    }
};