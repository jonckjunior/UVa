#include <bits/stdc++.h>
using namespace std;
int v[11];
int main() {
    int n;
    v[0] = 1;
    for(int i = 1; i <= 10; i++)
        v[i] = (v[i-1]*2*i*(2*i-1))/(i*(i+1));
    int first = 1;
    while(scanf("%d",&n) != EOF){
        if(!first) printf("\n");
        printf("%d\n",v[n]);
        first = 0;
    }
}
