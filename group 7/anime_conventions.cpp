#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find (int i){
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int a, int b){
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        parent[ra] = rb;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    DSU dsu(n);
    for (int i = 0; i < q; i++){
        char c; cin >> c;
        int a, b; cin >> a >> b;
        a--; b--;
        if (c == 'A') dsu.unite(a,b);
        else {
            if (dsu.find(a) == dsu.find(b)) cout << 'Y';
            else cout << 'N';
            cout << '\n';
        }
    }
    return 0;
}
