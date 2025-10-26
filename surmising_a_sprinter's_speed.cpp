#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long, long>> records;
    for (int i = 0; i < n; i++){
        long t, p; cin >> t >> p;
        records.push_back({t,p});
    }
    sort(records.begin(), records.end());
    double speed = 0.0;
    for (int i = 0; i < n-1; i++){
        speed = max(speed, (max(records[i+1].second, records[i].second) - min(records[i+1].second, records[i].second))/(max(records[i+1].first, records[i].first) - min(records[i+1].first, records[i].first) + 0.0));
    }
    cout << fixed << setprecision(5) << speed << endl;
    return 0;
}