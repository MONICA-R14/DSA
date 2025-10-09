class Solution {
public:
    string clearDigits(string s) {
       string v="";
        for(char c:s)
        {
            if(c>='0'&& c<='9')
            {
                v.pop_back();
                continue;
            }
            v.push_back(c);
        }
       
        return v;
    }
};