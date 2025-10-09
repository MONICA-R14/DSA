class Solution {
public:
    string clearDigits(string s) {
        vector<char>v; string ss="";
        for(char c:s)
        {
            if(c>='0'&& c<='9')
            {
                v.pop_back();
                continue;
            }
            v.push_back(c);
        }
        for(char c:v)
        {
             ss+=c;
        }
        return ss;
    }
};