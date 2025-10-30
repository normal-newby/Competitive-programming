#include <bits/stdc++.h>

using namespace std;

void printGrid(vector<vector<int>>grid, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c, pixels;
    cin >> r >> c >> pixels;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    vector<vector<int>> dist(r, vector<int>(c, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            int a; cin >> a;
            if (a > 0){
                grid[i][j] = a;
                q.push({i,j});
            }
            else dist[i][j] = -1;
        }
    }
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()){
        auto[cr, cc] = q.front(); q.pop();
        int pixel = grid[cr][cc];
        int distance = dist[cr][cc];
        if (distance == pixels) continue;
        for (auto[dr, dc] : dirs){
            int nr = cr+dr, nc = cc+dc;
            if (nr<0 || nr>=r || nc<0 || nc>=c) continue;
            if (dist[nr][nc] == -1){ //base case
                grid[nr][nc] = pixel;
                dist[nr][nc] = distance + 1;
                q.push({nr, nc});
            }
            else if (dist[nr][nc] == distance+1){ //case for same distance
                if (grid[nr][nc] < pixel) continue;
                grid[nr][nc] = pixel;
            }
        }
    }
    printGrid(grid, r, c);
    
    return 0;
}