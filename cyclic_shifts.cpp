#include <bits/stdc++.h>

using namespace std;

int main() {
    string t, s;
    cin >> t >> s;
    int l = s.length();
    for (int i = 0; i < l; i++){
        string news = "";
        for (int j = 0; j < l; j++){
            news += s[(i+j)%l];
        }
        if (t.find(news) != string::npos){
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}