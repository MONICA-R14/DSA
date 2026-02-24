class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0 || x%10==0 && x!=0) return false;
      int rev=0;
       //https://chatgpt.com/share/699da8ec-dd14-800b-a8e0-353e46680ebb
      while(x>rev)//We only want to reverse HALF. so x>rev not like x>0 noo
      {
        rev=rev*10 + x%10; // to maintain ones tens place (rev*10) , x%10 to get last digit
        x/=10;
      }
      return (x==rev || x==rev/10);// x=rev/10 It comes when the number has odd number of digits.

      /*string s=to_string(x);
      int n=s.length();
      int l=0,r=n-1;
      for(int i=0;i<n/2;i++)
      {
        if(s[i]!=s[n-i-1])
        return false;
      }

     return true;*/
     
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