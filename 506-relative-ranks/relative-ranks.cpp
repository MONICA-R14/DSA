class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> v = score;
        sort(v.begin(), v.end(), greater<int>());

        unordered_map<int, int> rank;
        for (int i = 0; i < v.size(); i++)
            rank[v[i]] = i + 1;

        vector<string> ans;
        for (int s : score) {
            int r = rank[s];
            if (r == 1) ans.push_back("Gold Medal");
            else if (r == 2) ans.push_back("Silver Medal");
            else if (r == 3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(r));
        }
        return ans;
    }
};
     /*string place(int rank)
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
};*/