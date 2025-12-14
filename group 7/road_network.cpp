#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef tuple<double, int, int> ti;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pi> coords;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        coords.push_back({a,b});
    }
    vector<ti> edges;
    for (int i = 0; i < n; i++){
    auto& [x1, y1] = coords[i];
        for (int j = i+1; j < n; j++){
            auto& [x2, y2] = coords[j];
            double weight = hypot(x2-x1, y2-y1);
            edges.push_back({weight,i,j});
        }
    }
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        edges.push_back({0,a,b});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int used = 0;
    double cost = 0;
    for (auto& [w,u,v] : edges){
        if (used == n-1) break;
        if (dsu.unite(u,v)){
            cost += w;
            used++;
        }
    }
    cout << fixed << setprecision(2) << cost << "\n";
    return 0;
}
