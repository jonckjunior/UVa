#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int const maxn = 60000;
vi p;
int value[maxn+5];

void sieve(){
    bitset<maxn+5> bt;
    bt.set();
    bt[0] = bt[1] = 0;
    p.push_back(2);
    for(int i = 4; i <= maxn; i+=2) bt[i] = 0;
    for(ll i = 3; i <= maxn; i+=2) if(bt[i]){
        p.push_back(i);
        for(ll j = i*i; j <= maxn; j+=i)
            bt[j] = 0;
    }
}

vii factor(int n){
    vii fct;
    int root = (int)sqrt(n);
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i], c=0;
        while(n%v == 0) n/=v, c++;
        if(c)
            fct.push_back(ii(v,c));
    }
    if(n!=1) fct.push_back(ii(n,1));
    return fct;
}

bool solve(int n, int m){
    if(m <= n) return true;
    vii fct = factor(m);
    for(int i = 0; i < fct.size(); i++){
        int v = fct[i].first, c = fct[i].second;
        int count = 0;
        for(int i = v; i <= n && count < c; i+=v){
            int nn=i;
            while(nn%v == 0) nn/=v, count++;
        }
        if(count < c) return false;
    }
    return true;
}

int main(){
    int n,m;
    sieve();
    while(scanf("%d %d",&n,&m) != EOF){
        memset(value,0,sizeof value);
        bool res = solve(n,m);
        if(res) printf("%d divides %d!\n",m,n);
        else    printf("%d does not divide %d!\n",m,n);
    }
    return 0;
}
