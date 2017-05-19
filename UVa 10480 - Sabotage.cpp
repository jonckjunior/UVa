#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define MAX_V 60
#define INF 40000001

int res[MAX_V][MAX_V], mf, f, s,t, g[MAX_V][MAX_V],n,m;
vi p, preco(MAX_V), vis(MAX_V), setS(MAX_V), setT(MAX_V);

void dfs(int v){
    vis[v] = setS[v] = 1;
    //printf("[+] DEBUG [+] -> %d belongs to setS\n",v);
    for(int i = 0; i < n; i++){
        if(res[v][i] && !vis[i])
            dfs(i);
    }
}

void dfs2(int v){
    vis[v] = 1;
    for(int i = 0; i < n; i++){
        if(g[v][i] && !vis[i] && setT[i])
            printf("%d %d\n",v+1,i+1);
        else if(g[v][i] && !vis[i])
            dfs2(i);
    }
}

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

int maxflow(){
    mf = 0;
        while(1){
            f = 0;
            vi dist(MAX_V, INF);dist[s] = 0;queue<int> q;q.push(s);
            p.assign(MAX_V, -1);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u == t) break;
                for(int v = 0; v < n; v++){
                    if(res[u][v] > 0 && dist[v] == INF)
                        dist[v] = dist[u]+1, q.push(v), p[v] = u;
                }
            }
            augment(t, INF);
            if(f==0) break;
            mf+=f;
        }
    return mf;
}

int main(){
	int x,y,w;
    while(cin >> n >> m && n,m){
        memset(res, 0, sizeof res);
        memset(  g, 0, sizeof   g);
        for(int i = 0; i < m; i++){
            cin >> x >> y >> w;
            x--;y--;
            res[y][x] = res[x][y] = g[x][y] = g[y][x] = w;
        }
        s = 0;
        t = 1;
        maxflow();

        vis.assign(MAX_V, 0);
        setS.assign(MAX_V, 0);
        setT.assign(MAX_V, 0);
        dfs(0);
        for(int i = 0; i < n; i++)
            setT[i] = !setS[i];
        vis.assign(MAX_V, 0);
        dfs2(0);
        //printf("[+] DEBUG [+] = %d\n", mf);
        cout << endl;
    }
}
