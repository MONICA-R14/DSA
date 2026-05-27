class Solution {
public:
    int totalFruit(vector<int>& fruit) {
        int l=0,r=0,length=0,diff=0;
        unordered_map<int,int>freq;

        for(int r=0;r<fruit.size();r++)
        {
            if(freq[fruit[r]]==0)
            {
                diff++;
            }
            freq[fruit[r]]++;
            if(diff<=2)
            {
                length=max(length,r-l+1);
            }

            while(diff>2)
            {
                freq[fruit[l]]--;
                if(freq[fruit[l]]==0)
                {
                    diff--;
                }
                l++;
            }
        }
        return length;
    }
};