class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        int count=0;int x;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]] > count)
            {
                x=nums[i];
                count=freq[nums[i]];
            }
        }
        return x;
    }
};