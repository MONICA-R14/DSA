class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
           /*unordered_set freq(nums.begin(),nums.end());
           return freq.size() < nums.size();*/

           sort(nums.begin(),nums.end());
           for(int i=1;i<nums.size();i++)
           {
            if(nums[i]==nums[i-1])
            return true;
           }
           return false;
           

            /* unordered_map<int,int>freq;
             for(int i=0;i<nums.size();i++)
             {
                freq[nums[i]]++;
                if(freq[nums[i]]>1)
                return true;;
             }
             return false;*/
    }
};