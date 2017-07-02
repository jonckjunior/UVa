#include <bits/stdc++.h>
using namespace std;
int const maxn = 80, maxk = 10;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int n,k, m[maxn][maxn], dp[maxn][maxn][maxk][5], dest, flag;
vector<vii> adj;

int dx[] = {1,0,0};
int dy[] = {0,1,-1};

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n) return false;
	else return true;
}

int solve(int x, int y, int t, int dir){
	if(t < 0) return -1e9;
	if(x == n-1 && y == n-1) {flag = 1;return 0;}
	
	int &value = dp[x][y][t][dir];
	if(value != -1) return value;
	value = -1e9;

	if(valid(x+1,y)) value = max(value, solve(x+1,y,t-(m[x+1][y] < 0),0) + m[x+1][y]);
	if(valid(x, y-1) && dir != 2) value = max(value, solve(x, y-1, t-(m[x][y-1] < 0), 1) + m[x][y-1]);
	if(valid(x, y+1) && dir != 1) value = max(value, solve(x, y+1, t-(m[x][y+1] < 0), 2) + m[x][y+1]);
	return value;
}

int main(){
	int caso = 0;
	while(cin >> n >> k, n+k != 0){
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&m[i][j]);
		flag = 0;
		int res = solve(0,0,k - (m[0][0] < 0),0) + m[0][0];
		if(!flag) printf("Case %d: impossible\n",++caso);
		else		    printf("Case %d: %d\n", ++caso,res);
	}
}
