#include <bits/stdc++.h>

using namespace std; 

typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        for (int prime : primes){
            if (gcd(a, prime) == 1) smallest = min(smallest,prime);
        }
    }
    cout << (smallest == INT_MAX ? -1 : smallest) << "\n";
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