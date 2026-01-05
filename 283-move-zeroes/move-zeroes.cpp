class Solution {
public:
    void moveZeroes(vector<int>& nums) {
           int j = 0;

    // move all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    // fill remaining positions with zero
    for (int i = j; i < nums.size(); i++) {
        nums[i] = 0;
    }

       /* int left=0;
        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]!=0)
            {
                swap(nums[right],nums[left]);
                left++;
            }
        }*/
    }
};