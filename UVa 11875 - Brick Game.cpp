#include <bits/stdc++.h>
using namespace std;

int v[15];

int main(){
	int t,caso=0,n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++) scanf("%d",&v[i]);
		printf("Case %d: %d\n",++caso,v[n/2]);
	}
}
