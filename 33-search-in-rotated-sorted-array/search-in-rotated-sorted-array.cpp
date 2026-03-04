class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            //https://chatgpt.com/share/69a83108-e4ec-800b-b270-aa815c32865b
            int mid=(l+r)/2;

            if(nums[mid]==target) return mid;

            if(nums[l]<=nums[mid])//left array is sorted
            {
                if(nums[l]<=target&& target<nums[mid])//target is within range in sorted array itslef
                {
                    r=mid-1;
                }
                else// target is in anotehr part of array might be in unsorted part
                {
                    l=mid+1;
                }
            }
            else //right part is sorted
            {
                if(nums[mid]<target&& target<=nums[r])//target is within range 
                {
                  l=mid+1;
                }
                else 
                {
                   r=mid-1;
                } 
            }
        }   
     
     return -1;
    }
};