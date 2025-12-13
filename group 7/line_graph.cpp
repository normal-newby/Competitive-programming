#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i){
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return false;
        parent[a] = b;
        return true;
    }
};

typedef tuple<int, int, int> ti;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ti> edges;
    for (int i = 0; i < n-1; i++){
        int w; cin >> w;
        edges.push_back({w,i,i+1});
    }
    for (int i = n-k-1; i >= 0; i--){
        edges.push_back({0, i, i+k});
    }
    sort(edges.begin(), edges.end());
    int numEdges = 0, weight = 0;
    DSU dsu(n);
    for (auto& [w, u, v] : edges){
        if (numEdges == n-1) break;
        if (dsu.unite(u,v)){
            numEdges++;
            weight += w;
        }
    }
    cout << weight << "\n";
    return 0;
}
