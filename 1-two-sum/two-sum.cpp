class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
             
             auto it=find(nums.begin()+i+1 , nums.end() , x);

             if(it!=nums.end())
             {
                return {i , int(it - nums.begin())}; //it-nums.begin() gives pointer , so to find the index of that pointer use int(that value) 
             }
        }
        return {}; // if it fails
    }
};