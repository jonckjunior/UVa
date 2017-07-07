#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,t,caso=0,res;
	cin >> t;
	while(t--){
		cin >> a >> b;
		res = 0;
		for(int i = a; i <= b; i++) if(i&1) res += i;
		printf("Case %d: %d\n",++caso,res);
	}
}
