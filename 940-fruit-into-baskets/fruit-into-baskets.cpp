class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> freq;

        int l = 0;
        int ans = 0;

        for(int r = 0; r < fruits.size(); r++)
        {
            freq[fruits[r]]++;

            while(freq.size() > 2)
            {
                freq[fruits[l]]--;

                if(freq[fruits[l]] == 0)
                {
                    freq.erase(fruits[l]);
                }

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
        
        
        /*int l=0,r=0,length=0,diff=0;
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
        return length;*/
    }
};