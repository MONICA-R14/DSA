class Solution {
public:
    int reverseBits(int n) {
     // https://chatgpt.com/share/699c6c66-210c-800b-9fe3-a7564d9cbcf6
      int res=0;
      for(int i=0;i<32;i++)
      {
        int x=n&1; //find if last bit is 0 or 1 
       res=(res<<1) | (x); //shift left means already existing bit eg:1 na it will become 10 (1 moved left) now that 0 thats not 0 it might be 0 or 1 depending on next last binary value of n thats found using n&1 , if its 0 then 0|0=0 correct , if its 1 then change 0 to 1 how? 0|1 =1 
       //remove that last bit bcz its added in front in result so remove that
       n=n>>1; // or n=n/2;
      }
      return res;
    }
};