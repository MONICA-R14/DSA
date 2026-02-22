class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;)
        {
            if(nums[i][1]>=nums[i+1][0])
            {
                nums[i][1]=max(nums[i][1],nums[i+1][1]);
                nums.erase(nums.begin()+i+1);
            }
            //dont increment i bcz next time this new nums[i][1] only needs to be checked with nums[i+2][1] (since nums[i+1] is deleted)   
            else{ i++; }   
         }
         return nums;
    }
};