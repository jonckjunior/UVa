#include <bits/stdc++.h>
using namespace std;
#define bit(i) (1<<(i))

int adj[25][25], aux[25], tempo[25], n, maxnodo, maxtempo=420, found, res;
void solve(int u, int mask, int w, int nodos){
	res = max(res, nodos);
	if(nodos == maxnodo){found=true;return;}
	if(w == maxtempo) return;
	for(int i = 0; i < n && !found; i++){
		int nw = w + adj[u][i] + tempo[i];
		if(!(bit(i)&mask) && nw <= maxtempo)
			solve(i, mask|bit(i), nw, nodos+1);
	}
}

int main(){
	while(scanf("%d",&n), n!=0){
		for(int i = 0; i < n; i++){
			scanf("%d",&tempo[i]);
			aux[i] = tempo[i];
		}
		maxnodo = 0;
		sort(aux, aux+n);
		int x = 0;
		for(int i = 0; i < n; i++){
			x += aux[i];
			if(x <= maxtempo) maxnodo++;
		}

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&adj[i][j]);

		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		found = false;
		res = 0;
		for(int i = 0; i < n && !found; i++)
			if(tempo[i] <= maxtempo)
				solve(i, bit(i), tempo[i], 1);
		printf("%d\n",res);
	}
	return 0;
}
