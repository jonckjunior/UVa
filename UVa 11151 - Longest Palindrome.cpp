#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int dp[1005][1005], n;
string s;
int solve(int i, int j){
	if(i == j) return 1;
	if(i+1==j) return (s[i] == s[j] ? 2 : 1);
	// if(i+1==j && s[i] == s[j]) return 2;
	int &v = dp[i][j];
	if(v != -1) return v;
	if(s[i] == s[j]) return v = 2 + solve(i+1,j-1);
	else return v = max(solve(i,j-1), solve(i+1,j));
	// return v = max(solve(i,j-1), solve(i+1,j));
}

int main(){
	int t;
	cin >> t;
	getchar();
	while(t--){
		getline(cin, s);
		n = s.size();
		memset(dp, -1, sizeof dp);
		int res = solve(0,n-1);
		cout << res << endl;
	}
}
