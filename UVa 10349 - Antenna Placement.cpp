#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

typedef vector<int> vi;

vi match, vis, color, left_size;
vector<string> vs;
vector<vi> adj;
int n,m, maxv = 405;

int solve(int s){
	queue<int> q; q.push(s);
	if(color[s] == -1) color[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		//printf("atual %d com cor %d\n",u,color[u]);
		if(color[u] == 1) left_size.push_back(u);
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(color[v] == -1){
				color[v] = color[u] == 1 ? 0 : 1;
				q.push(v);
			}
		}
	}
}	


int Aug(int l){
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int i = 0; i < adj[l].size(); i++){
		int r = adj[l][i];
		if(match[r] == -1 || Aug(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= m || vs[x][y] == 'o') return false;
	else return true;
}

int getNode(int x, int y){
	return x*m+y;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vs.assign(n, string());
		adj.assign(maxv, vi());
		left_size.clear();
		getchar();
		for(int i = 0; i < n; i++) getline(cin, vs[i]);

		int nodos = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			if(vs[i][j] == '*') nodos++;
				for(int k = 0; k < 4; k++){
					int x = i + dx[k], y = j + dy[k];
					if(valid(x,y) && valid(i,j)){
						int node_a = getNode(i,j), node_b = getNode(x,y);
						adj[node_a].push_back(node_b);
					}
				}
		}

		color.assign(maxv, -1);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(vs[i][j] == 'o') continue;
				int u = getNode(i,j);
				if(color[u] != -1) continue;
				solve(u);
			}

		int MCBM = 0;
		match.assign(maxv, -1);

		for(int l = 0; l < left_size.size(); l++){
			vis.assign(maxv,0);
			MCBM += Aug(left_size[l]);
		}
		cout << (nodos - MCBM) << endl;
	}
}
