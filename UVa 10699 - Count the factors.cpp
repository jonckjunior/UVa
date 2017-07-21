#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
int const maxn = 1000000;
vi p;
int dp[maxn+5];
void sieve(){
    memset(dp, 0, sizeof dp);
    for(ll i = 2; i <= maxn; i++) if(dp[i] == 0)
        for(ll j = i; j <= maxn; j+=i)
            dp[j]++;
}

int main() {
    int n;
    sieve();
    while(scanf("%d",&n), n!=0)
        printf("%d : %d\n",n,dp[n]);
    return 0;
}
