class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        //https://chatgpt.com/share/6a15a406-bee0-8322-bdcb-5f56b5131b30
        for(auto s : strs)
        {
            string temp=s;

            sort(temp.begin(),temp.end());

            mpp[temp].push_back(s);
        }
        vector<vector<string>>ans;

        for(auto i:mpp)
        {
            // first iteration i=["ate","eat","tea"] like that 
            ans.push_back(i.second);
        }
        return ans;
    }
};