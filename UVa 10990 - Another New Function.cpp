#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxn = 2000000;
vi p;
ll bt[maxn+5], sum[maxn+5], dp[maxn+5];

ll solve(int n){
    if(n==1) return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = solve(bt[n]) + 1;
}

void sieve(){
    bt[0] = 0;
    for(int i = 1; i <= maxn; i++) bt[i] = i;
    for(ll i = 2; i <= maxn; i++)
        if(bt[i] == i)
            for(ll j = i ; j <= maxn; j+=i)
                bt[j] = (bt[j]/i) * (i-1);
}


int main() {
    int t,n,m;
    memset(dp,-1,sizeof dp);
    sieve();
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        long long int sum = 0;
        for(int i = m; i <= n; i++){
            ll ans = solve(i);
            sum += ans;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
