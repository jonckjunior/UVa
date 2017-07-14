#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    int caso = 0;
    while(scanf("%lld",&n) && n != 0){
        long long int res = (1 + sqrt(1 + 8*n))/2 + 2;
        printf("Case %d: %lld\n",++caso,res);
    }
}
