#include <bits/stdc++.h>
using namespace std;

int v[105];

int main(){
	int t,n,x,caso=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(v,0,sizeof v);
		int flag = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				scanf("%d",&x);
				v[x]++;
				if(v[x] > n) flag = 0;
			}
		if(flag) printf("Case %d: yes\n",++caso);
		else	 printf("Case %d: no\n",++caso);

	}
}
