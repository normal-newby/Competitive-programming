#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parent;

int find_set(int i){
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if (!parent.count(a)) parent[a] = a;
        if (!parent.count(b)) parent[b] = b;
        a = find_set(a);
        b = find_set(b);
        if (a != b){
            parent[a] = b;
            n--;
        }
    }
    cout << n << "\n";
    return 0;
}
