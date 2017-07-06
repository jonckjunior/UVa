#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	printf("PERFECTION OUTPUT\n");
	while(cin >> n, n != 0){
		int res = 0;
		for(int i = 1; i < n; i++)
			if(n % i == 0) res += i;
		if(res > n)
			printf("%5d  ABUNDANT\n",n);
		else if(res < n)
			printf("%5d  DEFICIENT\n",n);
		else
			printf("%5d  PERFECT\n",n);
	}
	printf("END OF OUTPUT\n");
}
