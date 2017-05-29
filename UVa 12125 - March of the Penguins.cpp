#include <bits/stdc++.h>
using namespace std;
#define MAX_V 205
#define INF 1000000
#define TOL 1e-7
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,double> pdd;
typedef vector<ii> vii;
typedef vector< pair<int, ii> > viii;
int res[MAX_V][MAX_V], f,mf, s,t, n, m,num_penguim[MAX_V], jump[MAX_V], orig[MAX_V][MAX_V], offset;
vector<vi> adj;
vi p;
vector<pdd> ponto;
double d;


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

double dist(pdd a, pdd b){
    double x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
    return sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
}

void connectEdge(int a, int b){
    adj[a].push_back(b);
}

int main(){
    int x,y,n_pen,jmp, casos, total_penguim;
    cin >> casos;
    while(casos--){
        total_penguim = 0;
        cin >> n >> d;
        offset = n;
        s = offset*2;
        memset(res, 0, sizeof res);
        ponto.clear();
        adj.assign(MAX_V, vi());
        for(int i = 0; i < n; i++){
            cin >> x >> y >> n_pen >> jmp;
            ponto.push_back(pdd(x,y));
            total_penguim += n_pen;
            
            if(n_pen){
                //printf("s%d-%d\n",s,i);
                connectEdge(s, i+offset);
                connectEdge(i, s);
                res[s][i+offset] = n_pen;
            }
            connectEdge(i+offset, i);
            connectEdge(i, i+offset);
            res[i+offset][i] = jmp;
        }
        //printf("total p = %d\n",total_penguim);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i==j) continue;
                //printf("(%.0lf,%.0lf) para (%.0lf,%.0lf) = %.2lf\n",ponto[i].first,ponto[i].second, ponto[j].first, ponto[j].second,dist(ponto[i], ponto[j]));
                if( dist(ponto[i], ponto[j]) - d <= TOL ){
                    res[i][j+offset] = INF;
                    res[j][i+offset] = INF;
                    connectEdge(i, j+offset);
                    connectEdge(j+offset, i);
                    connectEdge(j, i+offset);
                    connectEdge(i+offset, j);
                }
            }
        }
        vi res_p;
        
        /*
        for(int i = 0; i < MAX_V; i++)
            for(int j =0 ; j < MAX_V; j++)
                if(res[i][j])
                    printf("res[%d][%d] = %d\n",i,j,res[i][j]);
        */
        

        for(int a = 0; a < MAX_V; a++) for(int b = 0; b < MAX_V; b++) orig[a][b] = res[a][b];
        for(int i = 0; i < n; i++){
            t = i + offset;
            maxflow();
            //printf("MF = %d\n",mf);
            for(int a = 0; a < MAX_V; a++) for(int b = 0; b < MAX_V; b++) res[a][b] = orig[a][b];
            if(mf == total_penguim) res_p.push_back(i);
        }
        if(res_p.size()){
            for(int i = 0; i < res_p.size(); i++){
                printf("%d",res_p[i]);
                if(i != res_p.size() - 1) printf(" ");
            }
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
}
