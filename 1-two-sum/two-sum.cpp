class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       /* unordered_map<int, int> pairIdx;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (pairIdx.find(target - num) != pairIdx.end()) {
                return {i, pairIdx[target - num]};
            }
            pairIdx[num] = i;
        }

        return {}; */

unordered_map<int,int>mapp;

for(int i=0;i<nums.size();i++)
{
    int sub=target-nums[i];

    if(mapp.find(sub)!=mapp.end())
    {
        return {i,mapp[sub]};//map[sub] returns sub index
    }
    mapp[nums[i]]=i;
}
return {};

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