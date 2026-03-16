class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        freq[0]=1;
        int presum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
             if(freq.find(presum - k) != freq.end())
            count += freq[presum - k];
            /*int remove=presum-k;
            count+=freq[remove];*/
            freq[presum]+=1;
        }
        return count;
    }
};