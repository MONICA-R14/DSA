class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++)
        {
            int sub=target-nums[i];
            if(mpp.find(sub)!=mpp.end())
            {
                return {mpp[sub],i};
            }
            mpp[nums[i]]=i;
        }
        return {};

       /* unordered_map<int, int> pairIdx;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (pairIdx.find(target - num) != pairIdx.end()) {
                return {i, pairIdx[target - num]};
            }
            pairIdx[num] = i;
        }

        return {}; */

       /* for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
             
             auto it=find(nums.begin()+i+1 , nums.end() , x);

             if(it!=nums.end())
             {
                return {i , int(it - nums.begin())}; //it-nums.begin() gives pointer , so to find the index of that pointer use int(that value) 
             }
        }
        return {}; // if it fails*/
    }
};