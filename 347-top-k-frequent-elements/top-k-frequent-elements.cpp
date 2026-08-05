class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //ref grey note front side from interview page onwards
       unordered_map<int,int>freq;

       for(int i=0;i<nums.size();i++)
       {
        freq[nums[i]]++;
       }
       //min heap
       priority_queue<pair<int,int> ,
                      vector<pair<int,int>>,
                      greater<pair<int,int>>>pq;
        for(auto& p : freq)
        {
            pq.push({p.second , p.first}); //insert frequency first bcz based on second value only we alter pq accordinlgy

            if(pq.size()>k)
            pq.pop();
        }

        vector<int>ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
       /*
        // ref better solu https://chatgpt.com/share/6a23d2df-29e8-8322-b395-8710ba4fcd5b
        //or below one but its not optimal
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
        */
    }
};