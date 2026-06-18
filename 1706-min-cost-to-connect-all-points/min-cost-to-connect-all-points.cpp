class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //to form adj list https://chatgpt.com/share/6a337f4c-c8c4-83e8-a1bc-77a11824e501
        //before this refer MST in gfg raisingbrain or youtube striver
        //gfg https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
        // utube https://www.youtube.com/watch?v=mJcZjjKzeqk
        
        int n=points.size();
        vector<pair<int,int>>adj[n];
        priority_queue< pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>
                       >pq;
        vector<int>visited(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=abs(points[i][0]-points[j][0]);
                int y=abs(points[i][1]-points[j][1]);

                int dist=x+y;
                
                adj[i].push_back({dist,j}); //like (0,0) is 0 and (2,2) is 1 , (3,10) is 2
                //so here 0--{4,1} -->meaning (0,0) ----{4,{2,2}} but its mentioned as 1,2 for simplicity 
                adj[j].push_back({dist,i}); //here 1---{4,0} meaning {2,2}---{4,{0,0}}
            }
        }

            pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            if(visited[node]==1) continue;//no need to go that way 
           //if its already visited then minimum value is already there so no need to go that way
 //how usay first marked value willbethe minimum value?? bcz this is min heap priority queue 
            visited[node]=1;
            sum+=wt;

            for(auto it:adj[node])
            {
                int adjnode=it.second;
                int adjwt=it.first;

                if(!visited[adjnode])
                  pq.push({adjwt,adjnode});//pass only new weight dont pass wt+adjwt bcz 
                   //bcz the new weight will be added to sum in next iteration so no problem
            }
        }
        return sum;
    }
};