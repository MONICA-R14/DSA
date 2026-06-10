class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; // like ((0,1),0) first 0,1 represents row,clm , 0-distance of that 0,1 to reach 0 is d=0 bcz it itself holds a zero

        //first lets mark all grids with 0 , d=0 and push them into queue 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0) 
                {
                    // q.push((i,j),0); this is wrongggggggggg keep {{i,j},d}
                    q.push({{i,j},0});//d=0 so insert 0 directly
                    visited[i][j]=1;//mark visited
                }
            }
        }

        while(!q.empty())
        {
            //first take that element and mark neighbours as 1 bcz any grid can reach its l,r,t,b in 1 step
            int row=q.front().first.first;
            int clm=q.front().first.second;
            int d=q.front().second;
            q.pop();

            int r[]={-1,0,1,0}; //distance to be added to row to get its neighbours in t,r,b,l
            int c[]={0,1,0,-1};//same for clm

            for(int i=0;i<4;i++)
            {
                int newro=row+r[i];
                int newcl=clm+c[i];

                if( newro<n && newro>=0 && newcl>=0 && newcl<m && !visited[newro][newcl])
                {
                    visited[newro][newcl]=1;
                    q.push({{newro,newcl},d+1});
                }
            }
            ans[row][clm]=d;
        }
        return ans;
    }
};