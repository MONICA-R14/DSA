class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n=nums.size();
          int totalsum=(n*(n+1))/2; //sum of n elements  Math:)
          for(int i=0;i<n;i++)
          {
            totalsum-=nums[i];
          }
          return totalsum; 
          
          
          
         /*int res=nums.size();

          for(int i=0;i<nums.size();i++)
          {
            res += i-nums[i];
          }
          return res; */


     
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