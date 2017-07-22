#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define bit(i) (1<<(i))
vector<string> vs;

char bf(int a, char c){
	if( (c/bit(a)) % 2 == 0) return '/';
	else				  return '\\';
}

void solve(){
	int n = 10, m = vs[0].size() + 2;
	for(int i = 1; i < m; i++){
		for(char car = ' '; car <= 'z'; car++){
			int valid = 1;
			for(int j = 1; j <= 8; j++)
				if(bf(j-1,car) != vs[j][i]){
					valid=0;
					break;
				}
			if(valid){
				printf("%c",car);
				break;
			}
		}
	}
}

int main() {
	int t;
	scanf("%d",&t);
	getchar();
	string s;
	while(t--){
		vs.clear();
		for(int i = 0; i < 10; i++){
			getline(cin,s);
			vs.push_back(s);
		}
		solve();
		cout << endl;
		getchar();
	}
    return 0;
}
