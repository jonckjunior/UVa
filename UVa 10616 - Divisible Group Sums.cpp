#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long long int n,q,d,m,ways,K[205],V[205],DP[205][25][15];

long long int solve(int u, int w, int num){
    long long int &value = DP[u][w][num];
    if(value != -1) return value;
    if(u==n || num == m){
        if(num == m && w == 0) return value = 1;
        return 0;
    }
    return value = solve(u+1,w,num) + solve(u+1,(w+V[u])%d,num+1);
}


int main(){
    ios::sync_with_stdio(false);    
    int caso = 0;
    while(cin >> n >> q && n+q != 0){
        //printf("SET %d:\n",++caso);
        cout << "SET " << ++caso << ":" << endl;
        for(int i = 0; i < n; i++) cin >> K[i];
        for(int i = 0; i < q; i++){
            cin >> d >> m;
            ways = 0;
            for(int j = 0; j < n; j++)
                V[j] = K[j] > 0 ? K[j]%d : ((K[j]%d)+d)%d;
            memset(DP,-1,sizeof DP);
            cout << "QUERY " << i+1 << ": " << solve(0,0,0) << endl;
        }
    }
}
