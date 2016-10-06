#include <iostream>
#include <vector>
#include <cstdio>
#define NOTVALID -1e7
using namespace std;

long long int grid[105][105];

int main(){
	int t,n,q,x1,x2,y1,y2;
	cin >> t;
	while(t--){
		cin >> n >> q;
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) grid[i][j] = 1;
		for(int i = 0 ; i < q; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;y1--;x2--;y2--;
			for(int j = x1; j <= x2; j++)
				for(int k = y1; k <= y2; k++)
					grid[j][k] = NOTVALID;
		}
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(grid[i][j] == NOTVALID) cout << "# ";
	            else cout <<"1 ";
	        }
	        cout << endl;
	    }
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i > 0) grid[i][j]+=grid[i-1][j];
        long long int maxRect = 0, subRect;
        for(int l = 0; l < n; l++)
            for(int i = l; i < n; i++){
                subRect = 0;
                for(int j = 0; j < n; j++){
                    subRect+=grid[i][j];
                    if(l > 0) subRect -= grid[l-1][j];
                    if(subRect < 0) subRect = 0;
                    else maxRect = max(maxRect, subRect);
                }
            }
        cout << maxRect << endl;

	}

	return 0;
}
