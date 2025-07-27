// Breadth-First Search

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> adj, vector<bool> visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); 
        q.pop();
        cout << node << " ";

        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n = 9; // number of nodes
    vector<vector<int>> adj(n);
    
    // Sample undirected edges
    // adj[0] = {1, 2};
    // adj[1] = {0, 3};
    // adj[2] = {0, 4};
    // adj[3] = {1, 5};
    // adj[4] = {2};
    // adj[5] = {3};

    adj[1] = {2, 6};
    adj[2] = {3, 4};
    adj[3] = {};
    adj[4] = {5};
    adj[5] = {8};
    adj[6] = {7,9};
    adj[7] = {8};
    adj[8] = {5};
    adj[9] = {};

    vector<bool> visited(n, false);
    int start = 1; // Start BFS from node 1 
    bfs(start, adj, visited);

    return 0;
}