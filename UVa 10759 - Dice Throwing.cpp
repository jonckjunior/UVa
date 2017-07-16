#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;

int n,x;
long long int dp[25][155];

long long int gcd(long long int a, long long int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long int solve(int left, int score){
    if(left == 0) return score >= x;
    if(dp[left][score] != -1) return dp[left][score];
    long long int ans = 0;
    for(int i = 1; i <= 6; i++)
        ans += solve(left - 1, score + i);
    return dp[left][score] = ans;
}

int main(){
    while(scanf("%d %d",&n,&x), n+x != 0){
        memset(dp,-1,sizeof dp);
        long long int low = ceil(pow(6,n));
        long long int high = solve(n,0);
        long long int fator = gcd(low,high);
        if(high == low) printf("1\n");
        else if(high == 0) printf("0\n");
        else printf("%lld/%lld\n",high/fator, low/fator);
    }    
}
