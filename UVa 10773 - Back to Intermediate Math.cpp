#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,d,u,v,flag,caso=0;
	double t1,t2;
	cin >> t;
	while(t--){
		cin >> d >> v >> u;
		flag = 1;
		t1 = t2 = 0;
		if(v >= u || v == 0) flag = 0;
		else{
			t1 = d/(double)u;
			t2 = d/sqrt(pow(u,2) - pow(v,2));
		}
		if(flag) printf("Case %d: %.3lf\n",++caso,abs(t1-t2));
		else     printf("Case %d: can't determine\n",++caso);
		
	}
}
