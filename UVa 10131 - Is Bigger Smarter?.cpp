#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
#include <string.h>
#include <vector>
#define MAX 10005
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

struct El{
    int w,iq,i;
    El(){}
    El(int a, int b, int c){w=a;iq=b;i=c;}
};

bool cmp(const El &a, const El &b){
    return a.iq > b.iq || (a.iq == b.iq && a.w > b.w);
}

El A[MAX];
int L[MAX], L_id[MAX], P[MAX];

int main() {
    int n=0, k;
    while(scanf("%d %d",&A[n].w, &A[n].iq) != EOF) A[n].i = n, n++;
    sort(A, A+n, cmp);
    //for(int i =0 ; i < n; i++)
       //printf("iq = %d peso = %d\n",A[i].iq, A[i].w );
    int lis = 0, lis_end = 0, old = -1;
    for(int i = 0; i < n; i++){
        int w = A[i].w;
        int pos = lower_bound(L,L+lis,w)-L;
        //if(A[i].iq == old) continue;
        //if(pos < lis && L[pos] == w) continue;
        //old = A[i].iq;
        L[pos] = w;
        L_id[pos] = i;
        P[i] = pos ? L_id[pos-1] : -1;
        if(pos+1>lis){
            lis = pos+1;
            lis_end = i;
        }
    }
    stack<int> s;
    int x = lis_end;
    for(; P[x] >= 0; x = P[x]) s.push(x);
    s.push(x);
    cout << lis << endl;
    while(!s.empty()) printf("%d\n",A[s.top()].i+1),s.pop();

}
