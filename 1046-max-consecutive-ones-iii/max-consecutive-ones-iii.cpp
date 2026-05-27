class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int zeros=0,count=0;
     int l=0,r=0;
     while(r<nums.size())
     {
        if(nums[r]==0)zeros++;

        if(zeros<=k) 
        {
            count=max(count,r-l+1);
        }
        while(zeros>k)
        {
            if(nums[l]==0)zeros--;

            l++;
        }
        r++;
     }  
     return count; 
    }
};