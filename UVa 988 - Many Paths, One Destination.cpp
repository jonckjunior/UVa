#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;
vector<vi> adj;
vi dp;

int dfs(int u){
	int res = 0;
	if(dp[u] != -1) return dp[u];
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		res += dfs(v);
	}
	if(adj[u].size() == 0) res = 1;
	return dp[u] = res;
}

int main(){
	int x,y,t=0;
	while(cin >> n){
		if(t) cout << endl;
		adj.assign(n+5, vi());
		dp.assign(n+5, -1);
		for(int i = 0; i < n; i++){
			cin >> x;
			for(int j = 0; j < x; j++){
				cin >> y;
				adj[i].push_back(y);
			}
		}
		int res = dfs(0);
		cout << res << endl;
		t++;
	}

}
