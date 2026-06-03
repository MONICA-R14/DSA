class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //ref striver or refer note

        //  1-transpose of matrix
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // O (n/2 * n/2) for each loop its n/2


        //  2-reverse each row (i.e) Mirror image
        for(int i=0;i<n;i++)
        {
            //  matrix[i] represents ith row
            reverse(matrix[i].begin() , matrix[i].end());
        }
        // O(n * n/2) , n-loop , n/2 is for reverse func
    }
};