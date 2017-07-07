#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int x,y,c;
	while(scanf("%lld %lld %lld",&x,&y,&c) && x + y + c != 0){
		long long int res = 0;
		int const t = 2;
		if(x&1) c=!c;
		int impar = (y&1);
		for(int i = 0; i+8 <= x ; i++){
			if(!impar){
				if(c) res += (y-8)/2 + 1;
				else  res += (y-8-2)/2+1;
			}
			else{
				if(c) res += (y-8-1)/2 + 1;
				else  res += (y-8-1)/2 + 1;
			}
			c=!c;
		}
		cout << res << endl;
	}
}
