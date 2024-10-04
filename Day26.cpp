#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool containsCycle(int V, vector<pair<int, int>>& edges) {
    // Create an adjacency list for the graph
    vector<vector<int>> adj(V);
    
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    
    // Visited array to keep track of visited nodes
    vector<bool> visited(V, false);
    
    // Check for cycles in each component of the graph
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    // Example 1
    int V1 = 5;
    vector<pair<int, int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << (containsCycle(V1, edges1) ? "true" : "false") << endl;
    
    // Example 2
    int V2 = 3;
    vector<pair<int, int>> edges2 = {{0, 1}, {1, 2}};
    cout << (containsCycle(V2, edges2) ? "true" : "false") << endl;
    
    // Example 3
    int V3 = 1;
    vector<pair<int, int>> edges3 = {};
    cout << (containsCycle(V3, edges3) ? "true" : "false") << endl;
    
    // Example 4
    int V4 = 4;
    vector<pair<int, int>> edges4 = {{0, 1}, {1, 2}, {2, 3}};
    cout << (containsCycle(V4, edges4) ? "true" : "false") << endl;

    return 0;
}
