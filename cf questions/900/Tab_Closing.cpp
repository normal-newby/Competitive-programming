#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long a, b, n; cin >> a >> b >> n;
    long long m = n*b;
    if (m <= a || a == b) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
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