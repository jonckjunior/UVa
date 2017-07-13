#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF){
    		double res = 0;
    		int m = max(k,n-k);
    		for(int i = m+1; i <= n; i++){
	    			res += log10(i);
	    			res -= log10(n-i+1);
	    	}
    		int ans = floor(res) + 1;
    		printf("%d\n",ans);
    }
}
