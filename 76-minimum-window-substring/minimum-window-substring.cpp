class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,len=10e8;
        int count=0,si=-1; //si=start index of ans
       if(t.length()>s.length())return "";
        unordered_map<char,int>freq;

        for(int i=0;i<t.size();i++)
        {
            freq[t[i]]++;
        }

        for( r=0;r<s.size();r++)
        {
            if(freq[s[r]]>0) count++;

            freq[s[r]]--;

            while(count==t.size())
            {
                if(r-l+1 < len)
                {
                    len=r-l+1;
                    si=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0)count--;
                l++;
            }
        }
        if(si==-1) return "";
        return s.substr(si,len);
    }
};