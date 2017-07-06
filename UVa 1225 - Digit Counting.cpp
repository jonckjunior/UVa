#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
	cin >> t;
	while(t--){
		cin >> n;
		string aux = "";
		for(int i = 1; i <= n; i++)
			aux += to_string(i);
		int v[10] = {0};
		for(int i = 0; i < aux.size(); i++)
			v[aux[i] - '0']++;
		for(int i = 0; i < 10; i++)
			if(i == 9) cout << v[i] << endl;
			else  	   cout << v[i] << " ";
	}
}
