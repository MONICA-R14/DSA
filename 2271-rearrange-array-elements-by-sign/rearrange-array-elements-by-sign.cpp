class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> u, v, res;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            u.push_back(nums[i]);
        else
            v.push_back(nums[i]);
    }

    int i = 0;
    while (i < u.size() && i < v.size()) {
        res.push_back(u[i]);
        res.push_back(v[i]);
        i++;
    }

    return res;
}

};