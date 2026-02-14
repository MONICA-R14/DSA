class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //refer takeuforward video
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(!visited[r][c] && grid[r][c]=='1')
                {
                    bfs(r,c,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
    void bfs(int r,int c,vector<vector<int>>&visited,vector<vector<char>>&grid)
    {
        visited[r][c]=1;

        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        q.push({r,c});

        while(!q.empty())
        {
            int row=q.front().first;
            int clm=q.front().second;
            q.pop();

            for(int delr=-1;delr<=1;delr++)
            {
                for(int delc=-1;delc<=1;delc++)
                {
                    int x=row+delr;
                    int y=clm+delc;
                     //skip self box
                     if(delr == 0 && delc == 0)
                             continue;

                    // skip diagonals
                    if(abs(delr) == 1 && abs(delc) == 1)
                        continue;
                     

                    if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]=='1')
                    {
                        visited[x][y]=1;
                        q.push({x,y});
                    }

                       /* here we dont need to check 8 directions , we only see 4 sides avoiding diagonals so only we skipped taht part and self part if u dont like that use this for better way
                       int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

for(int i = 0; i < 4; i++)
{
    int x = row + delrow[i];
    int y = clm + delcol[i];

    if(x >= 0 && x < n &&
       y >= 0 && y < m &&
       !visited[x][y] &&
       grid[x][y] == '1')
    {
        visited[x][y] = 1;
        q.push({x,y});
    }
}
                       */
                }
            }
        }
    }
};