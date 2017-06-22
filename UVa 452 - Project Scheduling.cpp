#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> AdjList;
vi dfs_num, ts, p, dp;
int const maxv = 50;
int n_nodos;

void dfs2(int u) {
	dfs_num[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == 0)
			dfs2(v);
	}
	ts.push_back(u);
}

int solve(int u){
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dp[v] == -1) dp[v] = dp[u] + p[v];
		else dp[v] = max(dp[u] + p[v], dp[v]);
	}
}

int main(){
	int t;
	cin >> t;
	string entrada;
	getline(cin, entrada);
	getline(cin, entrada);
	while(t--){

		AdjList.assign(maxv, vi());
		dfs_num.assign(maxv, 0);
		ts.clear();
		p.assign(maxv, 0);
		dp.assign(maxv, -1);
		n_nodos = 0;

		while(getline(cin,entrada) && entrada.size() > 0){
			n_nodos++;
			//cout << entrada << endl;
			istringstream iss(entrada);
			string nodo_a, vizinhos_a;
			int x,w;
			iss >> nodo_a;
			iss >> w;
			if(iss.good())
				iss >> vizinhos_a;
			x = nodo_a[0]-'A';
			p[x] = w;
			for(int i = 0; i < vizinhos_a.size(); i++){
				int y = vizinhos_a[i]-'A';
				AdjList[y].push_back(x);
			}
		}
		for(int i = 0; i < n_nodos; i++)
			if(dfs_num[i] == 0)
				dfs2(i);

		reverse(ts.begin(), ts.end());


		int res = -1;

		for(int i = 0; i < ts.size(); i++){
			int nodo = ts[i];
			if(dp[nodo] == -1) dp[nodo] = p[nodo];
			solve(nodo);
			res = max(res, dp[nodo]);
		}
		cout << res << endl;
		if(t) cout << endl;
	}
}
