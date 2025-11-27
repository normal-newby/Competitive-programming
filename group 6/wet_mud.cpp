/*
Minimum time to get to other side of trail
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> j;
    if (j == 0){
        cout << -1 << "\n";
        return 0;
    }
    vector<int> trail(n+2, INT_MAX);
    trail[n+1] = 0;
    int hi = 0;
    for (int i = 0; i < m; i++){
        int p, t;
        cin >> p >> t;
        hi = max(hi, t);
        trail[p] = t;
    }
    int cur = 0;
    int t_elapsed = 0;
    while (cur <= n){
        bool jumped = false;
        for (int i = min(cur+j, n+1); i > cur; i--){
            if (trail[i] <= t_elapsed){
                cur = i;
                jumped = true;
                break;
            }
        }
        if (jumped) continue;
        t_elapsed++;
        if (t_elapsed > n+hi) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    cout << t_elapsed << '\n';
    return 0;
}
