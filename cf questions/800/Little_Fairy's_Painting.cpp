#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    set<int> colours;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        colours.insert(a);
    }
    int ans = *upper_bound(colours.begin(), colours.end(), colours.size()-1);
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