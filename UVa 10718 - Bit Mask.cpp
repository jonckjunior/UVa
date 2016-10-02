#include <iostream>
#include <cstdio>
#include <vector>
#define bit(i) (1LL<<i)
using namespace std;
int main() {
	long long int n,l,u;
	while(cin >> n >> l >> u){
		long long int  res = 0, aux,aux2;
		for(int i = 31; i >= 0; i--){
			if((bit(i)&n)){
				aux = bit(i)-1;
				aux |= res;
				if( aux < l )
					res |= bit(i);
			}
			else{
				aux = bit(i);
				aux |= res;
				if( aux <= u)
					res = aux;
			}
		}
		cout << res << endl;
	}
	return 0;
}
