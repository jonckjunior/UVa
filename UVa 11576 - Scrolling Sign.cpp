#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<string> vs;

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
	int t,k,n;
	string s, last;
	cin >> t;
	while(t--){
		vs.clear();
		cin >> k >> n;
		last = "me ajuda";
		for(int i = 0; i < n; i++){
			cin >> s;
			if(s != last) vs.push_back(s);
			last = s;
		}
		int res = 0;
		n = vs.size();
		for(int i = n-1; i > 0; i--){
			string patt = vs[i];
			string text = vs[i-1];
			preprocess(patt);
			res += solve(text,patt);
		}
		cout << n*k-res << endl;
	}
	return 0;
}
