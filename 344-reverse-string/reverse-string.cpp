class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>t;

        for(int i=s.size()-1; i>=0;i--)
        {
            t.push_back(s[i]);
        }

        s=t;
    }
};