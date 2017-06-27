#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> AdjList;
vi dfs_num, ts,dp;
int const maxv = 105;
int n,m,g[maxv][maxv];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void dfs2(int u) {	
	dfs_num[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == 0)
			dfs2(v);
	}
	ts.push_back(u);
}

void solve(int u){
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dp[v] == -1) dp[v] = dp[u] + 1;
		else dp[v] = max(dp[u] + 1, dp[v]);
	}
}

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	else								   return true;
}


int main(){
	int t;
	string nome;
	cin >> t;
	while(t--){
		cin >> nome >> n >> m;

		memset(g, 0, sizeof g);
		dp.assign(n*m+2, -1);
		AdjList.assign(n*m+2, vi());
		ts.clear();

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> g[i][j];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				for(int k = 0; k < 4; k++){
					int x = i, y = j;
					int xi = x + dx[k], yi = y + dy[k];
					if(valid(xi,yi) && g[x][y] > g[xi][yi]){
						int node_a = x * m + y, node_b = xi * m + yi;
						AdjList[node_a].push_back(node_b);
					}
				}
		dfs_num.assign(n*m+2, 0);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int u = i * m + j;
				if(dfs_num[u] == 0){
					dfs2(u);
				}
			}
		}
		reverse(ts.begin(), ts.end());
		int res = -1;
		for(int i = 0; i < ts.size(); i++){
			int u = ts[i];
			solve(u);
			res = max(res, dp[u]);
		}
		cout << nome << ": " << res + 2 << endl;
	}
}
