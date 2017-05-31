#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const inf = 1e9;

int n,m, maxi, i_maxi;
vector<vi> adj, tree;
vii edge;

void bfs(ii e){
    int x = e.first, y = e.second;
    queue<int> q; q.push(x); q.push(y);
    vi dist(n+1, inf);
    tree.assign(n+1, vi());
    dist[x] = dist[y] = 0;
    maxi = i_maxi = -1;
    //printf("%d-%d\n",x,y);
    tree[x].push_back(y);
    tree[y].push_back(x);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[v] == inf){
                dist[v] = dist[u] + 1;
                q.push(v);
                //printf("%d-%d\n",u,v);
                tree[u].push_back(v);
                tree[v].push_back(u);
                if(dist[v] > maxi) maxi = dist[v], i_maxi = v;
            }
        }
    }
    //cout << endl;
}

void bfs2(int s){
    queue<int> q; q.push(s);
    vi dist(n+1, inf);
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < tree[u].size(); i++){
            int v = tree[u][i];
            if(dist[v] == inf){
                dist[v] = dist[u] + 1;
                q.push(v);
                if(dist[v] > maxi) maxi = dist[v], i_maxi = v;
            }
        }
    }
}


int main(){
    int caso = 0, t, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        adj.assign(n+1, vi());
        edge.clear();

        for(int i = 0; i < m; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            edge.push_back(ii(x,y));
        }

        int res = inf;

        for(int i = 0; i < m; i++){
            bfs(edge[i]);
            //printf("Mais distance de %d-%d é %d com %d\n",edge[i].first, edge[i].second, i_maxi, maxi);
            bfs2(i_maxi);
            res = min(res, maxi);
            //printf("Maxi = %d\n\n",maxi);
        }

        printf("Case #%d:\n",++caso);
        cout << res << endl << endl;
    }
}
