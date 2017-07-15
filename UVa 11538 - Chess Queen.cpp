#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    while(scanf("%d %d",&n,&m) && n+m!=0){
        long long int res = 0;
        long long int m1 = min(n,m);
        long long int m2 = max(n,m);
        res = m1*m2*(m2-1);
        res += m2*m1*(m1-1);
        res += 4*((m1*(m1-1)*(2*m1-1))/6-(m1*(m1-1))/2);
        res += 2LL*(m2-m1+1)*m1*(m1-1);
        printf("%lld\n",res);
    }
}
