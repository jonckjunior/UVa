#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
typedef vector<int> vi;

vi match, vis, color, left_size;
vector<string> vs;
vector<vi> adj;
int n,m;

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

int main(){
	int t, caso = 0;
	cin >> t;
	while(t--){
		int MCBM = 0, x;
		cin >> n >> m;
		adj.assign(n+m+2, vi());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				scanf("%d",&x);
				if(x == 0) continue;
				adj[i].push_back(n+j);
				adj[n+j].push_back(i);
			}

		match.assign(n+m+2, -1);
		for(int l = 0; l < n; l++){
			vis.assign(n,0);
			MCBM += Aug(l);
		}

		printf("Case %d: ",++caso);
		printf("a maximum of %d nuts and bolts ",MCBM);
		printf("can be fitted together\n");

	}
}
