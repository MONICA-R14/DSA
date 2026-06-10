class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        int min=0; int fresh=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
         queue<pair<int,int>>q;
        //first insert all rotten oranges into queue then appy bfs
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                  q.push({i,j});
                  visited[i][j]=1;
                } 
                if(grid[i][j]==1) fresh++;
            }
        }

        //bfs
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        while(!q.empty() && fresh>0)
        {
            int s=q.size();
           for(int i=0;i<s;i++) //use this loop to keep track of levels 
           {
            int row=q.front().first;
            int clm=q.front().second;
            q.pop();
           
            // to add neighoubor oranges  to queue grid[r][c]=1 , dont add empty cells
            for(int i=0;i<4;i++)
            {
                int newr=row+r[i];
                int newc=clm+c[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m  && !visited[newr][newc]
                 && grid[newr][newc]==1 ) //for orange grid boxes
                 {
                    q.push({newr,newc});
                    visited[newr][newc]=1;
                    fresh--;
                 }
             }
           }
           min++;
        }
        return fresh==0?min:-1;
    }
};