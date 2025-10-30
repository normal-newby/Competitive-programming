#include <bits/stdc++.h>

using namespace std;

bool backtrack(vector<vector<int>>& directions, vector<int>& seen, vector<int>& curSeen, int cur){
    seen[cur] = true;
    curSeen[cur] = true;
    for (int dir : directions[cur]){
        if (curSeen[dir]) return true;
        if (seen[dir]) continue;
        if (backtrack(directions, seen, curSeen, dir)) return true;
    }
    curSeen[cur] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> directions(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x; cin >> x;
            if (x == 0) continue;
            directions[i].push_back(j);
        }
    }
    vector<int> seen(n, false), curSeen(n, false);
    for (int i = 0; i < n; i++){
        if (seen[i]) continue;
        if (backtrack(directions, seen, curSeen, i)){
            cout << "NO" << endl; 
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}