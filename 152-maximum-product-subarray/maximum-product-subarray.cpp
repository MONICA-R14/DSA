class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
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
        return ans;
    }
};