#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll x,y,d;

ll gcd(ll a, ll b){if(a%b == 0) return b;return gcd(b, a%b);}

void extendedEuclid(ll a, ll b){
    if(b==0) {x = 1; y = 0; d = a; return;}
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int main() {
    ll a,b;
    while(scanf("%lld %lld",&a,&b) != EOF){
        extendedEuclid(a,b);
        printf("%lld %lld %lld\n",x,y,d);
    }
    return 0;
}
