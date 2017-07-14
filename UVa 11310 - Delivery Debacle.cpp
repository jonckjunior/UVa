#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int v[50];
    v[0] = v[1] = 1;
    v[2] = 5;
    for(int i = 3; i <= 40; i++){
        v[i] = 2*v[i-1] + 2*v[i-2];
        if(i&1)
            v[i]--;
        else
            v[i]++;
    }
    int t, n;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d",&n);
        printf("%lld\n",v[n]);
    }
}
