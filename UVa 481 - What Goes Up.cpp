#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
#define MAX 100000
using namespace std;

long long int A[MAX], P[MAX],L[MAX], L_id[MAX];

int main() {
    int x, n = 0;
    while(scanf("%d",&x) != EOF)
        A[n++] = x;

    int lis = 0, lis_end = 0;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(L, L+lis, A[i]) - L;
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos-1] : -1;
        if(pos+1>=lis){
            lis = pos+1;
            lis_end = i;
        }
    }
    stack<int> s;
    x = lis_end;
    printf("%d\n-\n",lis);
    for(; P[x] >= 0; x = P[x]) s.push(A[x]);
    s.push(A[x]);
    while(!s.empty())
        printf("%d\n",s.top()),s.pop();

    return 0;
}
