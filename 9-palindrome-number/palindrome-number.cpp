class Solution {
public:
    bool isPalindrome(int x) {
      string s=to_string(x);
      int n=s.length();
      int l=0,r=n-1;
      for(int i=0;i<n/2;i++)
      {
        if(s[i]!=s[n-i-1])
        return false;
      }

     return true;
     
      /*long long sum=0,rem=0;
      int n=x;
      while(n>0)
      {
        rem=n%10;
       sum=sum*10+rem;
     
        n/=10;
      }   
      if(sum==x)return true;
      return false;
    }*/
    }
};