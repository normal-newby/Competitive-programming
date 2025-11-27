/*
Given cows and wells, with each cow drinking from a well no bigger than them and no more than k smaller than them,
find minimum time for all cows to drink
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
/* ex: 5
10 13 13 24
8 14 20 22
*/

bool check(int limit, vector<int>& cows, vector<int>& heights){
    int cur = 0;
    int curCows = 0;
    for (int cow : cows){
        if (curCows == limit){
            cur++;
            curCows = 0;
        }
        if (cur >= m) return false;
        while (cur < m && !(heights[cur] >= cow-k && heights[cur] <= cow)){
            cur++;
            curCows = 0;
        }
        if (cur >= m) return false;
        curCows++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<int> cows(n);
    vector<int> heights(m);
    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < m; i++) cin >> heights[i];
    sort(cows.begin(), cows.end());
    sort(heights.begin(), heights.end());
    int lo = 1, hi = n+1, ans = -1;
    while (lo <= hi){
        int mid = (lo+hi)/2;
        if (check(mid, cows, heights)){
            ans = mid;
            hi = mid-1;
        } else lo = mid+1;
    }
    cout << (ans > n ? -1 : ans) << endl;
    return 0;
}