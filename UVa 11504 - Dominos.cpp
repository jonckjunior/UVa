#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vi> g;
vi p(100000);
vii grau(100000);

int findPai(int a){
	int i = a;
	while(p[i] != i){
		p[i] = p[p[i]];
		i = p[i];
	}
	return i;
}

void unionSet(int a, int b){
	p[b] = findPai(a);
}

bool func(const ii &a,const ii &b){
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
		return (a.second < b.second);
	else return false;
}

int main(){
	int t,n,m,x,y;
	cin >> t;
	while(t--){
		cin >> n >> m;

		for(int i = 0; i < n; i++){
			grau[i] = ii(0,i);
			p[i] = i;
		}
		g.assign(n, vi());
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			x--;y--;
			grau[x] = ii(grau[x].first+1, grau[x].second);
			g[x].push_back(y);
		}
		sort(grau.begin(), grau.begin() + n, func);
		for(int i = 0; i < n; i++){
			int u = grau[i].second;
			for(int j = 0; j < g[u].size(); j++){
				int v = g[u][j];
				unionSet(u,v);
			}
		}
		int contador = 0;
		for(int i = 0; i < n; i++){
			if(i == findPai(i))
				contador++;
		}
		cout << contador << endl;
	}

	return 0;
}
