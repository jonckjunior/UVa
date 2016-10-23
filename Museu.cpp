#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 1005
#define bit(i) (1<<i)
#define UNVISITED -1
#define VISITED 1
#define VISITING 2
#define MIN(a,b) (a < b ? a : b)
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int node[MAX_N], v, e, x , y, w;
vector<vii> g;

int dji(int s){
    vi dist(v,INF);
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0,s));
    dist[s] = 0;
    bool first = true;
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if(u == s && !first) return dist[u];
        if(d > dist[u]) continue;
        for(int i = 0; i < g[u].size(); i++){
            ii v = g[u][i];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
        if(first){
            dist[s] = INF;
            first = false;
        }
    }
    return dist[s];
}

int main(){
    ios::sync_with_stdio(false);
    cin >> v >> e;
    g.assign(v,vii());
    for(int i = 0; i < v; i++)
        cin >> node[i];
    for(int i = 0; i < e; i++){
        cin >> x >> y >> w;
        x--;y--;
        g[x].push_back(ii(y,w+node[y]));
    }

    int res = 1e9;
    for(int i = 0; i < v; i++)
        res = min(res, dji(i));

    printf("%d\n",res);
}
