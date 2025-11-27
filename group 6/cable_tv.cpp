/*
Find the minimum cost to connect all the houses, minimizing the cost but above all minimizing the number of dangerous links used.
*/

#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ti>> graph(n);
    vector<int> vis(n, 0);
    for (int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        graph[a].push_back({b,c,d});
        graph[b].push_back({a,c,d});
    }
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    int total = 0;
    int dangers = 0;
    pq.push({0,0,0});
    while (!pq.empty()){
        auto[d, c, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        total += c;
        dangers += d;
        vis[u] = 1;
        for (auto [nu, nc, nd] : graph[u]){
            if (vis[nu]) continue;
            pq.push({nd, nc, nu});
        }
    }
    cout << dangers << " " << total << endl;
    
    return 0;
}
