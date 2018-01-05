#include <bits/stdc++.h>

using namespace std;

int v[100005], dp[100005];

int main() {
    string s; cin >> s;
    int len = s.size();
    for(int i = 0; i < len-1; i++)
        v[i] = (s[i] == s[i+1]);
    dp[0] = v[0];
    for(int i = 1; i < len-1; i++){
        dp[i] = dp[i-1] + v[i];
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int x,y; cin >> x >> y;
        x--;y--;
        cout << dp[y-1]-dp[x]+v[x] << endl;
    }
}
