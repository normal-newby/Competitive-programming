#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, nt;
    cin >> n >> nt;
    vector<pair<int, int>> trees;
    trees.push_back({-1, -1});
    cout << "\n";
    for (int i = 0; i < nt; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        trees.push_back({a, b});
    }
    int low = 0;
    for (auto[tr, tc] : trees){
        if (tr++ == n-1) continue;
        for (auto[lr, lc] : trees){
            if (lc++ == n-1) continue;
            int bottombounds = INT_MAX;
            int rightbounds = INT_MAX;
            for (auto[cr, cc] : trees){
                if (cr < tr || cc < lc) continue;
                int dr = cr - tr, dc = cc - lc;
                if (dr > dc){
                    rightbounds = min(rightbounds, dr);
                } else if (dr == dc){
                    rightbounds = min(rightbounds, dr);
                    bottombounds = min(bottombounds, dc);
                } else {
                    bottombounds = min(bottombounds, dc);
                }
            }
            bottombounds = min(bottombounds, n-tr);
            rightbounds = min(rightbounds, n-lc);
            //cout << tr << " " << lc << "\n";
            //cout << min(bottombounds, rightbounds) << "\n";
            low = max(low, min(bottombounds, rightbounds));
        }
    }
    cout << low << endl;
    return 0;
}