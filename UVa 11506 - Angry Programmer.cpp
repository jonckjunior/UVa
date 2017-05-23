#include <bits/stdc++.h>
using namespace std;
#define MAX_V 105
#define INF 10000001
typedef vector<int> vi;
int res[MAX_V][MAX_V], f,mf, N,E, totalcost, s,t;
vi p, cost;

void augment(int v, int minEdge){
    if(v==s){
        f = minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void maxflow(){
    mf = 0;
    while(1){
        f = 0;
        vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
        p.assign(MAX_V, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 0; v < MAX_V; v++){
                if(res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if(f==0) break;
        mf += f;
    }
}

int main(){
    int x, y, w;
    while(cin >> N >> E, N+E != 0){
        memset(res, 0, sizeof res);
        s = 0;
        t = N-1;
        for(int i = 2; i < N; i++){
            cin >> x >> w;
            x--;
            res[x+50][x] = res[x][x+50] = w;
        }
        res[s+50][s] = res[t+50][t] = INF;
        for(int i = 0; i < E; i++){
            cin >> x >> y >> w;
            x--;y--;
            res[x][y+50] = res[y][x+50] = w;
            
        }
        maxflow();

        cout << mf << endl;
    }
}
