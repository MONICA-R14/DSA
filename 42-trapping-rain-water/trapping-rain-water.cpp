class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int rmax=0,lmax=0;
        int water=0;

        while(l<r)
        {
            if(height[l]<height[r])
            {
                lmax=max(lmax,height[l]);
                water=water+(lmax-height[l]);
                 l++;
            }
            else 
            {
                rmax=max(rmax,height[r]);
                water=water+(rmax-height[r]);
                r--;
            }
        }
        return water;
    }
};