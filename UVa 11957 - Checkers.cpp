#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n;
char m[105][105];
vector<vi> adj;
vi dp;

int dfs(int u){
	//printf("%d\n",u);
	if(dp[u] != -1) return dp[u];
	int res = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		res = (res + dfs(v))%1000007;
	}
	if(adj[u].size() == 0 && u < n) res = 1;
	return dp[u] = res;
}

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n) return false;
	else 								   return true;
}

int main(){
	int t,x,y,caso=0;
	cin >> t;
	while(t--){
		cin >> n;
		adj.assign(n*n + 5, vi());
		dp.assign(n*n + 5, -1);
		getchar();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%c",&m[i][j]);
				if(m[i][j] == 'W') x = i, y = j;
			}
			getchar();
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int node_a = i*n + j;
				if(valid(i-1,j+1)){
					int node_b;
					if(m[i-1][j+1] == '.'){
						node_b = (i-1)*n + j+1;
						//printf("(%d,%d)-(%d,%d)\n",i,j,i-1,j+1);
						adj[node_a].push_back(node_b);
					}
					else if(valid(i-2,j+2) && m[i-2][j+2] == '.'){
						node_b = (i-2)*n + j+2;
						//printf("(%d,%d)-(%d,%d)\n",i,j,i-2,j+2);
						adj[node_a].push_back(node_b);	
					}
				}
				if(valid(i-1, j-1)){
					int node_b;
					if(m[i-1][j-1] == '.'){
						node_b = (i-1)*n + j-1;
						//printf("(%d,%d)-(%d,%d)\n",i,j,i-1,j-1);
						adj[node_a].push_back(node_b);	
					}
					else if(valid(i-2,j-2) && m[i-2][j-2] == '.'){
						node_b = (i-2)*n + j-2;
						//printf("(%d,%d)-(%d,%d)\n",i,j,i-2,j-2);
						adj[node_a].push_back(node_b);
					}
				}
			}
		}

		int st = x*n + y;
		//printf("%d %d = %d\n",x,y,st);
		printf("Case %d: %d\n",++caso, dfs(st));
	}
}
