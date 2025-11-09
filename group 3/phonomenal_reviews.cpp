#include <bits/stdc++.h>

using namespace std;
int nodes;
void prune(vector<int>& phos, vector<int>& keep, vector<vector<int>>& adjs, int cur, int par){
    if (phos[cur]) keep[cur] = 1;
    for (int adj : adjs[cur]){
        if (adj == par) continue;
        prune(phos, keep, adjs, adj, cur);
        if (keep[adj]) keep[cur] = 1;
    }
    nodes += keep[cur];
}

void dfs(vector<vector<int>>& adjs, vector<int>& lengths, int cur, vector<int>& keep){
    for (int adj : adjs[cur]){
        if (lengths[adj] != -1 || keep[adj] == 0) continue;
        lengths[adj] = lengths[cur] + 1;
        dfs(adjs, lengths, adj, keep);
    }
}
pair<int, int> findLongestAndIdx(vector<int>& lengths, vector<int>& phos, vector<int>& keep){
    int ml = 0;
    int idx;
    for (int i = 0; i < lengths.size(); i++){
        if (keep[i] == 0) continue;
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
    vector<int> phos(n);
    for (int i = 0; i < m; i++){
        int a; cin >> a;
        phos[a] = true;
    }
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    vector<int> keep(n);
    int start;
    for (int i = 0; i < n; i++) if(phos[i]){start = i; break;}
    keep[start] = 1;
    prune(phos, keep, adjs, start, -1);


    vector<int> lengths(n, -1);

    lengths[start] = 0;
    dfs(adjs, lengths, start, keep);
    auto[_, idx] = findLongestAndIdx(lengths, phos, keep);
    fill(lengths.begin(), lengths.end(), -1);

    lengths[idx] = 0;
    dfs(adjs, lengths, idx, keep);
    auto[longest, finish] = findLongestAndIdx(lengths, phos, keep);
    
    cout << 2*(nodes-1) - longest << endl;
    return 0;
}