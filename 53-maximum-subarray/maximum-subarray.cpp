class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxi=nums[0];
      int curr=nums[0];
      for(int i=1;i<nums.size();i++)
      {
        curr=max(curr+nums[i] , nums[i]); //if nums[i] > oldsum+nums[i] then start with nums[i] itself , remove that old sum
        maxi=max(maxi,curr);
      }
      return maxi;
      
        /*int res=nums[0];
        int total=0;

        for(int i:nums)
        {
            if(total<0) total=0;

            total+=i;
            res=max(res,total);
        }
        return res;*/
    }
};