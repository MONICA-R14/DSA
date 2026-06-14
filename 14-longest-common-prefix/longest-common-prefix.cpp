class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //https://chatgpt.com/share/6a2ea93a-9568-83ee-971f-6c5ad487c52f
        //ref grey note back side day-1 ,  Q-6

        if(strs.empty()) return "";
        string ans="";

        for(int i=0;i<strs[0].size();i++)
        {
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(i>=strs[j].length() || c!=strs[j][i])
                {
                    return ans;
                }
            }
            ans+=c;
        }
        return ans;


    }
};