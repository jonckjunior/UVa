#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
vector<vi> adj;
int const mods = 20437;
int n;
char m[15][15], final;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dp[11][11][27][11*11*27], vis[11][11][27];
vector<ii> p;

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n || m[x][y] == '#') return false;
	else								   				     return true;
}

struct state{
    int x, y, w, food;
    state(){} state(int X, int Y, char F, int W) : x(X), y(Y), food(F), w(W) {}
};

ii solve(int sx, int sy){	
	queue<state> q; q.push(state(sx,sy,0,0));
	memset(vis, 0, sizeof vis);
	memset(dp, 0, sizeof dp);
	dp[sx][sy][0][0] = 1;
	while(!q.empty()){
		state front = q.front(); q.pop();
		int x = front.x, y = front.y, w = front.w, food = front.food;
		if(vis[x][y][food]) continue;
		vis[x][y][food] = 1;
		if(m[x][y] == final) return ii(w, dp[x][y][food][w]);
		int &value = dp[x][y][food][w];
		char last = food;
		if(m[x][y] == last + 'A') m[x][y] = '.', last++;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(valid(nx,ny)){
				if(m[nx][ny] == '.'){
					dp[nx][ny][food][w+1] = (dp[nx][ny][food][w+1] + value)%mods;
					q.push(state(nx,ny,food,w+1));
				}
				else if(m[nx][ny] - (food + 'A') == 1){
					dp[nx][ny][food+1][w+1] = (dp[nx][ny][food+1][w+1] + value)%mods;
					q.push(state(nx,ny,food+1,w+1));	
				}

			}
		}
	}
	return ii(-1,-1);
}

int main(){
	int caso = 0, x, y, destx, desty;
	while(cin >> n && n != 0){
		getchar();
		adj.assign(n*n + 5, vi());
		final = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> m[i][j];
				if(m[i][j] == 'A') x = i, y = j;
				if(isalpha(m[i][j]) && m[i][j] > final) final = m[i][j];
			}
			getchar();
		}

		ii res = solve(x,y);
		if(res.first == -1)
			printf("Case %d: Impossible\n", ++caso);
		else
			printf("Case %d: %d %d\n", ++caso, res.first, res.second);
	}
}
