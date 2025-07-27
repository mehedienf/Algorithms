#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> g(n);
    g[0] = {{1,2},{2,4}};
    g[1] = {{0,2},{2,1},{3,7}};
    g[2] = {{0,4},{1,1},{4,3}};
    g[3] = {{1,7},{4,1}};
    g[4] = {{2,3},{3,1}};

    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int weight = 0;
    int node = 0;
    pq.push({weight, node});
    int cost = 0;

    while (!pq.empty()) {
        int w = pq.top().first; 
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cost += w;
        for (auto e : g[u])
        {
            if (!vis[e.first])
            {
                pq.push({e.second, e.first});
            }
        }
    }

    cout << "MST cost: " << cost << "\n";
}