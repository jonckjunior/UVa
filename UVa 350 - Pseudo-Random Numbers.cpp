#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int Z,I,M,L;

int f(int x){
    return (Z*x+I)%M;
}

ii floydCycleFinding(int seed){
    int tortoise = f(seed), hare = f(f(seed));
    while(tortoise != hare){tortoise = f(tortoise); hare = f(f(hare));}
    int mu = 0;
    hare = seed;
    while(tortoise != hare){tortoise = f(tortoise); hare = f(hare);mu++;}
    int lambda = 1;
    hare = f(tortoise);
    while(tortoise != hare){ hare = f(hare); lambda++;}
    return ii(mu,lambda);
    
}


int main(){
    int caso = 0;
    while(scanf("%d %d %d %d",&Z,&I,&M,&L), Z+I+M+L != 0){
        ii res = floydCycleFinding(L);
        printf("Case %d: %d\n",++caso,res.second);
    }
    
    
    return 0;
}
