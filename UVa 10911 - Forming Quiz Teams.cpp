#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vii pares;
int n;
double dp[20][(1 << 16) + 5];

int bit(int b){return (1 << b);}

double dist(const ii& a, const ii& b){
    return hypot(a.first - b.first, a.second - b.second);
}

double solve(int match, int used){
    if(match*2 == n) return 0;
    if(dp[match][used] != -1) return dp[match][used];
    double res = 1e9;
    for(int i = 0; i < n; i++) if(!(bit(i)&used))
        for(int j = i+1; j < n; j++) if(!(bit(j)&used))
            res = min(res, solve(match+1, used|bit(i)|bit(j)) + dist(pares[i], pares[j]));
    return dp[match][used] = res;
}

int main() {
    int caso = 0;
    while(cin >> n, n != 0){
        n = 2*n;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= (1 << 16); j++)
                dp[i][j] = -1;
        pares.clear();
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            int x,y;
            cin >> x >> y;
            pares.push_back(ii(x,y));
        }
        double res = solve(0, 0);
        printf("Case %d: %.2f\n",++caso,res);
    }

    return 0;
}
