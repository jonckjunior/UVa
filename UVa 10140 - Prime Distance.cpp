#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;

int const maxn = 20000000;
int v[maxn],p[maxn];
int main(){
    int root,pos=1,n;
    root = sqrt(20000000);
    memset(p, 1, sizeof p);
    p[0] = p[1] = 0;
    for(int i = 2; i <= root; i++){
        if(p[i]){
            for(int j = i+i; j <= maxn; j+=i)
                p[j] = 0;
        }
    }
    for(int i = 3; i < maxn; i++)
        if(p[i] && p[i+2]) v[pos++] = i;
    while(scanf("%d",&n) != EOF)
        printf("(%d, %d)\n",v[n], v[n]+2);
}
