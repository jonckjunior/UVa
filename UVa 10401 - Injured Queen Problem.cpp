#include <bits/stdc++.h>
using namespace std;

int n;
long long int m[20], origin[20], dp[20][20];

long long int solve(int x, int y){
	//printf("(%d,%d)\n",x,y);
	if(y == (n-1)) return 1;
	if(dp[x][y] != -1) return dp[x][y];

	long long int res = 0;
	if(m[y+1] != -1){
		if(abs(m[y+1]-x) > 1)
			res = solve(m[y+1], y+1);
	}
	else{
		for(int i = 0; i < n; i++)
			if(abs(i-x) > 1)
				res += solve(i, y+1);
	}
	return dp[x][y] = res;
}

int main(){
	string entrada;
	while(cin >> entrada){
		n = entrada.size();
		memset(m, -1, sizeof m);
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < n; i++){
			char c = entrada[i];
			if(c == '?') continue;
			if(isdigit(c)) m[i] = c - '0' - 1;
			else m[i] = c - 'A' - 1 + 10;
		}
		long long int res = 0;
		if(m[0] != -1) res = solve(m[0], 0);
		else{
			for(int i = 0; i < n; i++)
				res += solve(i, 0);
		}

		cout << res << endl;
	}
}
