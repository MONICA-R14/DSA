class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length(); // or needle.size();
        int m=haystack.length();

        for(int i=0;i<= m-n;i++) //m-n bcz if m is less than n then no use
        {
            if(haystack[i]==needle[0])
            {
                string rough=haystack.substr(i,n); //s.substr(startindex,length) not like start,end nooo
                if(rough==needle)
                {
                 return i;
                }
            }
        }
        return -1;
    }
};