#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ans = min(ans + s, s + ans);
    }
    cout << ans << "\n";
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