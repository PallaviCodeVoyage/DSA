class Solution {
  public:
  vector<int>parent;
  vector<int>rank;
  int findd(int a)
  {
      if(parent[a]==a)return a;
      return parent[a]=findd(parent[a]);
  }
  bool dsu(int a,int b)
  {
      int ap=findd(a);
      int bp=findd(b);
      if(ap==bp)return false;
      if(rank[ap]>rank[bp])
      {
          parent[bp]=ap;
          
      }
      else if(rank[ap]<rank[bp])parent[ap]=bp;
      else
      {
           parent[bp]=ap;
           rank[ap]++;
          
      }
      return true;
      
  }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        sort(edges.begin(),edges.end(),[](const vector<int>a,const vector<int>b)
        {
            return a[2]<b[2];
            
        });//sort ho gya hain
        parent.assign(V,0);
        rank.assign(V,0);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
            
        }
        
        int ans=0;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            if(dsu(u,v))
            {
                ans+=wt;
            }
        }
        return ans;
    }
};
