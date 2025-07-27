#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0] = {{1,2},{2,4}};
    adj[1] = {{2,1},{3,7}};
    adj[2] = {{4,3}};
    adj[3] = {{4,1}};

    vector<int> d(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[0] = 0; 
    pq.push({0,0});

    while (!pq.empty()) {
        pair<int, int> top = pq.top(); 
        pq.pop();
        int dist = top.first;
        int u = top.second;
        
        if (dist > d[u]) continue;
        
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    
    return 0;
}