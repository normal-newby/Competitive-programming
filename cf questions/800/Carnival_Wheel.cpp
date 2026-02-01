#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, a, b; cin >> l >> a >> b;
    vector<bool> seen(l, 0);
    while (!seen[a]){
        seen[a] = 1;
        a += b;
        a %= l;
    }
    for (int i = l-1; i >= 0; i--){
        if (seen[i]){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}