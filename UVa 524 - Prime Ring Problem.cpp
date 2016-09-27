#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <bitset>
#include <algorithm>
using namespace std;
#define bit(i) (1<<i)
#define INF 1e8
#define MIN(a,b) (a) < (b) ? (a) : (b)

int n;

int primes[] = {2,3,5,7,11,13, 17,19,23,29,31,37};

vector<int> v;

bool isPrime(int a){
    for(int i = 0; i < 12; i++)
        if(a == primes[i]) return true;
    return false;
}
int contador=0, mark = 0;
void backtrack(){
    //printf("Tentando %d com size = %d\n",++contador,(int)v.size());
    if(v.size() == n){
        bool ok = true;
        if(!isPrime(v[n-1]+v[0]))return;
        if(!ok) return;
        for(int i =0 ; i < n; i++){
            if(i == n-1)
                printf("%d\n",v[i]);
            else
                printf("%d ",v[i]);
        }
        return;
    }

    for(int i = 1; i < n; i++){
        if(!(bit(i)&mark) && isPrime(i+1+v[v.size()-1])){
            v.push_back(i+1);
            mark |= bit(i);
            backtrack();
            mark ^= bit(i);
            v.pop_back();
        }
    }
}

int main(){
    bool espaco = false;
    int caso = 0;
    while(cin >> n){
        if(espaco) printf("\n");
        printf("Case %d:\n",++caso);
        v.clear();
        contador = mark = 0;
        v.push_back(1);
        backtrack();
        espaco = true;
    }  
}

