#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int l,n,cut[55],DP[55][55];

int solve(int left, int right){
    if(left + 1 == right) return 0;
    int &value = DP[left][right];
    if(value != -1) return value;
    value = INF;
    for(int i = left + 1; i < right; i++)
        value = min(value, solve(left, i) + solve(i, right) + cut[right] - cut[left] );
    return value;
}

int main(){
    
    while(cin >> l && l != 0){
        memset(DP,-1,sizeof DP);
        cin >> n;
        cut[0] = 0;
        cut[n+1] = l;
        for(int i = 1; i <= n; i++) cin >> cut[i];
        printf("The minimum cutting is %d.\n",solve(0,n+1));
    }

}
 
