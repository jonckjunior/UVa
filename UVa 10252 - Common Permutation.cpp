#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b;
	while(getline(cin,a), getline(cin,b)){
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int t = min(a.size(), b.size());
		string res = "";
		for(int i = 0; i < a.size(); i++)
			for(int j = 0; j < b.size(); j++)
				if(a[i] == b[j]){
					res += b[j];
					b.erase(b.begin()+j);
					break;
				}
		cout << res << endl;
	}
	return 0;
}
