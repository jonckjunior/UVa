#include <bits/stdc++.h>
using namespace std;

long long int v[80];

int main() {
    long long int n;
    int caso = 0;
    memset(v, 0, sizeof v);
    v[0] = v[1] = 1;
    v[2] = v[3] = 2;
    v[4] = 3;
    for(int i = 5; i <= 76; i++)
        v[i] = v[i-1] + v[i-5];
    while(scanf("%lld",&n) != EOF){
        printf("%lld\n",v[n]);
    }
}
