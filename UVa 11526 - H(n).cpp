#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,sinal;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n < 0) {printf("0\n");continue;}
		int root = sqrt(n);
		long long int res = 0;
		for(int i = 1; i <= root; i++){
			long long int lower = n/(i+1), higher = n/i;
			res += n/i;
			if(higher != i) res += (higher-lower)*i;
		}
		printf("%lld\n",res);
	}
}
