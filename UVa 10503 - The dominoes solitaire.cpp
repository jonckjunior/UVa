#include <iostream>
#include <vector>
#include <cstdio>
#define bit(a) (1<<a)
using namespace std;
typedef pair<int,int> ii;

int n,m;
ii inicio,fim;
vector<ii> pares;
bool found;

void backtrack(int u, int p, int mark){
	if(p == n && (u == fim.first) ){
		found = true;
		return;
	}
	for(int i = 0; i < pares.size(); i++){
		if(!(bit(i)&mark) && u == pares[i].first)
			backtrack(pares[i].second, p+1, mark|bit(i));
		if(!(bit(i)&mark) && u == pares[i].second)
			backtrack(pares[i].first, p+1, mark|bit(i));
	}	
}


int main(){
	int x,y;
	while(scanf("%d",&n) && n && scanf("%d",&m)){
		scanf("%d %d",&x,&y);
		inicio = ii(x,y);
		scanf("%d %d",&x,&y);
		fim = ii(x,y);
		for(int i = 0; i < m; i++){
			scanf("%d %d",&x,&y);
			pares.push_back(ii(x,y));
		}
		found = false;
		backtrack(inicio.first, 0, 0);
		if(!found)
			backtrack(inicio.second, 0, 0);
		pares.clear();
		if(found) cout << "YES" << endl;
		else cout<< "NO" << endl;
	}	

	return 0;
}
