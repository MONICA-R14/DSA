class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>freq;
        freq[0]=1;
        int presum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            int remove=presum-k;
            count+=freq[remove];
            freq[presum]+=1;
        }
        return count;
    }
};