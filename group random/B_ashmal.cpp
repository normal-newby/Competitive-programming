#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++){
        cin >> strings[i];
    }
    sort(strings.begin(), strings.end());
    for (string s : strings){
        cout << s;
    }
    cout << "\n";
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