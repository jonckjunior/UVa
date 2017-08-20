#include <bits/stdc++.h>

using namespace std;

int n,res;
vector<string> vs, words;
string s;

bool func(const string &a, const string &b){
	return (int)a.size() < (int)b.size();
}

bool valid(int x, int y){
	if(x >= 0 && x < 4 && y >= 0 && y < 4) return true;
	else return false;
}

int ponto(int p){
	if(p <= 4) return 1;
	if(p == 5) return 2;
	if(p == 6) return 3;
	if(p == 7) return 5;
	if(p >= 8)return 11;
	return 0;
}

bool solve(int x, int y, int p){
	if(p+1 == (int)s.size()) return true;
	char c = '!';
	swap(vs[x][y],c);
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++){
			int xx = x + i, yy = y + j;
			if(valid(xx,yy) && vs[xx][yy] == s[p+1] && solve(xx,yy,p+1)){
				swap(vs[x][y],c);
				return true;
			}
		}
	swap(vs[x][y],c);
	return false;
}

int main(){
	int t,q,caso=0;
	cin >> t;
	while(t--){
		vs.clear();
		words.clear();
		for(int i = 0; i < 4; i++)
			cin >> s, vs.push_back(s);
		cin >> q;
		for(int i = 0; i < q; i++)
			cin >> s, words.push_back(s);
		//sort(words.rbegin(), words.rend(), func);
		res = 0;
		for(int i = 0; i < q; i++){
			s = words[i];
			bool found = false;
			for(int j = 0; j < 4 && !found; j++)
				for(int k = 0; k < 4 && !found; k++)
					if(vs[j][k] == s[0] && solve(j,k,0))
						res += ponto(s.size()), found = true;
		}
		printf("Score for Boggle game #%d: %d\n",++caso,res);
	}
}
