#include <bits/stdc++.h>
using namespace std;

int v[1001];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){

    while(scanf("%d",&v[0]) && v[0] != 0){
        int n = 1;
        while(scanf("%d",&v[n]), v[n] != 0) n++;

        int res = abs(v[1]-v[0]);
        for(int i = 1; i < n; i++)
            res = gcd(res, abs(v[i] - v[i-1]) );
        printf("%d\n",res);
    }
    return 0;
}
