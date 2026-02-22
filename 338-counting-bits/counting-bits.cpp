class Solution {
public:
    vector<int> countBits(int n) {
      vector<int>v(n+1,0);

      for(int i=0;i<=n;i++)
      {
        
        v[i]=v[i>>1] + (i&1);
        //v[i] = v[i >> 1] + (i & 1) lets dry run for i=5  5 = 101   
        //i >> 1 = 2 right shift once means /2
        //v[2] = 1 (since 10 has one 1)
        //i & 1 = 1 (last bit is 1)
        //v[5] = 1 + 1 = 2 correct 5 has 2 ones

      }
      return v;
      /*   BUT ITS O(nlogn)
        for(int i=0;i<=n;i++)
        {
            int count=0;
            int x=i;
            while(x!=0)
            {
                count+=(x%2);
                x=x/2;
            }
            v.push_back(count);
        }
        return v;*/
    }
};