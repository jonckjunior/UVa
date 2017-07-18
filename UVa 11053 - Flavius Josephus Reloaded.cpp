#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int N,a,b;

int f(long long int x){
    return (a*((x*x)%N) + b) % N;
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
    while(cin >> N, N != 0){
        cin >> a >> b;
        ii res = floydCycleFinding(0);
        printf("%d\n",N-res.second);
    }
    
    
    return 0;
}
