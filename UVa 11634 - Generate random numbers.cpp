#include <bits/stdc++.h>

using namespace std;

int N, v[10000];

int f(int x){
    return ((x*x / 100) %10000);
}

int main(){
    int caso = 0;
    while(cin >> N, N != 0){
        memset(v,0,sizeof v);
        int c = 0;
        
        while(v[N] == 0){
            v[N] = 1;
            N = f(N);
            c++;
        }
        printf("%d\n",c);
    }  
    return 0;
}
