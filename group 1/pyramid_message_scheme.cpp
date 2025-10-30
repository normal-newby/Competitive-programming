#include <bits/stdc++.h>

using namespace std;

struct Zombie{
    int row;
    string name;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, n;
    cin >> l;
    for (int i = 0; i < l; i++){
        cin >> n;
        int cnt = 0;
        vector<string> names(n);
        for (int i = 0; i < n; i++){
            cin >> names[i];
        }
        vector<Zombie> zombies;
        Zombie z;
        z.row = 0;
        z.name = names[names.size()-1];
        zombies.push_back(z);
        for (int i = 0; i < n; i++){
            string name = names[i];
            Zombie z;
            z.name = name;
            bool cond = false;
            for (Zombie zz : zombies){
                if (zz.name == z.name){
                    z.row = zz.row + 1;
                    cnt = zz.row;
                    cond = true;
                    zombies.push_back(z);
                    break;
                }
            }
            if (cond) continue;
            z.row = ++cnt;
            zombies.push_back(z);
        }
        int m = 0;
        for (Zombie z : zombies){
            m = max(m, z.row);
        }
        cout << n*10 - m*20 << endl;
    }
    
    return 0;
}