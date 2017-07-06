#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,r,caso=0;
	while(cin >> r >> n, n + r != 0){
		if(n >= r)
			printf("Case %d: 0\n",++caso);
		else{
			int res = 0, flag = -1;
			for(int i = 1; i <= 26 && flag == -1; i++){
				res = n * i + n;
				if(res >= r) flag = i;
			}
			if(flag != -1) printf("Case %d: %d\n",++caso,flag);
			else 		   printf("Case %d: impossible\n",++caso);
			}
	}
}
