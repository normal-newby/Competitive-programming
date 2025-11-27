/*
Given: an undirected graph.
How many edges must you remove to make it a tree? (Or a forest of trees?)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a; cin >> a;
            if (a) graph[i].push_back(j);
        }
    }
    
    int total = 0;
    vector<int> seen(n, 0);
    for (int i = 0; i < n; i++){
        if (seen[i]) continue;
        vector<int> nodes;
        stack<int> st;
        st.push(i);
        seen[i] = 1;
        while (!st.empty()){
            int cur = st.top(); st.pop();
            nodes.push_back(cur);
            for (int adj : graph[cur]){
                if (seen[adj]) continue;
                st.push(adj);
                seen[adj] = true;
            }
        }
        int totalEdge = 0;
        for (int node : nodes) totalEdge += graph[node].size();
        totalEdge /= 2;
        total += totalEdge - (nodes.size() - 1);
    }
    cout << total << endl;
    
    return 0;
}