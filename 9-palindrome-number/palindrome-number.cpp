class Solution {
public:
    bool isPalindrome(int x) {
     vector<int>v;
     if(x<0)return false;
     while(x!=0)
     {
        v.push_back(x%10);
        x=x/10;
     }
     int n=v.size();
     for(int i=0;i<n/2;i++)
     {
        if(v[i]!=v[n-i-1])
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