#include <bits/stdc++.h>
using namespace std;
int const max_v = 250;
int degree[max_v], used[max_v];

typedef vector<int> vi;
vector<vi> adj;

void dfs(int u){
	used[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
		if(!used[adj[u][i]]) dfs(adj[u][i]);
}

int main(){
	int n,m,x,y;
	while(cin >> n >> m){
		adj.assign(n+1, vi());
		memset(degree, 0, sizeof degree);
		for(int i = 0; i < n; i++) used[i] = 1;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			degree[x]++;
			degree[y]++;
			adj[x].push_back(y);
			adj[y].push_back(x);
			used[x] = used[y] = 0;
		}
		int possible = 1, conjunto = 0;
		for(int i = 0; i < n && possible; i++){
			if(degree[i]&1) possible = 0;
			if(!used[i]) conjunto++, dfs(i);
		}
		if(possible && conjunto == 1)
			printf("Possible\n");
		else
			printf("Not Possible\n");
	}
}
