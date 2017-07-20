#include <bits/stdc++.h>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
int const maxn = 46500;
vi p;
vi factor;
void sieve(){
    bitset<maxn+5> bt;
    bt.set();
    bt[0] = bt[1] = 0;
    bt[2] = 1;
    p.push_back(2);
    for(int i = 4; i <= maxn; i += 2) bt[i] = 0;
    for(ll i = 3; i <= maxn; i += 2) if(bt[i]){
        p.push_back(i);
        for(ll j = i * i; j <= maxn; j+=i)
            bt[j] = 0;
    }
}

void solve(ll n){
    int root = (int)sqrt(n);
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i];
        while(n%v == 0) n/=v, factor.push_back(v);
    }
    if(n!=1) factor.push_back(n);
}

int main(){
    int n, sinal;
    sieve();
    while(scanf("%d",&n) && n != 0){
        sinal = 1;
        if(n < 0) sinal = -1;
        n = abs(n);
        factor.clear();
        solve(n);
        printf("%d = ",n*sinal);
        if(sinal == -1)
            printf("-1 x ");
        for(int i = 0; i < factor.size(); i++){
            if(i == factor.size() - 1)
                printf("%d\n",factor[i]);
            else
                printf("%d x ",factor[i]);
        }
    }
}
