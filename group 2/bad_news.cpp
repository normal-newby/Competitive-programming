#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs = {{1,1}, {1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

bool canFind(string word, vector<vector<char>> grid, int n){
    int len = word.length()-1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == tolower(word[0])){
                // r, c, l, vector(seen)
                stack<tuple<int, int, int, vector<pair<int, int>>>> st;
                st.push({i, j, 0, {{i,j}}});
                while (!st.empty()){
                    auto[cr, cc, l, seen] = st.top(); st.pop();
                    if (l == len) return true;
                    l++;
                    for (auto[dr, dc] : dirs){
                        int nr = cr+dr, nc = cc+dc;
                        bool cond = false;
                        for (auto[sr, sc] : seen) if (sr == nr && sc == nc){cond = true; break;}
                        if (cond) continue;
                        if (nr<0 || nr>=n || nc<0 || nc>=n) continue;
                        if (grid[nr][nc] != tolower(word[l])) continue;
                        vector<pair<int, int>> newSeen = seen;
                        newSeen.push_back({nr,nc});
                        st.push({nr, nc, l, newSeen});
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            grid[i][j] = tolower(grid[i][j]);
        }
    }
    for (int i = 0; i < q; i++){
        string word; cin >> word;
        if (canFind(word, grid, n)) cout << "good puzzle!" << "\n";
        else cout << "bad puzzle!" << "\n";
    }
    return 0;
}