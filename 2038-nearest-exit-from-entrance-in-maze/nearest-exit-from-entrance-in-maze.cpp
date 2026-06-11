class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //apply bfs
        int n=maze.size();
        int m=maze[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0],entrance[1]},0}); // 0-for path length
        
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        visited[entrance[0]][entrance[1]]=1;

        while(!q.empty())
        {
            
            int row=q.front().first.first;
            int clm=q.front().first.second;
            
            int p=q.front().second;
            q.pop();

            
    
            for(int i=0;i<4;i++)
            {
                int newr=row+r[i];
                int newc=clm+c[i];

                if(newr< 0 || newr>=n || newc <0 || newc>=m)
                {
                    if(!(row==entrance[0] && clm==entrance[1])) //here we need to check row and clm bcz from that place grid only we exit 
                    {
                        return p;
                    }
                }
                if(newr >= 0&& newr<n && newc<m && newc>=0 && maze[newr][newc]=='.' && !visited[newr][newc] )
                {
                    //check if its near exit , exit ={row <0 or =n or clm <0 or =m }and not !=entrance
                    /*if((newr==0 || newr==n-1 || newc==0 || newc==m-1) && !(newr==entrance[0] && newc==entrance[1]))
                    {
                     return p+1;
                    }*/
                    visited[newr][newc]=1;
                    q.push({{newr,newc},p+1});

                }
                
                
            }
        }
       return -1; 
    }
   
};