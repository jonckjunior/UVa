#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxn = 1000000;
vi p;
bitset<maxn+5> bt;
int fact[1000001];
void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    p.push_back(2);
    int root = 1005;
    for(int i = 4; i <= maxn; i += 2) bt[i] = 0;
    for(int i = 3; i <= root; i += 2) if(bt[i]){
        for(int j = i * i; j <= maxn; j += i)
            bt[j] = 0;
    }
    for(int i = 3; i <= maxn; i += 2)
        if(bt[i])
            p.push_back(i);
}

int solve(int n){
    memset(fact,0,sizeof fact);
    for(int i = 0; i < p.size() && p[i] <= n; i++){
        long long int v = p[i];
        while(v <= n) v*=p[i], fact[i]++;
    }
    
    fact[0] -= fact[2];
    fact[2] -= fact[2];

    int ans = 1;

    for(int i = 0; i < p.size() && p[i] <= n; i++){
        if(i!=0 && i!=2)
            fact[i] %= 4;
        for(int j = fact[i]; j >= 1; j--)
            ans = (ans*p[i])%10;
    }
    return ans;
}

int main() {
    int n;
    sieve();
    while(scanf("%d",&n), n!=0)
        printf("%d\n",solve(n));
    return 0;   
}
