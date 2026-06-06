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
        
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        int y=n/3;
        //this is wrong dont do this ,dont iterate through nums if u do so then duplicate elements appear twice so no! ,(eg: in eg1 , o/p will be [3,3] which is completely wrong so no!!)
        /*for(int i=0;i<n;i++)
        {
            if(freq[nums[i]]>y)
            {
                ans.push_back(nums[i]);
            }
        }*/
        for(auto &it : freq)
        {
            if(it.second > y)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};