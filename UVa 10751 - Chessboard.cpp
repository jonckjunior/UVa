#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n == 1) cout << "0.000" << endl;
		else if(n == 2) cout << "4.000" << endl;
		else{
			int aux = n-2;
			double res = (aux-1)*(aux) + aux;
			res = res*sqrt(2) + n*n - res;
			printf("%.3lf\n",res);
		}
		if(t) cout << endl;
	}
}
