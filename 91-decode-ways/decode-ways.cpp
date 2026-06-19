class Solution {
public:
        
int numDecodings(string s) {
        //in grey note recursion ans is there using memoization
        //by using tabulation 
        int n=s.length();
        //ref grey notes day-5 - 3rd ques from raising brain not from claude but writeen in grey note back side 
       vector<int>dp(n+1,0);
       dp[n]=1;
       for(int i=n-1;i>=0;i--)
       {
        if(s[i]=='0') dp[i]=0;
        else
        {
            //one digit decode
            dp[i]=dp[i+1];

            //two digit decode ref grey note for understanding
            if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))
            {
                dp[i] += dp[i+2]; //why += ref grey note doneky
            }
        }
       }
      return dp[0];
    }
};