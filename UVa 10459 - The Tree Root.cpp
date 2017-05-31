#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int const max_v = 5005, inf = 1000000;

int n, dist[max_v], res[max_v], maxi, i_maxi , p[max_v], source;
vector<vi> adj;
set<int> best, worst;
void bfs(int s){
    queue<int> q; q.push(s);
    memset(p, -1, sizeof p);
    for(int i = 0; i < n; i++) dist[i] = inf;
    dist[s] = 0;
    i_maxi = maxi = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();        
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[v] == inf){
                dist[v] = dist[u] + 1,p[v] = u,q.push(v);
                if(dist[v] > maxi) maxi = dist[v], i_maxi = v;
            }
        }
    }
}

void findPath(int u){
    if( (!(maxi&1) && dist[u] == maxi/2) || ( (maxi&1) && dist[u] == maxi/2 ) || ( (maxi&1) && dist[u] == maxi/2+1) ) best.insert(u);
    if(u == source) return;    
    else if(p[u] != -1) findPath(p[u]);
}

int main(){
    while(cin >> n){
        adj.assign(n+1, vi());
        best.clear();
        worst.clear();
        int v,k;
        for(int i = 0; i < n; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> v;
                v--;
                adj[i].push_back(v);
            }
        }        
        bfs(0);

        source = i_maxi;
        bfs(source);

        printf("Best Roots  :");
        findPath(i_maxi);
    
        for(set<int>::iterator it = best.begin(); it != best.end(); it++){
            printf(" %d",*it+1);
            bfs(*it);
            for(int j = 0; j < n; j++)
                if(dist[j] == maxi) worst.insert(j);
        }
        cout << endl;
        
        printf("Worst Roots :");
        for(set<int>::iterator it = worst.begin(); it != worst.end(); it++)
            printf(" %d",*it+1);
        cout << endl;
    }
}
