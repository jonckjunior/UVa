#include <bits/stdc++.h>
using namespace std;
double const pi = acos(-1);
int main(){
	int n;
	while(cin >> n && n != -1){
		int root = sqrt(2*n) + 1;
		int flag = 0, st, fn;
		for(int i = root; i >= 1 && !flag; i--){
			int r = i;
			int a = (2*n - r*r + r)/(2*r);
			if(n*2 == r*(2*a + r-1)) flag = 1, st = a, fn = st + i;
		}
		if(st == 0) st = 1;
		if(flag)
			printf("%d = %d + ... + %d\n",n,st,fn-1);
		else
			printf("%d = %d + ... + %d\n",n,n,n);
	}
}
