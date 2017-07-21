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
    p.push_back(2);
    int root = sqrt(maxn);
    for(int i = 3; i <= root; i += 2) if(bt[i]){
        p.push_back(i);
        for(int j = i * i; j <= root; j += i)
            bt[j] = 0;
    }
}

int numDivisors(int n){
    int root = (int)sqrt(n);
    long long int c = 1;
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i];
        long long int power = 0;
        while(n%v==0) n/=v, power++;
        c *= (power+1);
    }
    if(n!=1) c *= 2;
    return c;
}

int main() {
    int t,u,l;
    scanf("%d",&t);
    sieve();
    while(t--){
        scanf("%d %d",&u,&l);
        int res = 0, resnum = 0;
        for(int i = u; i <= l; i++){
            int aux = numDivisors(i);
            if(aux > res) res = aux, resnum = i;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",u,l,resnum,res);
    }
    return 0;
}
