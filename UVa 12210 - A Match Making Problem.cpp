#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int boys[10005], girls[10005];

int main() {
    int n,m,caso=0;
    while(cin >> n >> m && n+m != 0){
        for(int i = 0; i < n; i++)
            scanf("%d",&boys[i]);
        for(int i = 0; i < m; i++)
            scanf("%d",&girls[i]);
        if(m>=n){
            printf("Case %d: %d\n",++caso,0);
            continue;
        }
        sort(boys,boys+n);
        printf("Case %d: %d %d\n",++caso,n-m,boys[0]);
    }
}
