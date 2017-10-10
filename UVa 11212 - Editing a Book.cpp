#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(vi src, map<vi,int>& dist){
    queue<vi> q; q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        vi frente = q.front(); q.pop();
        int d = dist[frente];
        if(d > 1) continue;
        for(int i = 0; i < 9; i++) //start cut
            for(int j = i; j < 9; j++){ // end cuts
                vi aux(frente);
                vi next(frente.begin()+i, frente.begin()+j+1);
                aux.erase(aux.begin()+i, aux.begin()+j+1);
                for(int k = 0; k < (int)aux.size(); k++){ // pos cut
                    vi proximo(aux);
                    proximo.insert(proximo.begin()+k, next.begin(), next.end());
                    if(!dist.count(proximo)){
                        dist[proximo] = d+1;
                        q.push(proximo);
                    }
                }
            }
    }
}

int query(vi src, const map<vi,int> &dist){
    queue<vi> q; q.push(src);
    map<vi,int> visitado;
    visitado[src] = 0;
    while(!q.empty()){
        vi frente = q.front(); q.pop();
        int d = visitado[frente];
        if(d > 1) continue;
        for(int i = 0; i < 9; i++) //start cut
            for(int j = i; j < 9; j++){ // end cuts
                vi aux(frente);
                vi next(frente.begin()+i, frente.begin()+j+1);
                aux.erase(aux.begin()+i, aux.begin()+j+1);
                for(int k = 0; k < (int)aux.size(); k++){ // pos cut
                    vi proximo(aux);
                    proximo.insert(proximo.begin()+k, next.begin(), next.end());
                    if(dist.count(proximo)){
                        return dist.at(proximo) + d + 1;
                    }
                    if(!visitado.count(proximo)){
                        visitado[proximo] = d+1;
                        q.push(proximo);
                    }
                }
            }
    }
    return -1;
}

int main() {
    int n,caso=0;
    vi finalera(9);
    for(int i = 0; i < 9; i++)
        finalera[i] = i+1;
    map<vi,int> dist;
    solve(finalera, dist);
    while(cin >> n, n != 0){
        vi v(9);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        for(int i = n; i < 9; i++)
            v[i] = i+1;
        if(dist.count(v)){
            printf("Case %d: %d\n", ++caso, dist[v]);
        }
        else{
            // printf("query\n");
            int res = query(v, dist);
            if(res == -1) printf("Case %d: %d\n", ++caso, 5);
            else printf("Case %d: %d\n", ++caso, res);
        }
    }

    return 0;
}
