class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(findgreater(nums2,nums1[i]));
        }
        return ans;
    }
    int findgreater(vector<int>& nums2,int x)
    {
        int found=0;
        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]==x) 
                found=1;
            if(nums2[i]>x && found==1)
             return nums2[i];
        }

        return -1;
    }
};