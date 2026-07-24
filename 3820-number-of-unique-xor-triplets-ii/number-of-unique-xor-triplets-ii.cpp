class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAX_XOR=2048;

        vector<bool>present(MAX_XOR,false);

        for(int num:nums)
        {
            present[num]=true;

        }
        vector<vector<bool>>dp(4,vector<bool>(MAX_XOR,false));
        dp[0][0]=true;

        for(int count=1;count<=3;count++)
        {
            for(int value=0;value<MAX_XOR;value++)
            {
                if(!present[value]) continue;

                for(int xr=0;xr<MAX_XOR;xr++)
                {
                    if(dp[count-1][xr])
                    {
                        dp[count][xr^value]=true;
                    }
                }
            }
        }
        int answer=0;
        for(int xr=0;xr<MAX_XOR;xr++)
        {
            if(dp[3][xr]){
                answer++;
            }
        }

        return answer;
    }
};