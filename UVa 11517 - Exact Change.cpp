#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool func(const int &a, const int &b){
    return a > b;
}

int price, n, numcoin[105];
ii DP[105][10005];
ii solve(int id, int change, int nc){
    if(change >= price)         return ii(change,nc);
    if(id == n)                 return ii(INF,INF);
    ii &value = DP[id][change];
    if(value != ii(-1,-1) )     return ii(value.first, value.second + nc);
    return value = min(solve(id+1,change,nc), solve(id+1,change + numcoin[id], nc+1));
} 

int main(){
    ios::sync_with_stdio(false);
    int t,i;
    cin >> t;
    while(t--){
        cin >> price >> n;
        for(i = 0; i < n; i++) cin >> numcoin[i];
        memset(DP, -1, sizeof DP);
        sort(numcoin, numcoin+n, func);
        ii ans = solve(0,0,0);
        cout << ans.first << " " << ans.second << endl;
    }
}
