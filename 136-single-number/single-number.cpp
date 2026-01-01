class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for (int x : nums) ans ^= x;//a ^ a = 0
                                   //a ^ 0 = a this is xor property so a^a la all elements produce output as 0 so ans =0 then that one single element ^ 0(ans)=single element

        return ans;
        
        
        /*if(nums.size()==1)
        return nums[0];

       
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i=i+2)
        {
           
            if(nums[i]!=nums[i+1])
            return nums[i];
           
        }
       
        return nums[nums.size() - 1]; //last element must be the single one , since the above loop runs till n-1 th position
        */
    }
};