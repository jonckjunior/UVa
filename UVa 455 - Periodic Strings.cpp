#include <bits/stdc++.h>

using namespace std;

int b[1000005];

void preprocess(string p){
	int i = 0, j = -1, len = p.size();
	b[0] = -1;
	while(i < len){
		while(j >= 0 && p[i] != p[j]) j = b[j];
		i++;j++;
		b[i] = j;
	}
}

int solve(string p, string t){
	preprocess(p);
	int i = 0, j = 0, n = t.size(), m = p.size(), c = 0;
	while(i < n){
		while(j >= 0 && t[i] != p[j]) j = b[j];
		i++;j++;
		if(j == m) c++, j=b[j];
	}
	return c;
}

int main(){
	string s;
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		string ss = s + s;
		int res = solve(s,ss) - 1, len = s.size();
		cout << len/res << endl;
		if(t) cout << endl;
	}
}
