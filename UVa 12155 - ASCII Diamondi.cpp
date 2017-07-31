#include <bits/stdc++.h>

using namespace std;

int n,r1,c1,r2,c2,caso=0;

char printDiamond(int i, int j){
    int dist = abs(i-(n-1)) + abs(j-(n-1));
    return dist >= n ? '.' : ('a' + dist%26);
}

int main(){
    while(cin >> n , n != 0){
        cin >> r1 >> c1 >> r2 >> c2;
        printf("Case %d:\n",++caso);
		for(int i = r1; i <= r2; i++){
		    int x = i%(2*n-1);
			for(int j = c1; j <= c2; j++){
			    int y = j%(2*n-1);
				printf("%c",printDiamond(x,y));
			}
			printf("\n");
		}
    }
    
    return 0;
}
