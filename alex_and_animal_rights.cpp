#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    vector<pair<int, int>> monkeys;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'M'){
                monkeys.push_back({i,j});
            }
        }
    }
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int cages = 0;
    for (auto[sr, sc] : monkeys){
        if (grid[sr][sc] == '#') continue;
        queue<pair<int, int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto[cr, cc] = q.front(); q.pop();
            for (auto[dr, dc] : dirs){
                int nr = cr + dr, nc = cc + dc;
                if (nr < 1 || nr >= r-1 || nc < 1 || nc >= c-1) continue;
                if (grid[nr][nc] == '#') continue;
                q.push({nr,nc});
                grid[nr][nc] = '#';
            }
        }
        cages++;
    }
    cout << cages << endl;
    return 0;
}