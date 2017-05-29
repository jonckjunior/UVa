#include <bits/stdc++.h>
using namespace std;
#define MAX_V 2000
#define INF 1000
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector< pair<int, ii> > viii;
int res[MAX_V][MAX_V], f,mf, s,t, n, m,tb_siz;
vector<vi> adj;
char tb[MAX_V][MAX_V];
vi p;


void augment(int v, int minEdge){
    //printf("Path %d\n",v);
    if(v==s){
        f = minEdge;
        //cout << endl;
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
            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i];
                if(res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if(f==0) break;
        mf += f;
    }
}

int valid(int a, int b){
    if(a >= 0 && a < n && b >= 0 && b < m && tb[a][b] != '~') return true;
    else                                                      return false;
}

int GetNode(int a,int b){
    //if(a*m+b == s || a*m+b == t) printf("[+] DEBUG-------------------------------------------\n");
    return a*m+b;
}

void connectEdge(int a, int b){
    adj[a].push_back(b);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    int ps;
    char c;
    while(cin >> n >> m >> ps){
        getchar();
        memset(res, 0, sizeof res);
        adj.assign(MAX_V, vi());

        tb_siz = n*m;
        s = tb_siz*2;
        t = s+1;
        adj.assign(t+5, vi());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%c",&c);
                tb[i][j] = c;
                if(c == '~') continue;

                int node = GetNode(i,j);

                if(c == '*'){
                    connectEdge(s, node+tb_siz);
                    connectEdge(node+tb_siz, node);
                    connectEdge(node,node+tb_siz);
                    connectEdge(node, s);
                    res[s][node+tb_siz]= 1;
                    res[node+tb_siz][node] = 1;
                }
                if(c == '.'){
                    connectEdge(node+tb_siz, node);
                    connectEdge(node,node+tb_siz);
                    res[node+tb_siz][node] = 1;
                }
                if(c == '@'){
                    connectEdge(node+tb_siz, node);
                    connectEdge(node,node+tb_siz);
                    res[node+tb_siz][node] = INF;
                }
                if(c == '#'){
                    connectEdge(node, t);
                    connectEdge(node+tb_siz,node);

                    connectEdge(t, node+tb_siz);
                    connectEdge(node,node+tb_siz);
                    res[node][t] = ps;
                    res[node+tb_siz][node] = INF;
                }
            }
            getchar();
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(valid(i,j))
                    for(int k = 0; k < 4; k++){
                        int ax = i + dx[k], ay = j + dy[k];
                        if(valid(ax,ay)){
                            int node_a = GetNode(i,j), node_b = GetNode(ax, ay);                            
                            connectEdge(node_a,node_b+tb_siz);
                            connectEdge(node_b+tb_siz,node_a);
                            res[node_a][node_b+tb_siz] = INF;
                        }
                    }

        maxflow();

        cout << mf << endl;

    }
}
