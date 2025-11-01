#include <bits/stdc++.h>

using namespace std;

int dfs(vector<int>& pointer, vector<bool>& seen, int start, int& n){
    vector<bool> curSeen(n, false);
    stack<int> st;
    st.push(start);
    int length = 0;
    while(!st.empty()){
        int cur = st.top(); st.pop();
        if (curSeen[cur]) break;
        curSeen[cur] = true;
        length += 1;
        st.push(pointer[cur]);
    }
    for (int i = 0; i < n; i++){
        seen[i] = curSeen[i] || seen[i];
    }
    return length;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n; cin >> n;
        if (n == 0) break;
        vector<int> pointer(n);
        vector<bool> seen(n, false);
        vector<int> lengths;
        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            pointer[a] = b;
        }
        for (int i = 0; i < n; i++){
            if (seen[i]) continue;
            lengths.push_back(dfs(pointer, seen, i, n));
        }
        int curLCM = lcm(lengths[0], lengths[1]);
        for (int i = 2; i < lengths.size(); i++){
            curLCM = lcm(curLCM, lengths[i]);
        }
        cout << curLCM << "\n";
    }
    return 0;
}