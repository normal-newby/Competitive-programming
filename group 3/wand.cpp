#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> wins(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        wins[b].push_back(a);
    }
    if (wins[0].size() == 0){
        cout << 1;
        for (int i = 0; i < n-1; i++) cout << 0;
        cout << "\n";
        return 0;
    }
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for (int adj : wins[cur]){
            if (visited[adj]) continue;
            visited[adj] = 1;
            q.push(adj);
        }
    }
    for (int v : visited) cout << v;
    return 0;
}