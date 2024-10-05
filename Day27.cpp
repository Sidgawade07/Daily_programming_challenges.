#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int shortestPath(int V, vector<pair<int, int>>& edges, int start, int end) {
    // Step 1: Build the adjacency list
    vector<vector<int>> graph(V);
    for (auto& edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since the graph is undirected
    }

    // Step 2: BFS initialization
    vector<bool> visited(V, false);
    queue<pair<int, int>> q; // pair of (node, distance)
    q.push({start, 0});
    visited[start] = true;

    // Step 3: BFS loop
    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        // If we reach the end node, return the distance
        if (node == end) {
            return distance;
        }

        // Explore neighbors
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, distance + 1});
            }
        }
    }

    // If BFS completes without finding the end node, return -1
    return -1;
}

int main() {
    // Test case 1
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0, end = 4;
    cout << "Shortest path length: " << shortestPath(V, edges, start, end) << endl; // Output: 3

    return 0;
}
