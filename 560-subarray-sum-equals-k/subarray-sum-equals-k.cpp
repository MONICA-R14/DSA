class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //https://chatgpt.com/s/t_6a26482bc9cc8191bc82b32919adea0f
      //https://chatgpt.com/s/t_6a2647d60d9481918b0ccba8648cef3a
      //ref strivers second solu : prefix+hashmap , bcz 3rd solu is only for +ve elements but here we have -ve elements too so dont use that 3rd

      int prefix=0;
      int count=0;
      unordered_map<int,int>mp;
      mp[0]=1; //let 0 be there once (freq = 1) for zero
      for(int num : nums)
      {
        prefix+=num;

        if(mp.find(prefix-k)!=mp.end())
        {
            count+=mp[prefix-k]; //ref why in second link of chatgpt , add freqcount , bcz particular sum  may occur manytime
        }
        mp[prefix]++;
      }
      return count;
    }
};