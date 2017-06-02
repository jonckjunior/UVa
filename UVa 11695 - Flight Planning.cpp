#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const inf = 1e9;

int n, i_maxi, maxi;
vector<ii> edges;
vector<vii> adj;
vi dist, p;

void bfs(int s){
    dist.assign(n+1, inf);
    p.assign(n+1, -1);
    queue<int> q; q.push(s);dist[s] = 0;
    maxi = i_maxi = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            ii frente = adj[u][i];
            int v = adj[u][i].first, valid = adj[u][i].second;
            if(valid && dist[v] == inf){
                dist[v] = dist[u]+1;
                q.push(v);
                p[v] = u;
                if(dist[v] > maxi) maxi = dist[v], i_maxi = v;
            }
        }
    }
}

ii getDiametro(int s){
    bfs(s);
    if(i_maxi == -1) return ii(0,s);
    bfs(i_maxi);
    vi path;
    for(int u = i_maxi; u != -1; u = p[u])
        path.push_back(u);
    return ii(maxi, path[maxi/2]);
}

void turnOff(int u, int v){
    for(int j = 0; j < adj[u].size(); j++)
        if(adj[u][j].first == v){adj[u][j].second = 0; break;}
    for(int j = 0; j < adj[v].size(); j++)
        if(adj[v][j].first == u){adj[v][j].second = 0; break;}
}

void turnOn(int u, int v){
    for(int j = 0; j < adj[u].size(); j++)
        if(adj[u][j].first == v){adj[u][j].second = 1; break;}
    for(int j = 0; j < adj[v].size(); j++)
        if(adj[v][j].first == u){adj[v][j].second = 1; break;}
}

int newDiametro(int a, int b, int c, int d){
    int res = max(a+b, c+d);
    res = max(res, b+d+1);
    return res;
}

int main(){
    int t,x,y;
    cin >> t;
    while(t--){
        cin >> n;
        edges.clear();
        adj.assign(n+1, vii());
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            x--;y--;
            edges.push_back(ii(x,y));
            adj[x].push_back(ii(y,1));
            adj[y].push_back(ii(x,1));
        }
        ii nova, deletada;
        int res = inf;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i].first, v = edges[i].second;
            turnOff(u,v);
            ii esq = getDiametro(u);
            ii dir = getDiametro(v);
            int l1= esq.first/2, l2 = (esq.first+1)/2, r1 = dir.first/2, r2 = (dir.first+1)/2;
            int novoDiametro = newDiametro(l1,l2,r1,r2);

            if(novoDiametro < res){
                res = novoDiametro;
                deletada = edges[i];
                nova = ii(esq.second, dir.second);
            }
            turnOn(u,v);
        }
        printf("%d\n",res);
        printf("%d %d\n",deletada.first+1, deletada.second+1);
        printf("%d %d\n",nova.first+1, nova.second+1);
    }
}
