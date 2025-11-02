#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int>& adj, vector<int>& seen, vector<int>& curCycle, int cur){
    seen[cur] = 1;
    curCycle.push_back(cur);
    int nxt = adj[cur];
    if (!seen[nxt]) dfs(adj, seen, curCycle, nxt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> adj(n);
    for (int i = 0; i < n; i++){
        adj[i] = i;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        reverse(adj.begin()+a, adj.begin()+b);
    }
    vector<vector<int>> cycles;
    vector<int> seen(n, 0);
    for (int i = 0; i < n; i++){
        if (seen[i] != 0) continue;
        vector<int> curCycle;
        dfs(adj, seen, curCycle, i);
        cycles.push_back(curCycle);
    }
    vector<int> result(n);
    for (vector<int>& cycle : cycles){
        int s = cycle.size();
        for (int i = 0; i < s; i++){
            int pos = (i+k)%s;
            result[cycle[i]] = cycle[pos];
        }
    }
    for (int x : result){
        cout << x+1 << "\n";
    }
    return 0;
}