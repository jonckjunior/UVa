#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,double> id;
int v,e, n, lojas[55];
double g[55][55], preco[55], grafo[20][20], DP[20][100000];

double solve(int u, int mark){
    //printf("%d %d\n",u,mark );
    if(bit(n+1)-1 == mark) return -grafo[u][0];
    double &value = DP[u][mark];
    if(value != -1) return value;
    value = -grafo[u][0];
    for(int i = 0; i <= n; i++)
        if (!(bit(i)&mark))
            value = max(value, solve(i, mark|bit(i))+ preco[i] - grafo[u][i]); 
    return value = max(value, -grafo[u][0]);
}

int main(){
    int t,x,y;
    double w;
    cin >> t;
    while(t--){
        cin >> v >> e;
        v++;
        for(int i = 0; i <= v; i++) for(int j = 0; j <= v; j++){
            if(i==j) g[i][j] = 0;
            else g[i][j] = INF;
        }
        for(int i = 0; i < e; i++){
            cin >> x >> y >> w;
            g[x][y] = g[y][x] = min(g[x][y],w);
        }
        for (int k = 0; k < v; k++)
            for (int i = 0; i < v; i++)
                for (int j = 0; j < v; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> x >> w;
            lojas[i] = x;
            preco[i] = w;
        }
        lojas[0] = preco[0] = 0;
        for(int i = 0; i <= n; i++){
            int u = lojas[i];
            for(int j = 0; j <= n; j++){
                int v = lojas[j];
                grafo[i][j] = g[u][v];
            }
        }
        /*for(int i = 0; i <= n; i++)
            for(int j = 0; j<= n; j++)
                printf("grafo[%d][%d] = %.2lf\n",i,j,grafo[i][j]);*/
        for(int i = 0; i <= n; i++) for(int j = 0; j <= 100000; j++) DP[i][j] = -1;
        double ans = solve(0,1);
        //cout << ans << endl;
        if(abs(ans) <= 1e-7) printf("Don't leave the house\n");
        else if(ans < 0)     printf("Don't leave the house\n");
        else                 printf("Daniel can save $%.2lf\n",ans);
    }
}
 
