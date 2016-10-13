#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long long int DP[10][30005], n, numcoins = 5;
int coin[] = {1,5,10,25,50};

long long int solve(int type, int change){
    //printf("%d %d\n",type,change );
    if(change == 0) return 1;
    if(change < 0 || type == numcoins) return 0;
    long long int &value = DP[type][change];
    if(value != -1) return value;
    return value = solve(type+1, change) + solve(type, change - coin[type]);
}


int main(){
    memset(DP,-1,sizeof DP);
    while(cin >> n){
        long long int ans = solve(0,n);
        if(ans == 1) printf("There is only 1 way to produce %lld cents change.\n",n);
        else printf("There are %lld ways to produce %lld cents change.\n",ans,n);
    }
}
