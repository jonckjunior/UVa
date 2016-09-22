#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

	int n,c;
	int v[6];

void backtrack(){
	bool found = true;
	for(int j = 0;j < n - 1; j++){
		if(v[j] > v[j+1]){
			found=false;
			swap(v[j],v[j+1]);
			backtrack();
			swap(v[j],v[j+1]);
		}
	}
	if(found) c++;
}

int main(){
	int caso = 0;
	while(scanf("%d",&n) && n){
		for(int i =0 ; i < n; i++)
			scanf("%d",&v[i]);
		c = 0;
		for(int i = 0; i < n-1; i++)
			if(v[i] > v[i+1]){
				swap(v[i],v[i+1]);
				backtrack();
				swap(v[i],v[i+1]);
			}
		printf("There are %d swap maps for input data set %d.\n",c,++caso );
	}

	return 0;
}
