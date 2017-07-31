#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,caso=0;
    string s;
    cin >> t;
    while(t--){
    	cin >> s;
    	printf("Case #%d:\n",++caso);
    	char res[105][105] = {};
    	int x=50, maxy=50, miny=50;
    	for(int i = 0; i < s.size(); i++){
    		if(s[i] == 'C')
    			res[x][i] = '_';
    		else if(s[i] == 'R'){
    			if(i!=0 && s[i-1] == 'R') x++;
    			res[x][i] = '/';
    			if(i+1 <= s.size()-1 && s[i+1] == 'C') x++;
    		}
    		else{
    			if(i!=0 && s[i-1] != 'R') x--;
    			res[x][i] = '\\';
    		}
    		if(x > maxy) maxy = x;
    		if(x < miny) miny = x;
    	}
 		int y;
    	for(int i = maxy; i >= miny; i--){
    		printf("|");
    		y = 50;
    		printf(" ");
    		while(!res[i][y]) y--;
    		for(int k = 0; k <= y; k++)
                printf("%c", !res[i][k] ? ' ' : res[i][k]);
            printf("\n");
    	}
    	printf("+");
    	for(int i = 0; i <= s.size() + 1; i++)
    		printf("-");
    	printf("\n\n");
    }
}
