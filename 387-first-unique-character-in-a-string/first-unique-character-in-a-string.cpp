class Solution {
public:
    int firstUniqChar(string s) {
        int index=-1,i=0;
        unordered_map<char,int>freq;

        for(char c:s)
        {
            freq[c]++;
        }
        for(char c:s)
        {
            if(freq[c]==1)
             return i;

             i++;
    
        }
        return index;
    }
};