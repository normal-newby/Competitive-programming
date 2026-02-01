#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, int> edge;
typedef tuple<ll, ll, int, int> undirect;
typedef pair<ll, ll> pi;

int n, m;

ll dijk(int start, int end, vector<vector<edge>>& edges){
    vector<ll> dists(n, LLONG_MAX);
    vector<bool> vis(n, 0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,start});
    dists[start] = 0;
    while (!pq.empty()){
        auto [l, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == end) return l;
        for (auto [nl, _, v] : edges[u]){
            if (dists[v] <= l + nl) continue;
            dists[v] = l + nl;
            pq.push({dists[v], v});
        }
    }
    return LLONG_MAX;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<edge>> edges(n);
    vector<undirect> all;
    for (int i = 0; i < m; i++){
        ll u, v, l, c; cin >> u >> v >> l >> c;
        u--; v--;
        all.push_back({l,c,u,v});
        all.push_back({l,c,v,u});
    }
    sort(all.begin(), all.end());
    ll total = 0;
    for (undirect& e : all){
        auto [l, c, u, v] = e;
        ll shortest = dijk(u, v, edges);
        if (shortest <= l) continue;
        total += c;
        edges[u].push_back({l, c, v});
        edges[v].push_back({l,c,u});
    }
    cout << total << "\n";
    return 0;
}