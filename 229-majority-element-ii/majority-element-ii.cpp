class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // ref striver
        //https://chatgpt.com/share/6a239af8-d8f8-8324-9ead-d366f3e316f2
        // if > n/3 then max only 2 elements are possible , if n>2 then only 1 element is max possible 
        
        int c1=0,c2=0; // if n>3 then max possible elements are 2 only ,ref chat link for reason
        int el1=INT_MIN;
        int el2=INT_MIN; int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(c1==0 && nums[i]!=el2) // to avoid el1 and el2 to have same values 
            {
                c1++; el1=nums[i];
            }
            else if(c2==0 && nums[i]!=el1)
            {
                c2++; el2=nums[i];
            }

            else if(nums[i]==el1) c1++;
            else if(nums[i]==el2) c2++;

            else {
                c1--;
                c2--;
            }
        }
        vector<int>ans;
        //once check again manually using for loop , if el1 and el2 are the  majority elements ot not
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2)cnt2++;
        }
        int y=int(n/3);
        if(cnt1 >= y+1) ans.push_back(el1);
        if(cnt2 >= y+1) ans.push_back(el2);

        return ans;




        /*unordered_map<int,int>freq;  int n=nums.size();
        vector<int>ans;
        if(n==1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        int y=n/3;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            //we cant use  count>y bcz if count=3,y=4 then at next stage count=4,y=4 then same element added twice or more than that so no!, add only once for that check ==
            if(freq[nums[i]]==y+1) // count> y so check if==y+1 
                ans.push_back(nums[i]);
        }
       
        return ans;
        */
    }
};