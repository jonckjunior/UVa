#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define NOTVALID -1e7

int grid[105][105];

int main(){
	int n,m;
	while(cin >> n >> m && n + m != 0){
		int maxRect = NOTVALID, subRect = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				scanf("%d",&grid[i][j]);
				if(grid[i][j] == 1) grid[i][j] = NOTVALID;
				else grid[i][j] = 1;
				maxRect = max(maxRect, subRect);
				if(i > 0) grid[i][j] += grid[i-1][j];
			}
		for(int l = 0; l < n; l++)
			for(int i = l; i < n; i++){
				subRect = 0;
				for(int j = 0; j < m; j++){
					subRect += grid[i][j];
					if(l > 0) subRect -= grid[l-1][j];
					if(subRect < 0) subRect = 0;
					else maxRect = max(maxRect, subRect);
				}
			}
		cout << maxRect << endl;
	}
}
