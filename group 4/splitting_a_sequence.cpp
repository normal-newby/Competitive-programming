#include <bits/stdc++.h>

using namespace std;

int n, m;

bool check(vector<int>& a, long long limit){
    long long sum = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        if (sum + a[i] > limit){
            sum = a[i];
            cnt++;
        } else {
            sum += a[i];
        }
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long lo = 0, hi = 0, ans = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        lo = min(lo, (long long)(a[i]));
        hi += a[i];
    }
    while (lo <= hi){
        long long mid = (lo + hi)/2;
        if (check(a, mid)) {
            ans = mid;
            break;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}