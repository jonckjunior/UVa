#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
#define UNVISITED -1
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num, dfs_low, visited, S;
vector<string> vs;
int dfsNumber;

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfsNumber++;
    S.push_back(u); 
    visited[u] = 1;
    for(int i = 0; i < AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == UNVISITED)
            dfs(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        while(true){
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if(u == v) printf("%s",vs[v-1].c_str());
            else       printf("%s, ",vs[v-1].c_str());
            if(u == v) break;
        }
        printf("\n");
    }
}

int main(){
    int v,e,caso = 0, espaco = 0;
    while(cin >> v >> e && v+e != 0){
        if(espaco) cout << endl;
        vs.clear();
        AdjList.assign(v+1, vi());
        map<string,int> m;
        string pa, pb;
        int k = 0;
        for(int i = 0; i < e; i++){
            cin >> pa >> pb;
            int u = m[pa], w = m[pb];
            if(u == 0) vs.push_back(pa),u = m[pa] = ++k;
            if(w == 0) vs.push_back(pb),w = m[pb] = ++k;
            AdjList[u].push_back(w);
        }
        dfs_num.assign(v+1, UNVISITED);
        dfs_low.assign(v+1, 0);
        visited.assign(v+1, 0);
        dfsNumber = 0;
        S.clear();
        printf("Calling circles for data set %d:\n",++caso);
        for(int i = 1; i <= v; i++)
            if(dfs_num[i] == UNVISITED)
                dfs(i);
        espaco = 1;
    }
  
}
 
