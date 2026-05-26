class Solution {
public:
    char findTheDifference(string s, string t) {
      //https://chatgpt.com/share/6a1550e3-4d00-8324-9504-6fc964f8ae1f
      char ans=0;

      for(char c:s)
      {
        ans^=c;
      }
      for(char c:t)
      {
        ans^=c;
      }
      return ans;
      
       /* unordered_map<char,int>freq;

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
        return ' ';*/
    }
};