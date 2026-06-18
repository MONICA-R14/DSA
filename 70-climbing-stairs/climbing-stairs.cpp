class Solution {
public:
    // if we use repeated func for fibo then it causes time limit to exceed (bcz this function called more than once for the same input) like for fibo(37) fibo(36)+fibo(35)now for fibo(36) also again fibo(35)+fibo(34) here fibo(35) repeated again but ans is same ... so its not efficient.. so better use loop or dp
    int climbStairs(int n) {
        if(n<=1)
        return 1;
        long long prev1=1,prev2=1;
        for(int i=2;i<=n;i++)
        {
            long long temp=prev1+prev2; //eg: in fibo (prev1)1,(prev2)1,2,3,5,...,prev1=1,prev2=1 
            //at next stage prev1=prev2=1 , then prev2=3(prev1+prev2) ,
            prev1=prev2;
            prev2=temp;
        }
        return prev2;
    }
};