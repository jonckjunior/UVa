#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;
typedef vector<int> vi;
int const maxn = 1000000;
bitset<maxn> bt;
vi primes;

void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    bt[2] = 1;
    primes.push_back(2);
    for(int i = 4; i <= maxn; i+=2) bt[i] = 0;
    for(int i = 3; i <= maxn; i+=2) if(bt[i]){
        primes.push_back(i);
        for(int j = i + i; j <= maxn; j+=i) bt[j] = 0;
    }
}

bool isPrime(int n){
    if(n <= 1000000) return bt[n]==1;
    int r = (int)sqrt(n);
    for(int i = 0; i < primes.size() && primes[i] <= r; i++)
        if(n%primes[i] == 0) return false;
    return true;
}

int main() {
    int n,m;
    sieve();
    while(scanf("%d %d",&n,&m) != EOF){
        long long int first = -1, second = -1, sfirst=-1, ssecond=-1, last=-1;
        for(long long int i = n; i <= m; i++){
            if(isPrime(i)){
                if(first == -1) first = i;
                else if(second == -1) second = i;
                else if(i-last < second-first)
                    first = last, second = i;
                if(sfirst == -1) sfirst = i;
                else if(ssecond == -1) ssecond = i;
                else if(i-last > ssecond-sfirst)
                        sfirst = last, ssecond = i;
                last = i;
            }
        }
        if(first!=-1 && second != -1)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",first,second,sfirst,ssecond);
        else
            printf("There are no adjacent primes.\n");
    }
}
