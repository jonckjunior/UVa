#include <bits/stdc++.h>

using namespace std;

int n,xf,yf;
char mm[105][105];
string s;

bool valid(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < n) return true;
	else return false;
}

bool solve(int x, int y, int p, int dx, int dy){
	if(p == (int)s.size()) {xf = x - dx; yf = y - dy; return true;}
	if(!valid(x,y)) return false;
	if(mm[x][y] != s[p]) return false;
	return solve(x+dx,y+dy,p+1,dx,dy);
}

int main(){
	int t,q;
	char c;
	cin >> n;
	getchar();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			scanf("%c",&mm[i][j]);
		getchar();
	}
	while(cin >> s, s != "0"){
		int x=-1,y=-1,found=0;
		for(int j = 0; j < n && !found; j++)
			for(int k = 0; k < n && !found; k++)
				if(mm[j][k] == s[0]){
					found |= solve(j,k,0,0,1);
					found |= solve(j,k,0,1,0);
					found |= solve(j,k,0,1,1);
					found |= solve(j,k,0,0,-1);
					found |= solve(j,k,0,-1,-1);
					found |= solve(j,k,0,1,-1);
					found |= solve(j,k,0,-1,1);
					x = j, y = k;
				}
		if(found)
			printf("%d,%d %d,%d\n",x+1,y+1,xf+1,yf+1);
		else
			printf("Not found\n");
	}
	if(t) cout << endl;
}
