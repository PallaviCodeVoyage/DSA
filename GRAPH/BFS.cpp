#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs; // To store BFS traversal
        vector<bool> visited(V, false); // To mark nodes as visited

        // Start BFS from node 0 (assuming graph is connected and starts from node 0)
        queue<int> q;
        q.push(0); // Start from vertex 0
        visited[0] = true; // Mark node 0 as visited

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node); // Add the node to the BFS traversal result

            // Traverse all adjacent vertices of the dequeued node
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    q.push(it); // Enqueue the adjacent node
                    visited[it] = true; // Mark it as visited
                }
            }
        }

        return bfs; // Return the BFS traversal result
    }
};

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
            adj[u].push_back(v); // Directed graph
            // For undirected graph, uncomment the following line:
            // adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
