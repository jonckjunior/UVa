#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
#include <string.h>
#define MAX 100000
using namespace std;

long long int A[MAX], P[MAX],L[MAX], L_id[MAX], V[MAX], D[MAX];

int main() {
    int n, t, caso = 0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i =0 ; i < n; i++) scanf("%lld",&A[i]);
        for(int i =0 ; i < n; i++) scanf("%lld",&V[i]),L[i]=D[i]=V[i];
        long long int inc, dec;
        inc = dec = V[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(A[i] > A[j] && L[i] < L[j] + V[i])
                    L[i] = L[j] + V[i];
                if(A[i] < A[j] && D[i] < D[j] + V[i])
                    D[i] = D[j] + V[i];
                inc = max(inc, L[i]);
                dec = max(dec, D[i]);
            }
        }
        if(inc >= dec)
            printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",++caso,inc,dec);
        else
            printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",++caso,dec,inc);

    }
    return 0;
}
