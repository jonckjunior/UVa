#include <bits/stdc++.h>
using namespace std;
#define MAX_V 500
#define INTERVALO 50005
#define INF 10000001
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector< pair<int, ii> > viii;
int res[MAX_V][MAX_V], f,mf, N,E, totalcost, s,t, n, m, usado[50005];
vi p, cost;
vii intervalo_nodos, macaquitos;
viii macacos;
vector< vi > adj;
vector< vii > int_final;

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

bool func(const ii &a,const ii &b){
    return macacos[a.second-1].second > macacos[b.second-1].second;
}

int main(){
    int numero_de_vezes_que_os_macaquinhos_tomaram_agua = 0, caso=0;
    while(cin >> n, n){
        cin >> m;

        priority_queue< ii, vii, greater<ii> > pq;
        numero_de_vezes_que_os_macaquinhos_tomaram_agua = 0;
        memset(res, 0, sizeof res);
        intervalo_nodos.clear();
        macacos.clear();
        adj.assign(n+5, vi());
        macaquitos.clear();
        int_final.assign(n+5, vii());
        s = 0;
        t = n+1;
        macaquitos.push_back(ii(0,0));
        for(int i = 0; i < n; i++){
            int a,b,v;
            cin >> v >> a >> b;
            macacos.push_back(make_pair(a,ii(b,v)));
            res[0][i+1] = res[i+1][0] = v;
            numero_de_vezes_que_os_macaquinhos_tomaram_agua += v;
            pq.push(ii(a,b));
            macaquitos.push_back(ii(v, i+1));
        }
        
        while(!pq.empty()){
            ii pri = pq.top(); pq.pop();
            if(pq.empty()){
                intervalo_nodos.push_back(pri);                
                break;
            }
            ii sec = pq.top(); pq.pop();
            if(pri.second > sec.first){
                if(pri.first == sec.first){
                    pq.push(ii(pri.first, pri.second));
                    pq.push(ii(pri.second, sec.second));
                }
                else if(pri.second == sec.second){
                    pq.push(ii(pri.first, sec.first));
                    pq.push(ii(sec.first, sec.second));
                }
                else if(pri.second > sec.second){
                    pq.push(ii(pri.first, sec.first));
                    pq.push(ii(sec.first, sec.second) );
                    pq.push(ii(sec.second, pri.second));
                }
                else{
                    pq.push(ii(pri.first, sec.first));
                    pq.push(ii(sec.first, pri.second) );
                    pq.push(ii(pri.second, sec.second) );
                }
            }
            else{
                intervalo_nodos.push_back(pri);
                pq.push(sec);
            }

        }

        for(int i = 0; i < intervalo_nodos.size(); i++){
            int ia = intervalo_nodos[i].first, ib = intervalo_nodos[i].second;
            res[i+t+5][t] = res[t][i+t+5] = (ib-ia)*m;
        }

        for(int i = 0; i < macacos.size(); i++){
            int a = macacos[i].first, b = macacos[i].second.first, v = macacos[i].second.second;
            for(int j = 0; j < intervalo_nodos.size(); j++){
                int ia = intervalo_nodos[j].first, ib = intervalo_nodos[j].second;
                if(ia >= a && ib <= b){
                    adj[i+1].push_back(j+t+5);
                    res[i+1][j+t+5] = min(ib-ia, v);
                }
            }
        }
        maxflow();
        if(mf == numero_de_vezes_que_os_macaquinhos_tomaram_agua){
            printf("Case %d: Yes\n", ++caso);
            memset(usado,0, sizeof usado);
            for(int i = 0; i < intervalo_nodos.size(); i++){
                viii respostas;
                vii res_mac;
                for(int j = 1; j <= n; j++){
                    if(res[i+t+5][j] > 0) res_mac.push_back(ii(res[i+t+5][j],j));
                }
                sort(res_mac.rbegin(), res_mac.rend());
                int a = intervalo_nodos[i].first, b = intervalo_nodos[i].second, auxa;
                auxa = a;
                for(int j = 0; j < res_mac.size(); j++){
                    int v = res_mac[j].first;
                    int macaco_atual = res_mac[j].second;
                    while(v > 0){
                        int init_a = a;
                        while(usado[a] < m && v > 0 && a < b)
                            usado[a]++, a++, v--;
                        int end_a = a;
                        if(end_a != init_a)
                            int_final[macaco_atual].push_back(ii(init_a, end_a));
                        else a++;
                        if(a >= b) a = a%b+auxa;
                    }
                }
            }
            
            for(int i = 0; i < int_final.size(); i++){
                stack<ii> stk;
                sort(int_final[i].begin(), int_final[i].end());
                for(int j = int_final[i].size()-1; j >=0 ; j--)
                    stk.push(int_final[i][j]);
                vii obrigado_felipe;
                while(!stk.empty()){
                    ii pri = stk.top(); stk.pop();
                    if(stk.empty()){
                        obrigado_felipe.push_back(pri);
                        break;
                    }
                    ii sec = stk.top(); stk.pop();
                    if(pri.second == sec.first)
                        stk.push(ii(pri.first, sec.second));
                    else{
                        obrigado_felipe.push_back(pri);
                        stk.push(sec);
                    }
                }
                if (obrigado_felipe.size())cout << obrigado_felipe.size();
                for(int j = 0; j < obrigado_felipe.size(); j++){
                    printf(" (%d,%d)", obrigado_felipe[j].first, obrigado_felipe[j].second);
                    if(j == obrigado_felipe.size() - 1) cout << endl;
                }
            }
            
        }
        else
            printf("Case %d: No\n", ++caso);

    }
}
