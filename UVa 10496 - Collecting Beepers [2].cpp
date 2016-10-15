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

int n,m,k,bestsum;
vii p;
int g[MAX_N][MAX_N], DP[15][2100];

int solve(int u, int mark){
    if(bit(k)-1 == mark) return g[u][0];
    int &value = DP[u][mark];
    if(value != -1) return value;
    value = INF;
    for(int i = 0; i < k; i++)
        if(!(bit(i)&mark))
            value = min (value, solve(i,mark|bit(i)) + g[u][i]);
    return value;
}

int main(){
    int t,x,y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> x >> y;
        p.push_back(ii(x,y));
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            p.push_back(ii(x,y));
        }
        k++;
        for(int i = 0; i <= k; i++)
            for(int j = 0; j<= k; j++)
                g[i][j] = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
        memset(DP, -1, sizeof DP);
        int ans = solve(0,1);
        cout << "The shortest path has length " << ans << endl;
        p.clear();
    }
}
