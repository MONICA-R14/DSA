class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //https://www.youtube.com/watch?v=sPlRs126bFU
        int l=1;
        int r=piles[0];
     
        for(int i=1;i<piles.size();i++)
        {
            r=max(r,piles[i]);
        }
        int time=r;
        while(l<=r)
        {
           int k=l+(r-l)/2; //mid value , speed value
           long hours=0;
           for(int i=0;i<piles.size();i++)
           {
            hours+= (piles[i]+k-1)/k; //to get ciel value of piles[i]/k use piles[i]+k-1/k;
           }
           if(hours<=h)
           {
             time=k;
             r=k-1; //r=mid-1
           }
           else
           {
            l=k+1;
           }
        }
        return time;
    }
};