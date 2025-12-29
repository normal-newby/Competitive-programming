#include <bits/stdc++.h>

using namespace std;

string r;

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
        if (a == b || r[a] != r[b]) return false;
        parent[a] = b;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; 
    cin >> n >> m >> k >> r;
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        dsu.unite(a,b);
    }
    int cnt = 0;
    for (int i = 0; i < k; i++){
        int a, b; cin >> a >> b; a--; b--;
        a = dsu.find(a), b = dsu.find(b);
        if (a == b) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
