class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;

        sort(nums.begin(),nums.end());
        int expected=1;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            if(x==expected)
             expected++;

             if(x > expected)
             {
                while(x > expected)
                {
                    ans.push_back(expected);
                    expected++;
                }
                expected++;
             }
             
        }

        while(expected<=nums.size())
        {
            ans.push_back(expected++);
        }
        return ans;
        
        /*vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;*/
    }
};







