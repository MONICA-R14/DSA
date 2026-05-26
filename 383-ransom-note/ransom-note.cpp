class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       //if u dont understand this ref below solu first then come here
       //https://chatgpt.com/share/6a15532b-6eb4-8322-8cdc-183743005cfa 
       int freq[26] = {0};

        for(char c : magazine)
        {
            freq[c - 'a']++;
        }

        for(char c : ransomNote)
        {
            if(--freq[c - 'a'] < 0)
                return false;
        }

        return true;
    
       
       
        /*vector<int>freq(26,0);

        for(char c:ransomNote)
        {
            freq[c - 'a']++;
        }

        for(char c:magazine)
        {
            freq[c - 'a']--;
        }

        for(auto i:freq)
        {
            if(i>0)return false;
        }
        return true;*/
    }
};