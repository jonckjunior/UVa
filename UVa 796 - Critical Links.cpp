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
vi dfs_low, dfs_num, dfs_parent;
vii articulation;
int dfsNum, dfsRoot, rootChildren;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfsNum++;
    for(int i = 0; i < AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;
            dfs(v);
            if(dfs_low[v] > dfs_num[u]){
                articulation.push_back(ii( min(u,v),max(u,v) ));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    int n,u,z,v;
    string s;
    while(cin >> n){
        AdjList.assign(n+1,vi());
        for(int i = 0; i < n; i++){
            scanf("%d (%d)",&u,&v);
            for(int i = 0; i < v; i++){
                scanf("%d",&z);
                AdjList[u].push_back(z);
            }
        }
        dfs_num.assign(n+1,UNVISITED);
        dfs_low.assign(n+1,0);
        dfs_parent.assign(n+1,0);
        dfsNum = 0;
        for(int i = 1; i <= n; i++){
            if(dfs_num[i] == UNVISITED){
                dfsRoot = i;
                rootChildren = 0;
                dfs(i);
            }
        }    
        sort(articulation.begin(), articulation.end());
        printf("%d critical links\n",(int)articulation.size() );
        for(int i = 0; i < articulation.size(); i++)
            printf("%d - %d\n",articulation[i].first, articulation[i].second);
        articulation.clear();
        cout << endl;
    }
}
 
