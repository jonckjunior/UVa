#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int const maxn = 1e6;
int n, vline[105][105], vcol[105][105];
vector<string> vs;
vector<vi> adj;
vi match, vis;

int Aug(int l){
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int i = 0; i < (int)adj[l].size(); i++){
		int r = adj[l][i];
		if(match[r] == -1 || Aug(match[r])){
			match[r] = l; return 1;
		}
	}
	return 0;
}

int main(){
	string s;
	ios::sync_with_stdio(false);
	while(cin >> n){
		vs.clear();
		for(int i = 0; i < n; i++)
			cin >> s, vs.push_back(s);
		int line = 0, col = 0;
		for(int i = 0; i < n; i++){ // lines
			for(int j = 0; j < n; j++){
				if(vs[i][j] == 'X')
					line++;
				else
					vline[i][j] = line;
			}
			line++;
		}
		for(int i = 0; i < n; i++){ // col
			for(int j = 0; j < n; j++){
				if(vs[j][i] == 'X')
					col++;
				else
					vcol[j][i] = col;
			}
			col++;
		}
		adj.assign(line+col+50, vi());
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(vs[i][j] == 'X') continue;
				int u = vline[i][j], v = vcol[i][j] + line + 1;
				adj[u].push_back(v);
			}
		}
		int MCBM = 0;
		match.assign(line+col+50, -1);
		for(int l = 0; l <= line; l++){
			vis.assign(line+5, 0);
			MCBM += Aug(l);
		}

		cout << MCBM << endl;
	}
}
