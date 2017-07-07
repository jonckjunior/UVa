#include <bits/stdc++.h>
using namespace std;

long long int v[1005],n,k,mod;

int fastExp(int base, int p){
	if(p == 0) return 1;
	else if(p == 1) return base;
	else{
		int res = fastExp(base, p/2);
		res = ((res%mod)*(res%mod))%mod;
		if(p%2 == 1) res = ((res%mod)*(base%mod))%mod;
		return res;
	}
}

int main(){
	int t,caso=0;
	cin >> t;
	while(t--){
		scanf("%lld %lld %lld",&n,&k,&mod);
		for(int i = 0; i < n; i++) scanf("%lld",&v[i]);
		long long int res = (fastExp(n,k-1)*k)%mod;
		long long int sum = 0;
		for(int i = 0; i < n; i++)
			sum = (sum + (res*v[i])%mod)%mod;
		printf("Case %d: %lld\n",++caso,sum);
	}
}
