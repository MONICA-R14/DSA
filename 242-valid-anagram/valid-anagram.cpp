class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
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
            if(i.second!=0)
            return false;
        }
        return true;
        /*
        here we used 2 unorderedmaps , how abt one map? ref above solu
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(int i=0;i<s.length();i++)
        {
            freq1[s[i]]++;
            freq2[t[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(!freq2[c]) return false;
            if(freq1[c]!=freq2[c])
            return false;
        }
        return true;*/
    }
};