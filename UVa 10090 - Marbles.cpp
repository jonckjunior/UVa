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
    ll n,c1,n1,c2,n2;
    while(scanf("%lld",&n) , n!=0){
        scanf("%lld %lld",&c1,&n1);
        scanf("%lld %lld",&c2,&n2);
        if(n%gcd(n1,n2) != 0) printf("failed\n");
        else{
            extendedEuclid(n1,n2);
            ll div = gcd(n1,n2);
            n /= div;n1 /= div;n2 /= div;
            x *= n; y *= n;
            ll lower = ceil(-(double) x / n2), upper = floor((double) y/n1);
            if(lower > upper){
                printf("failed\n");
                continue;
            }
            ll x1 = x + n2*lower;
            ll y1 = y - n1*lower;
            ll x2 = x + n2*upper;
            ll y2 = y - n1*upper;
            if(x1*c1 + y1*c2 < x2*c1 + y2*c2)
                printf("%lld %lld\n",x1,y1);
            else
                printf("%lld %lld\n",x2,y2);
        }
    }
    return 0;
}
