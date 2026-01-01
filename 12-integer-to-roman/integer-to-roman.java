class Solution {
    public String intToRoman(int num) {
        
        String[] M = {"", "M", "MM", "MMM"};// max value is 3999 only so stop till 3000 value!
        String[] C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[(num%10)];
       
       
       
        //why use stringbuilder  , s.append("a") and toString ? refer upstop word document for reference
        // in c++ use s+='a' like that , in java also we can use that but its better to use String builder , append operation and toString ref the reason there

        
    }
}