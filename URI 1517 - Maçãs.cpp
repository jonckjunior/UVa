#include <bits/stdc++.h>

using namespace std;
int const max_v = 30, max_t = 1005;


int n, m, k, tmaxi;
int res[max_v][max_v][max_t], DP[max_v][max_v][max_t*2];

bool valid(int x, int y, int t){
    if(x < 0 || x >= n || y < 0 || y >= m || t > tmaxi) return false;
    else                                                return true;
}

int solve(int x, int y, int t){
    int &value = DP[x][y][t];
    if(value != -1) return value;
    int ans = 0;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int xx = x + i, yy = y + j, tt = t+1;
            if(valid(xx, yy, tt)){
                ans = max(ans, solve(xx,yy,tt));
            }
        }
    }

    return value = ans + res[x][y][t];
}

int main(){
    int x, y, t;
    while(cin >> n >> m >> k && n+m+k != 0){
        tmaxi = -1;
        memset(res, 0, sizeof res);
        memset(DP, -1, sizeof DP);
        for(int i = 0; i < k; i++){
            cin >> x >> y >> t;
            x--;y--;
            tmaxi = max(tmaxi, t);
            res[x][y][t] = 1;
        }
        cin >> x >> y;
        x--;y--;
        cout << solve(x,y,0) << endl;
    }
    return 0;
}
