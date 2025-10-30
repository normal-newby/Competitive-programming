#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n; cin >> n;
    vector<long> s(n), a(n+2);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    a[0] = a[1] = a[2] = 0;
    long high0 = 0, high1 = 0, high2 = 0;
    for (int i = 3; i < n+2; i++){
        a[i] = s[i-2] - s[i-3] + a[i-3];
        if (a[i] < 0){
            if (i%3 == 0) high0 = max(high0, abs(a[i]));
            else if (i%3 == 1) high1 = max(high1, abs(a[i]));
            else if (i%3 == 2) high2 = max(high2, abs(a[i]));
        }
    }
    for (int i = 0; i < n+2; i++){
        if (i%3 == 0) a[i] += high0;
        else if (i%3 == 1) a[i] += high1;
        else if (i%3 == 2) a[i] += high2;
    }
    if (high0 + high1 + high2 > s[0]){
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        int sum = a[i] + a[i+1] + a[i+2];
        if (sum < s[i]){
            a[i+2] += s[i] - sum;
        }
    }
    cout << "Yes" << "\n";
    for (int i : a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}