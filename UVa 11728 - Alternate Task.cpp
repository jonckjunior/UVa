#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxn = 1000000000;
vi p;
bitset<32000> bt;
int dp[1005];
void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    int root = (int)sqrt(maxn);
    p.push_back(2);
    for(int i = 3; i <= root; i+=2) if(bt[i]){
        p.push_back(i);
        for(int j = i*i; j <= root; j+=i)
            bt[j] = 0;
    }
}

int sumFactor(int n){
    int ans = 1;
    int root = sqrt(n);
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i], power = 0;
        while(n%v==0) n/=v, power++;
        ans *= ((int)pow(v, power+1.0)-1)/(v-1);
    }
    if(n!=1) ans*= ((int)pow(n, 2.0)-1)/(n-1);
    return ans;
}

int main() {
    int n,caso=0;
    sieve();
    memset(dp,-1,sizeof dp);
    for(int i = 1; i <= 1000; i++){
        int ans = sumFactor(i);
        if(ans <= 1000) dp[ans] = i;
    }

    while(scanf("%d",&n), n!=0)
        printf("Case %d: %d\n",++caso,dp[n]);
    return 0;
}
