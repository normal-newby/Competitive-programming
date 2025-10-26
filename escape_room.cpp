#include <bits/stdc++.h>

using namespace std;
int m;
int n;
int input;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> m;
    cin >> n;
    int room[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> room[i][j];
        }
    }
    int target = room[m-1][n-1];
    stack<pair<int, int>> st;
    st.push({0, 0});
    while (!st.empty()){
        auto[a, b] = st.top(); st.pop();
        if (a == m-1 && b == n-1){
            cout << "yes" << endl;
            return 0;
        }
        int x = room[a][b];
        room[a][b] = 0;
        for (int i = 1; i <= sqrt(x); i++){
            if (x % i == 0){
                int nc1 = x/i-1, nc2 = i-1;
                if (!(nc1 >= m || nc2 >= n)){
                    if (room[nc1][nc2] != 0){
                        st.push({nc1, nc2});
                    }
                }
                if (!(nc2 >= m || nc1 >= n)){
                    if (room[nc2][nc1] != 0) {
                        st.push({nc2, nc1}); 
                    }
                }
            }
        }
    }
    cout << "no" << endl;
    return 0;
}