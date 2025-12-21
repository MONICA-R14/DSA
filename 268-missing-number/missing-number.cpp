class Solution {
public:
    int missingNumber(vector<int>& nums) {
          int res=nums.size();

          for(int i=0;i<nums.size();i++)
          {
            res += i-nums[i];
          }
          return res;
     
       /*sort(nums.begin(),nums.end()); int i;
       if(nums[0]!=0) return 0;
        for( i=0;i<nums.size()-1;i++)
        {
            if(nums[i]+1 !=nums[i+1])
            {
                return nums[i]+1;
            }
        }
        return nums[i]+1;*/
    }
};