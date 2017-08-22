#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


int b[100005];

void preprocess(string s){
	int i = 0, j = -1, m = s.size();
	b[0] = -1;
	while(i < m){
		while(j >= 0 && s[i] != s[j]) j = b[j];
		i++;j++;
		b[i]=j;
	}
}

int solve(string s, string p){
	int i = 0, j = 0, n = s.size(), m = p.size(), res = 0;
	while(i < n){
		while(j >= 0 && s[i] != p[j]) j = b[j];
		i++;j++;
		res = j;
		if(j==m) j=b[j];
	}
	return res;
}

int main(){
	string s;
	while(cin >> s){
		string rev(s.rbegin(), s.rend());
		preprocess(rev);
		int res = solve(s,rev);
		printf("%s",s.c_str());
		for(int i = res; i < (int)rev.size(); i++)
			printf("%c",rev[i]);
		puts("");
	}
	return 0;
}
