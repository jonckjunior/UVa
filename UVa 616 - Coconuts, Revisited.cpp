#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n, n >= 0){
		int root = sqrt(n) + 1, flag, res;
		res = -1;
		for(int i = root; i > 0; i--){
			flag = 1;
			int aux = n;
			for(int j = 0; j < i && flag; j++){
				if(aux % i != 1) flag = 0;
				aux = aux - aux / i - 1;
			}
			if(flag && aux % i == 0){
				res = i;
				break;
			}
		}
		if(res == -1) printf("%d coconuts, no solution\n",n);
		else		  printf("%d coconuts, %d people and 1 monkey\n",n,res);
	}
}
