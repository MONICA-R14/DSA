class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<pair<int,int>>fr(freq.begin(),freq.end());
        // sort(fr.begin(),fr.end()); tihs sorts by key not value 
        //below one sorts by value so correct
        //https://chatgpt.com/s/t_6a23d1e4db7c8191b4734d57127edaea
         sort(fr.begin(), fr.end(), [](auto &a, auto &b)   {
                 return a.second > b.second;
             });
              //generally return_type func(para) { return x; } 
             // [] is to catch returned value , then no func name , (para passed as reference & )
             //inside { return bigger value ;} 

        for(int i=0;i<k;i++)
        {
            ans.push_back(fr[i].first);
        }
        return ans;
    }
};