class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxsum=0;

        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        maxsum=lsum;//initialize maxsum with lsum

        int j=cardPoints.size()-1;//for rsum 
        for(int i=k-1;i>=0;i--,j--)
        {
            lsum-=cardPoints[i];
            rsum+=cardPoints[j];

            maxsum=max(rsum+lsum , maxsum);
        }
        return maxsum;

    }
};