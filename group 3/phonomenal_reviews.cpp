#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adjs, vector<int>& lengths, int cur){
    for (int adj : adjs[cur]){
        if (lengths[adj] != -1) continue;
        lengths[adj] = lengths[cur] + 1;
        dfs(adjs, lengths, cur);
    }
}
pair<int, int> findLongestAndIdx(vector<int>& lengths, set<int>& phos){
    int ml = 0;
    int idx;
    for (int i = 0; i < lengths.size(); i++){
        if (!phos.count(i)) continue;
        if (lengths[i] > ml){
            ml = lengths[i];
            idx = i;
        }
    }
    return {ml, idx};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adjs(n);
    set<int> phos;
    int start;
    for (int i = 0; i < m; i++){
        int a; cin >> a;
        phos.insert(a);
        start = a;
    }
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    vector<int> lengths(m, -1);

    lengths[start] = 0;
    dfs(adjs, lengths, start);
    auto[_, idx] = findLongestAndIdx(lengths, phos);
    fill(lengths.begin(), lengths.end(), -1);

    lengths[idx] = 0;
    dfs(adjs, lengths, start);
    auto[longest, finish] = findLongestAndIdx(lengths, phos);

    int totalLength = 0;
    for (int length : lengths) totalLength += length;
    totalLength*=2;
    totalLength -= longest;
    
    cout << totalLength << endl;
    return 0;
}