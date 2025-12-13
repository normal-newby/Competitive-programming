#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int n){
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }
    bool unite(int a, int b){
        int ar = find(a), br = find(b);
        if (ar == br) return false;
        parent[ar] = br;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<int> ans;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        if (dsu.unite(a,b)){
            ans.push_back(i+1);
        }
    }
    set<int> forest;
    for (int& i : dsu.parent){
        forest.insert(dsu.find(i));
    }
    if (forest.size() > 1) cout << "Disconnected Graph\n";
    else for (int i : ans) cout << i << "\n";
    return 0;
}
