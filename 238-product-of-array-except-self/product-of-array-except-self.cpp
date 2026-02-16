class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        int pre[n+1],post[n+1];
        int pro=1;
        int i=0; pre[0]=1; post[n]=1;
        //if needed refer utube for reference 
        while(i<n)
        {
            pre[i+1]=pre[i]*nums[i];
            i++;
        }
        i=n-1;
        while(i>=0)
        {
            post[i]=post[i+1]*nums[i];
            i--;
        }

        for(int i=0;i<n;i++)
        {
            v.push_back(pre[i]*post[i+1]);
        }
        return v;
    }
};