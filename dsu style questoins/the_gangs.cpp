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
    void unite(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return;
        parent[a] = b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<int> enemy(n, -1);
    for (int i = 0; i < m; i++){
        char t; cin >> t;
        int a, b; cin >> a >> b;
        a--; b--;
        if (t == 'F'){
            dsu.unite(a, b);
        } else if (t == 'E'){
            if (enemy[a] != -1) dsu.unite(enemy[a], b);
            else enemy[a] = b;
            
            if (enemy[b] != -1) dsu.unite(enemy[b], a);
            else enemy[b] = a;
        }
    }
    set<int> gangs;
    for (int i = 0; i < n; i++){
        gangs.insert(dsu.find(i));
    }
    cout << gangs.size() << "\n";
    return 0;
}
