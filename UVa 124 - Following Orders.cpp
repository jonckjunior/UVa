#include <bits/stdc++.h>

using namespace std;

int can[30], mapa[30][30], used[30];
string line;
char p[30], ch1,ch2;
stringstream ssin;

void dfs(int idx, int n){
	if(idx == n){
		p[idx] = '\0';
		puts(p);
		return;
	}
	//puts(p);
	for(int i = 0; i < 30; i++){
		if(can[i] && !used[i]){
			for(int j = 0; j < 30; j++)
				if(mapa[i][j] && used[j])
					return;
			used[i] = 1;
			p[idx] = i + 'a';
			dfs(idx+1, n);
			used[i] = 0;
		}
	}
}

int main(){
	int first = 0;
    while(getline(cin, line)){
    	if(first)
            puts("");
        first = 1;
    	memset(can, 0, sizeof can);
    	memset(mapa, 0, sizeof mapa);
    	memset(used, 0, sizeof used);
    	ssin.clear();
    	ssin << line;
    	while(ssin >> ch1){
    		can[ch1-'a'] = 1;
    	}
    	int n = 0;
    	for(int i = 0; i < 30; i++)
    		n += can[i];
    	getline(cin, line);
    	ssin.clear();
    	ssin << line;
    	while(ssin >> ch1 >> ch2){
    		mapa[(ch1-'a')][(ch2-'a')] = 1;
    	}
    	dfs(0, n);
    }
    return 0;
}
