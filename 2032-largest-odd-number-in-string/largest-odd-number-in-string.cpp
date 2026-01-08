class Solution {
public:
    string largestOddNumber(string num) {
        string fire="";

        for(int i=num.length()-1; i>=0;i--)
        {
            if((num[i] - '0')  % 2 != 0)  //num[i] -'0' gives the char's integer value ----for string stoi(string);
            {
                return num.substr(0, i + 1);
                /*for(int k=0;k<=i;k++)
                {
                    fire+=num[k];
                
                }*/
              // replace for loop with---- return num.substr(0, i + 1);

                break;
            }
        }
        return fire;
    }
};