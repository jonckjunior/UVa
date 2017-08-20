#include <bits/stdc++.h>

using namespace std;

int n,m;
char mm[55][55];
string s;

bool valid(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

bool solve(int x, int y, int p, int dx, int dy){
	//printf("%d %d %d %d %d\n",x,y,p,dx,dy);
	if(p == (int)s.size()) return true;
	if(!valid(x,y)) return false;
	if(mm[x][y] != s[p]) return false;
	return solve(x+dx,y+dy,p+1,dx,dy);
}

int main(){
	int t,q;
	cin >> t;
	char c;
	while(t--){
		cin >> n >> m;
		getchar();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%c",&c);
				mm[i][j] = tolower(c);
			}
			getchar();
		}
		cin >> q;
		for(int i = 0; i < q; i++){
			cin >> s;
			for(int j = 0; j < (int)s.size(); j++) s[j] = tolower(s[j]);
			int x=-1,y=-1,found=0;
			for(int j = 0; j < n && !found; j++)
				for(int k = 0; k < m && !found; k++)
					if(mm[j][k] == s[0]){
						found |= solve(j,k,0,0,1);
						found |= solve(j,k,0,1,0);
						found |= solve(j,k,0,1,1);
						found |= solve(j,k,0,0,-1);
						found |= solve(j,k,0,-1,0);
						found |= solve(j,k,0,-1,-1);
						found |= solve(j,k,0,1,-1);
						found |= solve(j,k,0,-1,1);
						x = j, y = k;
					}
			printf("%d %d\n",x+1,y+1);
		}
		if(t) cout << endl;
	}
}
