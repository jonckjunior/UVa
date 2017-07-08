#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int r = (1 + sqrt(8*n))/2 + 1;
		int m = (r*r-r)/2;
		int r2 = r - 1;
		int m2 = (r2*r2 - r2)/2;
		if(r2&1) printf("TERM %d IS %d/%d\n",n,m-n+1,n-m2);
		else     printf("TERM %d IS %d/%d\n",n,n-m2,m-n+1);
	}	
}
