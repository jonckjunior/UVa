#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
ll const maxn = 4294967294;
bitset<70000> bt;
vi p;
void sieve(){
    bt.set();
    int root = (int)sqrt(maxn);
    for(ll i = 2; i <= root; i++) if(bt[i]){
        p.push_back(i);
        for(ll j = i*i; j <= root; j += i)
            bt[j] = 0;
    }
}

ll numDivisor(ll n){
    int root = (int)sqrt(n);
    ll ans = 1;
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        ll v = (ll)p[i], power = 0;
        while(n%v==0) n/=v, power++;
        ans *= (power+1);
    }
    if(n!=1) ans *= 2;
    return ans;
}

int main() {
    ll n;
    sieve();
    while(scanf("%lld",&n), n!=0){
        ll res = numDivisor(n);
        if(res%2==1) printf("yes\n");
        else      printf("no\n");
    }
    return 0;
}
