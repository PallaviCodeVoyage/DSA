class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>>mp;
        for(vector<int>v:edges)
        {
            mp[v[0]].push_back({v[2],v[1]});
            mp[v[1]].push_back({v[2],v[0]});
            
        }//map is made
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
//int edges=V-1;
        vector<int>parent(V,-1);
        vector<bool>visited(V,false);
        vector<int>safar(V,INT_MAX);
        
        int start=0;
        safar[start]=0;
        pq.push({0,start});
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            int u=p.second;
            int travel=p.first;
            if(visited[u])
            {
                continue;
            }
            
            visited[u]=true;
            for(pair<int,int>z:mp[u])
            {
                int v=z.second;
                int newedgecost=z.first;
                if(visited[v]==false&&newedgecost<safar[v])
                {
                    safar[v]=newedgecost;
                    parent[v]=u;
                    pq.push({newedgecost,v});
                }
            }
            
            
        }
        int ans=0;
        
        for(int i=0;i<V;i++)
        {
            ans+=safar[i];
        }
        return ans;
    }
};
