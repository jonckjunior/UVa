#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxn = 1000000;
vi p;
int dp[maxn+5], sum[maxn+5];
void sieve(){
    memset(dp, 0, sizeof dp);
    memset(sum,0, sizeof sum);
    dp[1] = 1;
    for(ll i = 2; i <= maxn; i++) if(dp[i] == 0)
        for(ll j = i; j <= maxn; j+=i){
            if(dp[j]==-1) continue;
            int orig = j, c = 0;
            while(orig%i==0 && c <= 1) orig/=i, c++;
            if(c > 1) dp[j] = -1;
            else      dp[j]++;
        }
    sum[1] = 1;
    for(ll i = 2; i <= maxn; i++){
        int aux = 0;
        if(dp[i] == -1) dp[i] = 0;
        else if(dp[i]%2==0) aux = dp[i] = 1;
        else aux = dp[i] = -1;
        sum[i] = sum[i-1] + aux;        
    }
}

int main() {
    int n;
    sieve();
    while(scanf("%d",&n), n!=0){
        printf("%8d%8d%8d\n",n,dp[n],sum[n]);
    }
    return 0;
}
