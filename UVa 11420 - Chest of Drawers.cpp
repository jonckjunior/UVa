#include <bits/stdc++.h>
#define INF 1e9
#define MAX_N 30
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,double> id;
typedef vector<id> vid;
long long int n,m, DP[70][70][5];

long long int solve(int drawer, int secure, int prev){
    //printf("%d %d %d\n",drawer, secure, prev );
    if(drawer == 0) return secure == m;
    long long int &value = DP[drawer][secure][prev];
    if(value != -1) return value;
    return value = solve(drawer - 1, secure, 0) + solve(drawer - 1, secure + prev, 1);
}

int main(){
    while(cin >> n >> m, n >= 0 && m >= 0){
        memset(DP, -1, sizeof DP);
        cout << solve(n,0,1) << endl;
    }
}
 
