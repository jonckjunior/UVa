#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll Pow(ll x, ll y, ll p) {
    if(y == 0)
        return 1;
    if(y&1)
        return ((x%p)*Pow(((x%p)*(x%p)), y/2, p))%p;
    else
        return Pow(((x%p)*(x%p)), y/2, p)%p;
}

int main() {
    ll n,m,p;
    while(scanf("%lld %lld %lld",&n,&m,&p) != EOF)
        printf("%lld\n",Pow(n,m,p));
    return 0;
}
