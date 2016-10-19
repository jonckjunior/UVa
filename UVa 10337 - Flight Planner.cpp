#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int distancia, wind[1005][1005], DP[1005][1005];

int solve(int pos, int dist){
    if(pos < 0 || pos > 9) return INF;
    if(dist == distancia){
        if(pos != 0) return INF;
        return 0;
    }
    int &value = DP[pos][dist];
    if(value != -1) return value - wind[pos][dist];
    value = min(solve(pos+1,dist+1) + 60, solve(pos, dist+1) + 30);
    value = min(value, solve(pos-1,dist+1) + 20);
    return value - wind[pos][dist];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> distancia;
        distancia /= 100;
        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < distancia; j++)
                cin >> wind[i][j];
        memset(DP, -1, sizeof DP);
        cout << solve(0,0) << endl;
        cout << endl;
    }  
}
 
