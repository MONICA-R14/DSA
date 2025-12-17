class Solution {
public:
     string place(int rank)
     {
        if(rank==1)
        return "Gold Medal";
        else if(rank==2)
        return "Silver Medal";
        else
        return "Bronze Medal";
     }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>v2;
        v2=score; // copy values to vector v 
        sort(v2.begin(),v2.end(),greater<int>());

        vector<string>ans;
        for(int i=0;i<score.size();i++)
        {
            int rank=find(v2.begin(),v2.end(),score[i]) -v2.begin() + 1;
            if(rank<=3)
            {
              ans.push_back(place(rank));
            }
            else
            {
                ans.push_back(to_string(rank));
            }
        }
        return ans;
    }
};