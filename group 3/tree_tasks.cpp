#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<pair<int, int>>>& adjs, vector<int>& lengths, int cur){
    for (auto adj : adjs[cur]){
        if (lengths[adj.first] != -1) continue;
        lengths[adj.first] = lengths[cur] + adj.second;
        dfs(adjs, lengths, adj.first);
    }
}
pair<int, int> findLongestAndIdx(vector<int>& lengths){
    int ml = 0;
    int idx;
    for (int i = 0; i < lengths.size(); i++){
        if (lengths[i] > ml){
            ml = lengths[i];
            idx = i;
        }
    }
    return {ml, idx};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<pair<int, int>>> adjs(n);
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adjs[a].push_back({b,c});
        adjs[b].push_back({a,c});
    }
    vector<int> lengths(n, -1);
    
    lengths[0] = 0;
    dfs(adjs, lengths, 0);
    auto[_, idx] = findLongestAndIdx(lengths);
    
    fill(lengths.begin(), lengths.end(), -1);
    lengths[idx] = 0;
    dfs(adjs, lengths, idx);
    auto[diameter, finish] = findLongestAndIdx(lengths);
    
    vector<int> lengths2(n, -1);
    lengths2[finish] = 0;
    dfs(adjs, lengths2, finish);
    
    int radius = INT_MAX;
    for (int i = 0; i < n; i++){
        radius = min(radius, max(lengths[i], lengths2[i]));
    }
    cout << diameter << endl;
    cout << radius << endl;
    return 0;
}