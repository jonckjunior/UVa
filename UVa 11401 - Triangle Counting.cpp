#include <bits/stdc++.h>

using namespace std;

long long int v[1000001], s[1000001];

int main(){
    int n;
    memset(v, 0, sizeof v);
    v[3] = 0;
    long long int aux = 0;
    for(int i = 4; i <= 1000000; i++){
        if(i%2==0) aux++;
        s[i] = s[i-1] + aux;
        v[i] = v[i-1] + s[i];
    }
    while(scanf("%d",&n) && n >= 3){
        printf("%lld\n",v[n]);
    }
    return 0;
}
