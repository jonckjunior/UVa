#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,double> id;
typedef vector<id> vid;

struct state{
	int next;
	ii players;
	state(){players = ii(-1,-1); next = -1;}
};

int n;
double mm[305][305];
int mark[605];
vector<state> adj;
void solveChance(vid v1, vid v2, vid &ret){
	for(int i = 0; i < (int) v1.size(); i++){
		int p1 = v1[i].first;
		double chance_p1 = v1[i].second;
		double aux = 0;
		for(int j = 0; j < (int) v2.size(); j++){
			int p2 = v2[j].first;
			double chance_p2 = v2[j].second;
			aux += mm[p1][p2] * chance_p2;
		}
		aux *= chance_p1;
		ret.push_back(id(p1,aux));
	}
}

vid solve(int u){
	vid ret;
	if(u < n){
		ret.push_back(id(u,1.0));
		return ret;
	}
	vid left = solve(adj[u].players.first);
	vid right = solve(adj[u].players.second);
	solveChance(left,right,ret);
	solveChance(right,left,ret);
	return ret;
}

int main(){
	int x, y;
	while(scanf("%d",&n), n!=0){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%lf",&mm[i][j]);
		adj.assign(2*n + 5, state());
		for(int i = 0; i < n-1; i++){
			int nodo = n+i;
			scanf("%d %d",&x,&y);
			x--;y--;
			adj[x].next = adj[y].next = nodo;
			adj[nodo].players = ii(x,y);
		}
		vid ans;
		for(int i = 0; i < n-1; i++)
			if(adj[n+i].next == -1){
				ans = solve(n+i);
				break;
			}
		for(int i = 0; i < (int)ans.size(); i++)
			if(ans[i].first == 0){
				printf("%.6f\n",ans[i].second);
				break;
			}
	}
	return 0;
}
