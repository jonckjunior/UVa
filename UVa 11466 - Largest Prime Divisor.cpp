#include <bits/stdc++.h>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi p;
int const maxn = 10000000;
bitset<maxn + 5> bt;
void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    bt[2] = 1;
    p.push_back(2);
    for(int i = 4; i <= maxn; i+=2) bt[i] = 0;
    for(ll i = 3; i <= maxn; i+=2) if(bt[i]){        
        p.push_back(i);
        for(ll j = i*i; j <= maxn; j+=i)
            bt[j] = 0;
    }
}

ll solve(ll n){
    int root = (int)sqrt(n), dif = 0;
    ll res = 1, orig = n;
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i];
        if(n%v == 0) dif++, res = v;
        while(n%v == 0) n /= v;
    }
    if(n!=1) res = n, dif++;
    if(dif <= 1) res = orig;
    return res;
}

int main(){
    sieve();
    ll n;
    while(scanf("%lld",&n), n!=0){
        n = abs(n);
        ll res = solve(n);
        printf("%lld\n", res == n ? -1 : res);
    }
    return 0;
}
