#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& relations, int start, int n, vector<int>& dists){
    dists[start] = 1;
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int cur = st.top(); st.pop();
        for (int person : relations[cur]){
            if (dists[person] != -1) continue;
            st.push(person);
            dists[person] = dists[cur]+1;
        }
    }
    int maxDist = 0;
    int idx = 0;
    for (int i = 0; i < n; i++){
        if (dists[i] > maxDist){
            maxDist = dists[i];
            idx = i;
        }
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> relations(n);
    for (int i = 0; i < n-1; i++){
        int p1, p2;
        cin >> p1 >> p2;
        p1--, p2--;
        relations[p1].push_back(p2);
        relations[p2].push_back(p1);
    }
    vector<int> buffer(n, -1);
    vector<int> firstDistance(n, -1);
    vector<int> secondDistance(n, -1);
    int firstDfs = dfs(relations, 0, n, buffer);
    int secondDfs = dfs(relations, firstDfs, n, firstDistance);
    int thirdDfs = dfs(relations, secondDfs, n, secondDistance);
    for (int i = 0; i < n; i++){
        cout << max(firstDistance[i], secondDistance[i]) << "\n";
    }
    return 0;
}