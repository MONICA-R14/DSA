class Solution {
public:
  int n=0;
  int m=0;
    int numIslands(vector<vector<char>>& grid) {
        //refer takeuforward video
        //When the graph is given as vertices and edges , find adj list else no need to find
        //here adj matrix given so no need to find adj list 
         n=grid.size();  m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;  
    }
    void dfs(int row,int clm,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
      visited[row][clm]=1;
       int r[]={-1,0,1,0}; 
       int c[]={0,1,0,-1};

       for(int i=0;i<4;i++)
       {
        int newr=row+r[i];
        int newc=clm+c[i];

        if(newr >=0 && newr < n && newc >=0 && newc < m && grid[newr][newc]=='1' && !visited[newr][newc])
        {
            dfs(newr,newc,grid,visited);
        }
       }
    }
};
/*
 int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j] )
                {
                    dfs(i,j,n,m,visited,grid); // or use bfs , bfs code is written below dfs
                    c++;
                }
            }
        }
        return c;
    }
    void dfs(int r,int c,int n,int m,vector<vector<int>>& visited,vector<vector<char>>& grid)
    {
       visited[r][c]=1;

       int row[]={-1,0,1,0};
       int clm[]={0,1,0,-1};

       for(int i=0;i<4;i++)
       {
        int newr=r+row[i];
        int newc=c+clm[i];

        if(newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc] &&
            grid[newr][newc]=='1')
            {
                visited[newr][newc]=1;
                dfs(newr,newc,n,m,visited,grid);
            }
                     
       }
    }
    void bfs(int r,int c,int n,int m,vector<vector<int>>& visited,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c]=1;

        while(!q.empty())
        {
            int row[]={-1,0,1,0};
            int clm[]={0,1,0,-1};

            r=q.front().first;
            c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newr=r+row[i];
                int newc=c+clm[i];


                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc] &&
                     grid[newr][newc]=='1')
                     {
                        visited[newr][newc]=1;
                        q.push({newr,newc});
                     } 
            }
        }
        */
