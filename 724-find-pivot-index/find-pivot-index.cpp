class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //https://www.youtube.com/watch?v=u89i60lYx8U
        int ls=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();

        for(int i=0;i<nums.size();i++)
        {
            int rs=total-ls-nums[i]; 
            if(rs==ls)
            {
                return i;
            }
            ls+=nums[i];
        }
        return -1;


    }
};