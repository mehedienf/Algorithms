// Depth-First Search

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> adj, vector<bool> visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i : adj[node]) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }
}

int main() {
    int n = 6; // Number of nodes (0 to 5)
    vector<vector<int>> adj(n);

    // Build the graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {2};
    adj[5] = {3};

    vector<bool> visited(n, false);
    dfs(0, adj, visited); // Start DFS from node 0

    return 0;
}