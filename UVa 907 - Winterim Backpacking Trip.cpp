#include <bits/stdc++.h>
using namespace std;
int const maxn = 605, maxk = 305;
int n,k, v[maxn], dp[maxn][maxk];

int solve(int pos, int night_left){
	if(night_left < 0) return 1e9;
	if(pos == n) return v[pos];
	int &value = dp[pos][night_left];
	if(value != -1) return value;

	if(night_left == 0){
		int soma = 0;
		for(int i = pos; i <= n; i++) soma += v[i];
		return value = soma;
	}

	value = 1e9;
	int dist = v[pos];
	for(int i = pos + 1; i <= n; i++){
		if(value < dist) continue;
		value = min(value, max(solve(i, night_left-1), dist) );
		dist += v[i];
	}
	return value;
}

int main(){
	while(cin >> n >> k){
		memset(dp, -1, sizeof dp);
		for(int i = 0; i <= n; i++)
			cin >> v[i];

		cout << solve(0, k) << endl;
	}
}
