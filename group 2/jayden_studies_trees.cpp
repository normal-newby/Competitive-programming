#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(int start, vector<vector<int>> paths, int n){
    vector<int> dist(n, -1);
    dist[start] = 0;
    stack<int> st;
    st.push(start);
    while (!st.empty()){
        int cur = st.top(); st.pop();
        int d = dist[cur];
        vector<int> edges = paths[cur];
        for (int edge : edges){
            if (dist[edge] != -1) continue;
            st.push(edge);
            dist[edge] = d+1;
        }
    }
    int m = 0;
    for (int d : dist) m = max(m, d);
    int index;
    for (int i = 0; i < n; i++) if (dist[i] == m) {index = i; break;}
    return {m, index};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> paths(n, vector<int>());
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        paths[x].push_back(y);
        paths[y].push_back(x);
    }
    pair<int, int> info = dfs(0, paths, n);
    info = dfs(info.second, paths, n);
    cout << info.first << endl;
    return 0;
}