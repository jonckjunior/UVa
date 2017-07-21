#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxn = 1000000000;
vi p;
bitset<32000> bt;
void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    int root = (int)sqrt(maxn);
    p.push_back(2);
    for(int i = 3; i <= root; i+=2) if(bt[i]){
        p.push_back(i);
        for(int j = i*i; j <= root; j+=i)
            bt[j] = 0;
    }
}

long long int EulerPhi(long long int n){
    //if(n <= 32000) return bt[n];
    long long int root = (int)sqrt(n), ans = n;
    for(long long int i = 0; i < p.size() && p[i] <= root; i++){
        if(n%p[i]==0) ans -= ans/p[i];
        while(n%p[i]==0) n/=p[i];
    }
    if(n!=1) ans -= ans/n;
    return ans;
}

int main() {
    int n;
    sieve();
    while(scanf("%d",&n), n!=0)
        printf("%lld\n",EulerPhi(n));
    return 0;
}
