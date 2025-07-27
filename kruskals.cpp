#include <iostream>
#include <vector>
using namespace std;

int find(int x, vector<int> p) 
{ 
    return p[x] = (p[x] == x ? x : find(p[x], p)); 
}

int main() {
    int n = 5;
    vector<tuple<int,int,int>> edges = {
        {2,0,1}, {4,0,2}, {1,1,2}, {7,1,3}, {3,2,4}, {1,3,4}
    };

    sort(edges.begin(), edges.end());
    vector<int> parent(n); 
    for (int i = 0; i < parent.size(); ++i)
    {
        parent[i] = i;
    }

    int cost = 0;
    for (auto edge : edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        if (find(u,parent) != find(v,parent)) {
            cost += w;
            parent[find(u,parent)] = find(v,parent);
        }
    }

    cout << "MST cost: " << cost << "\n";
}