#include <bits/stdc++.h>

using namespace std;

#define VERTICAL 1
#define HORIZONTAL 2
#define MATCH 3
#define REPLACE 4

int dp[105][105];
vector<string> vs;

int solve(string a, string b){
    memset(dp, 0, sizeof dp);
    int n = a.size(), m = b.size();
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int &v = dp[i][j];
            v = dp[i-1][j-1] + (a[i-1] == b[j-1] ? 1 : -1e9);
            v = max(v, dp[i-1][j]);
            v = max(v, dp[i][j-1]);
        }
    return dp[n][m];
}
int main(){
    string a,b;
    int caso = 0;
    while(getline(cin, a), a != "#"){
         getline(cin, b);
         int res = solve(a,b);
         printf("Case #%d: you can visit at most %d cities.\n",++caso, res);
    }
    return 0;
}
