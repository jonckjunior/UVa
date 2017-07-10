#include <bits/stdc++.h>

using namespace std;

int c[10005];

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k) && n != -1 && k != -1){
        for(int i = n; i >= 0; i--) scanf("%d",&c[i]);
        for(int i = 0; i + k <= n; i++){
            c[i+k] -= c[i];
            c[i]=0;
        }
        int t = 0;
        while(c[t] == 0 && t <= n) t++;
        if(t > n) printf("0\n");
        else{
            for(int i = n; i >= t; i--){
                if(i==n) printf("%d",c[i]);
                else     printf(" %d",c[i]);
            }
            printf("\n");
        }
    }
}
