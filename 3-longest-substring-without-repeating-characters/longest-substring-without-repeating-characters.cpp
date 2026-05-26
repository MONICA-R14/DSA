class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        //https://chatgpt.com/share/6a15c9f8-6340-8320-a185-ef8d0cfd08c7
        // in chat recent at last this question is there
        int maxi=0;
        unordered_map<char,int>mp;
        for(int j=0;j<s.length();j++)
        {
           if(mp.find(s[j])!=mp.end() && mp[s[j]]>=i)
           {
             i=mp[s[j]]+1;//i move to next index of (old) repeated char 
           }
           mp[s[j]]=j;
           maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};