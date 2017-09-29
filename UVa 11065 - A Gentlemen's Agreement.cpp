#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
#define bit(i) (1LL << (i))

int t,n,m, nS, mxS;
int const maxn = 62;
vector< ll > adj;

void solve(int i, ll used, int depth){
    //printf("%lld %lld %lld\n", i,used,depth);
    if(used == bit(n) - 1){
        nS++;
        mxS = max(mxS, depth);
    }
    else{
        for(ll j = i; j < n; j++)
            if(!(used & bit(j)))
                solve(j+1, used | adj[j], depth + 1);
    }
}

int main(){
    //ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(t--){
        //printf("here\n");
        scanf("%d %d",&n,&m);
        adj.assign(n+5, 0);
        for(int i = 0; i < n; i++)
            adj[i] = bit(i);
        for(int i = 0; i < m; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            adj[x] |= bit(y);
            adj[y] |= bit(x);
        }
        nS = 0;
        mxS = 0;
        solve(0,0,0);
        printf("%d\n", nS);
        printf("%d\n", mxS);
    }
    return 0;
}
