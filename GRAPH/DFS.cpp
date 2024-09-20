//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int>ans;
    void solve(int n,vector<int>adj[],int u,vector<bool>&visited)
    {
        visited[u]=true;
        ans.push_back(u);
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                solve(n,adj,v,visited);
            }
            
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>v(V,false);
        for(int i=0;i<V;i++)//also the concern or situation if the graph is not connected taken care
        {
            if(v[i]==false)
            {
                solve(V,adj,i,v);
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
