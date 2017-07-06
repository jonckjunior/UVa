#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	while(cin >> n >> k){
		int res = n;
		while(n >= k){
			int aux = n/k;
			res+= aux;
			n = n%k + aux;
		}
		cout << res << endl;
	}
}
