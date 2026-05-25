class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0); //for 26 alphabets so max possibility is 26 right initialize with 0 for each
        for(char c:s)
        {
            freq[c-'a']++; //eg: if c='b' then freq[1]++ ? how? freq['b'-'a'] = freq[97-96]=freq[1]
        }
        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]-'a']==1)
            return i;
        }
        return -1;

        
        
        /*
        instead of unordered_map we can just use vector to reduce 
        Comparison Internally
        unordered_map
        To access: freq['c']
        computer does:
        hash calculation
        bucket lookup
        collision check
        node access

        array/vector
        To access: freq['c'-'a']
        computer directly jumps to:
        freq[2]
        One operation.
        So array is faster.
        
        
        unordered_map<char,int> freq;

        for(char c : s)
        {
            freq[c]++;
        }

        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]] == 1)
                return i;
        }

        return -1;*/
    }
};