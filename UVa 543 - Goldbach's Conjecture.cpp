#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int const maxn = 1000001;
bitset<maxn> bt;
vi primes;

void sieve(){
    bt.set();
    bt[0] = bt[1] = bt[2] = 0;
    for(int i = 4; i <= maxn; i+=2) bt[i] = 0;
    for(int i = 3; i <= maxn; i+=2) if(bt[i]){
        primes.push_back(i);
        for(int j = i + i; j <= maxn; j+=i) bt[j] = 0;
    }
}
int main() {
    int n;
    sieve();
    while(scanf("%d",&n) && n!=0){
        vi::iterator low = lower_bound(primes.begin(), primes.end(), n);
        int pos = (low - primes.begin());
        int found = 0;
        for(int i = 0; i <= pos && pos < primes.size() && primes[i] <= n; i++){
            int x = n-primes[i];
            if(bt[x]){
                printf("%d = %d + %d\n",n,primes[i],n-primes[i]);
                found = 1;
                break;
            }
        }
    }
}
