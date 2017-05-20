#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define MAX_V 105
#define INF 1000001
typedef vector<int> vi;
int res[MAX_V][MAX_V], s,t, f,mf, n;
vi p;

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
            for(int v = 1; v <= n; v++){
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
    int caso = 0, x,y,w,c;
    while(cin >> n, n){
        cin >> s >> t >> c;
        memset(res, 0, sizeof res);
        for(int i = 0; i < c; i ++){
            cin >> x >> y >> w;
            res[x][y] += w;
            res[y][x] += w;
        }

        maxflow();

        printf("Network %d\n",++caso);
        printf("The bandwidth is %d.\n\n",mf);
        
    }
}
