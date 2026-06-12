class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
  // https://youtu.be/73sneFXuTEg?si=-XVUDHwNwUu7w2d6  -- topological sort / khan algo
 // https://youtu.be/iTBaI90lpDQ?si=Y59iGUV_OLW7kH16   --detect cycle in graph using khan algo
 // https://www.youtube.com/watch?v=WAOfKpxYHR8&t=440s
 
        vector<int>adj[V];
        
        //if [1,0] then 0-->1 , 0 should happen before 1 so, 0-->1
        // [2,1] then 0-->1-->2 is correct , 0 before 1 , 1 before 2 

        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>indegree(V,0);
        //calculate indegree for all nodes
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])//for each node mark neighbour's indegree++
            {
                indegree[it]++;
            }
        }
        //if indegree is 0 insert into queue
        queue<int>q;  
        for(int i=0;i<V;i++)
        {
           if(indegree[i]==0)
           {
               q.push(i);
           }
        }
        vector<int>topo;  //to store topo order
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                 q.push(it);
            }
        }
        
       if(topo.size()==V) return topo;
       else return {};     
    }
};