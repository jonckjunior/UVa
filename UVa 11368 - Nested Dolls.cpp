#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
#include <string.h>
#include <vector>
#define MAX 20005
using namespace std;
typedef pair<int,int> ii;
vector<ii> A;
int L[MAX];
bool cmp(ii a, ii b){
    return a.first > b.first || (a.first == b.first&&a.second<b.second);
}

int main() {
    int t,n,x,y;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            scanf("%d %d",&x,&y);
            A.push_back(ii(x,y));
        }
        sort(A.begin(), A.end(),cmp);
        int lis = 0;
        for(int i = 0; i < n; i++){
            int h = A[i].second;
            int pos = upper_bound(L,L+lis,h) - L;
            if(pos == lis) L[pos] = h,lis++;
            else L[pos] = h;
        }
        cout << lis << endl;
        A.clear();
     }
}
