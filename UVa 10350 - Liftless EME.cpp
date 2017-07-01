#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int const maxv = 125, maxe = 20;
int n,m;
vector<vii> adj;
vi dp;

int dfs2(int u){
	if(dp[u] != -1) return dp[u];
	int m = 0;
	if(!adj[u].empty()){
		m = 1e9;
		for(int i = 0; i < adj[u].size(); i++){
			m = min(m, adj[u][i].second + dfs2(adj[u][i].first));
		}
	}
	return dp[u] = m;
}

int main(){
	string entrada;
	while(cin >> entrada >> n >> m){
		int x,y;
		dp.assign(maxe*maxv, -1);
		adj.assign(maxe*maxv, vii());
		for(int i = 0; i < n-1; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < m; k++){
					cin >> x;
					int node_a = i*m + j, node_b = (i+1)*m + k;
					adj[node_a].push_back(ii(node_b,x+2));
				}
			}
		}
		int res = 1e9;
		for(int i = 0; i < m; i++)
			res = min(res, dfs2(i));

		cout << entrada << endl;
		cout << res << endl;
	}
}
