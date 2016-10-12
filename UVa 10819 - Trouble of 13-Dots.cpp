#include <bits/stdc++.h>
#define INF 1e9
#define W first
#define VA second
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int DP[105][12000],n,b;
vii V;

int solve(int u, int w){
    if(w > b && !(w > 2000 && w-b <= 200)) return -INF;
    if(u == n) return 0;
    int &value = DP[u][w];
    if(value != -1) return value;
    value = max(solve(u+1,w),solve(u+1,w+V[u].W) + V[u].VA);
    return value;
}

int main(){
    int x,y;
    //ios::sync_with_stdio(false);
    while(cin >> b >> n){
        V.clear();
        for(int i =0 ; i < n; i++){
            cin >> x >> y;
            V.push_back(ii(x,y));
        }
        sort(V.begin(),V.end());
        memset(DP,-1,sizeof DP);      
        cout << solve(0,0) << endl;
    }
}
