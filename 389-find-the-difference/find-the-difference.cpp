class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>freq;

        for(char c:s)
        {
            freq[c]++;
        }
        for(char c:t)
        {
            freq[c]--;
        }

        for(auto i:freq)
        {
            if(i.second==1||i.second==-1)
              return i.first;
        }
        return ' ';
    }
};