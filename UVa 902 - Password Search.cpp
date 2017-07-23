#include <bits/stdc++.h>
#include <iterator>
using namespace std;

map<string,int> mm;

int main() {
	int n;
	string p;
	while(cin >> n >> p){
		mm.clear();
		string res;
		int maxi = -1e9;
		for(int i = 0; i <= p.size() - n; i++){
			int &value = mm[p.substr(i, n)];
			value++;
			if(value > maxi) maxi = value, res = p.substr(i, n);
		}
		cout << res << endl;
	}
	return 0;
}
