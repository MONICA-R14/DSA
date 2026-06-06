class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;  int n=nums.size();
        vector<int>ans;
        if(n==1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        int y=n/3;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]==y+1) 
                ans.push_back(nums[i]);
        }
       
        return ans;
    }
};