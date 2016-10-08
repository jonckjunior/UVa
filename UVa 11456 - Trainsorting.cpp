#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
#include <string.h>
#define MAX 100000
using namespace std;

long long int A[MAX],L[MAX],D[MAX];

int main() {
    int n, t, caso = 0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n; i++) scanf("%lld",&A[i]),L[i] = D[i] = 1;
        
        long long int ans = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(A[i] > A[j] && L[i] < L[j] + 1)
                    L[i] = L[j] + 1;
                if(A[i] < A[j] && D[i] < D[j] + 1)
                    D[i] = D[j] + 1;
            }
            ans = max(ans,L[i]+D[i]-1);
        }
        
        if(n <= 1)
            cout << (n == 1) << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
