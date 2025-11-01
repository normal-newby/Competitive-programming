#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<pair<long long,long long>>> paths(n+1);
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        paths[a].push_back({b,c});
        paths[b].push_back({a,c});
    }
    long long totalDist = 0;
    for (auto location : paths){
        for (auto[dir, dist] : location){
            totalDist += dist;
        }
    }
    totalDist /= 2;
    vector<long long> dists(n+1, -1);
    dists[0] = 0;
    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int location = st.top(); st.pop();
        for (auto[dir, dist] : paths[location]){
            if (dists[dir] != -1) continue;
            st.push(dir);
            dists[dir] = dists[location] + dist;
        }
    }
    long long longest = 0;
    for (long long dist : dists){
        longest = max(longest, dist);
    }
    cout << totalDist*2 - longest << endl;
    return 0;
}