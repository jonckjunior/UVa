#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
typedef vector<int> vi;

vi match, vis;
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
		cin >> n;
		vi left_side(n);
		for(int i = 0; i < n; i++) scanf("%d",&left_side[i]);
		cin >> m;
		vi right_side(m);
		for(int i = 0; i < m; i++) scanf("%d",&right_side[i]);
		adj.assign(n+m+2, vi());
		for(int i = 0; i < left_side.size(); i++){
			int esq = left_side[i];
			for(int j = 0; j < right_side.size(); j++){
				int dir = right_side[j];
				if(esq == dir || (esq != 0 && dir % esq == 0) ){
					adj[i].push_back(n+j);
					adj[n+j].push_back(i);
				}
			}
		}

		match.assign(n+m+2, -1);
		for(int l = 0; l < n; l++){
			vis.assign(n,0);
			MCBM += Aug(l);
		}
		printf("Case %d: %d\n",++caso, MCBM);
	}
}
