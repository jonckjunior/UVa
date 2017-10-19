#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
int const maxn = 2;
ll magic = 1e6;
ll k,l;
vvi matrixMult(const vvi &a, const vvi &b){
    vvi res(maxn, vi(maxn, 0));
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            for(int k = 0; k < maxn; k++)
                res[i][j] = (res[i][j]%magic + (a[i][k]%magic * b[k][j]%magic) )%magic;
    return res;
}

vvi matrixPow(vvi &base, ll p){
    vvi res(maxn, vi(maxn, 0));
    for(int i = 0; i < maxn; i++)
        res[i][i] = 1;
    while(p){
        if(p & 1) res = matrixMult(res, base);
        base = matrixMult(base,base);
        p >>= 1;
    }
    return res;
}

int main(){
    ll n;
    while(scanf("%lld %lld %lld",&n,&k,&l) != EOF){
        n/=5;
        vvi base(maxn, vi(maxn, 1));
        base[1][1] = 0;
        base[0][0] = k%magic;
        base[0][1] = l%magic;
        base = matrixPow(base, n);  
        printf("%06lld\n",base[0][0]%magic);
    }
    return 0;
}
