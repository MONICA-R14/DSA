class Solution {
    public int lengthOfLastWord(String s) {
        int n=s.length(); int count=0; int z=n-1;
        while(z>=0 && s.charAt(z)==' ')
        {
            z--; //if in last we have space then skip that
        }
        for(int i=z;i>=0 && s.charAt(i)!=32 ;i--)
        {
           //what if at last there is extra space 
           
            count++;
        }
        return count;
    }
}