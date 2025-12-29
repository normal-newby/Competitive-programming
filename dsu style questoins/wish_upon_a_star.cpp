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
        a = find(a), b = find(b);
        if (a == b) return false;
        parent[a] = b;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    DSU dsu(n);
    int components = n;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        if (dsu.unite(a,b)) components--;
    }
    cout << ((m == n-components || m == n-components+1) ? "YES" : "NO") << "\n";
    return 0;
}